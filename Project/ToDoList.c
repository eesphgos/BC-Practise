#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <cjson/cJSON.h>

void add_task(const char *title, int n);
void view_tasks(WINDOW *disc, WINDOW *deadline, WINDOW *subtask1, WINDOW *categories);
void mark_task_as_done();
void add_description(const char *descrip);
void del_task(int x);
void edit_task(const char *name, WINDOW *disc, WINDOW *deadline, WINDOW *subtask, WINDOW *categories, int);

void save_tasks_to_json(const char *filename);
void load_tasks_from_json(const char *filename);
void load_categories_from_json(const char *filename);
void load_categories_from_json(const char *filename);

int y, x, ch, chc, chs, task_count = 0, highlight = 0, subhighlite = 0, cathighlite = 0, cat_count = 4;

typedef struct
{
    char type[30];
} categories;

typedef struct
{

    char subtitle[50];
    int subsituation;

} sub_tasks;
typedef struct
{
    int num;
    char title[60];
    int situation;
    char discription[1000];
    int yaer;
    int month;
    int day;
    sub_tasks subtasks[30];
    int num_of_sumtask;
    char catgor[20];

} task;

task tasks[60];
task sort_by_num[60];
task sort_by_a_z[60];
task sort_by_dead[60];

categories cat[20];

int main()
{

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    getmaxyx(stdscr, y, x);

    WINDOW *main = newwin(3 * y / 4, 2 * x / 3, 0, 0);
    refresh();
    box(main, 0, 0);
    wprintw(main, "Tasks");
    wrefresh(main);
    scroll(main);
    keypad(main, true);
    wmove(main, 1, 1);

    WINDOW *description = newwin(2 * y / 4, x / 3, y / 2, 2 * x / 3);

    box(description, 0, 0);
    wprintw(description, "Description");
    wrefresh(description);

    WINDOW *disc = newwin(2 * y / 4 - 2, x / 3 - 2, y / 2 + 1, 2 * x / 3 + 1); // a window that smaller than description and in to the description window

    WINDOW *categories = newwin(2 * y / 4 - 3, x / 3, 3, 2 * x / 3);

    box(categories, 0, 0);
    wprintw(categories, "Categories");

    wrefresh(categories);

    WINDOW *deadline = newwin(3, x / 3, 0, 2 * x / 3);

    box(deadline, 0, 0);
    wprintw(deadline, "Deadline");
    wrefresh(deadline);

    WINDOW *subtask = newwin(y / 4, 2 * x / 3, 3 * y / 4, 0);

    box(subtask, 0, 0);
    wprintw(subtask, "Subtaskes");
    wrefresh(subtask);

    WINDOW *subtask1 = newwin(y / 4 - 2, 2 * x / 3 - 2, 3 * y / 4 + 1, 1);

    // scrollok(main,TRUE);
    // scrollok(disc, TRUE);
    // scrollok(subtask1, TRUE);
    // scrollok(categories,TRUE);

    load_tasks_from_json("proj.json");
    load_categories_from_json("categories.json");

    ch = 's';
    strcpy(cat[0].type, "regular sort");
    strcpy(cat[1].type, "sort by number");
    strcpy(cat[2].type, "sort by a --> z");
    strcpy(cat[3].type, "sort by deadline");

    for (int i = 0; i < 60; i++)
    {
        tasks[i].num_of_sumtask = 0;
    }
    while (ch != 'q')
    {

        load_tasks_from_json("proj.json");
        load_categories_from_json("categories.json");

        wrefresh(main);
        wrefresh(description);
        wrefresh(deadline);
        wrefresh(subtask);
        wrefresh(categories);

        view_tasks(disc, deadline, subtask1, categories);
        mvprintw(3, x / 4, "                                                 ");

        wrefresh(main);

        ch = wgetch(main);
        switch (ch)
        {
        case 'a':

            int cc = getch();
            int ccc = cc - '0';
            char title[50];
            getstr(title);

            add_task(title, cc);
            wrefresh(main);
            break;

        case ' ':
            mark_task_as_done();

            break;

        case 'k':
            highlight++;
            if (highlight + 1 > task_count)
            {
                highlight = 0;
            }
            break;

        case 'j':
            highlight--;
            if (highlight < 0)
            {
                highlight = task_count - 1;
            }
            break;

        case 'r':

            char descrip[999];
            getstr(descrip);
            add_description(descrip);

            break;
        case 'd':

            deleteln();

            redrawwin(main);
            redrawwin(description);
            redrawwin(categories);
            redrawwin(deadline);
            redrawwin(subtask);

            refresh();
            del_task(highlight);
            highlight--;
            if (highlight < 0)
            {
                highlight++;
                mvwprintw(deadline, 1, 1, "               ");
                werase(subtask1);
                redrawwin(subtask);
            }
            task_count--;
            break;

        case 'e':

            int new_num;
            new_num = getchar();
            char new_title[60];
            getstr(new_title);
            edit_task(new_title, disc, deadline, subtask1, categories, new_num);

            redrawwin(main);
            redrawwin(description);
            redrawwin(categories);
            redrawwin(deadline);
            redrawwin(subtask);
            refresh();
            break;

        case 'n':

            int yaer, month, day;
            scanf("%d%d%d", &day, &month, &yaer);

            tasks[highlight].yaer = yaer;
            tasks[highlight].month = month;
            tasks[highlight].day = day;

            if (yaer < 1 || yaer > 9999)
            {
                tasks[highlight].yaer = 0;
                tasks[highlight].month = 0;
                tasks[highlight].day = 0;
            }
            if (month > 12 || month < 1)
            {
                tasks[highlight].yaer = 0;
                tasks[highlight].month = 0;
                tasks[highlight].day = 0;
            }
            if (month < 7 && month > 0 && (day < 1 || day > 31))
            {
                tasks[highlight].yaer = 0;
                tasks[highlight].month = 0;
                tasks[highlight].day = 0;
            }
            if (month < 12 && month > 6 && (day < 1 || day > 30))
            {
                tasks[highlight].yaer = 0;
                tasks[highlight].month = 0;
                tasks[highlight].day = 0;
            }
            if (month == 12 && (day < 1 || day > 29))
            {
                tasks[highlight].yaer = 0;
                tasks[highlight].month = 0;
                tasks[highlight].day = 0;
            }

            if (tasks[highlight].yaer == 0 && tasks[highlight].month == 0 && tasks[highlight].day == 0)
            {
                mvprintw(3, x / 4, "  YOU ENTER AN INCORECT DATE PLEAS ENTER AGAIN...");
                usleep(1000000); // delay
            }
            wrefresh(deadline);

            refresh();
            break;

        case 'l':
            chs = 'l';
            subhighlite = 0;
            int sub_task_count = tasks[highlight].num_of_sumtask;
            while (chs != 'h')
            {

                view_tasks(disc, deadline, subtask1, categories);

                chs = getch();

                switch (chs)
                {
                case 'k':

                    subhighlite++;
                    if (subhighlite == sub_task_count)
                    {
                        subhighlite--;
                    }

                    break;

                case 'j':

                    subhighlite--;
                    if (subhighlite == -1)
                    {
                        subhighlite++;
                    }

                    break;

                case 'a':

                    char new_subtitle[50];
                    getstr(new_subtitle);
                    strcpy(tasks[highlight].subtasks[sub_task_count].subtitle, new_subtitle);
                    tasks[highlight].subtasks[sub_task_count].subsituation = 0;
                    sub_task_count++;

                    break;

                case 'd':

                    deleteln();

                    redrawwin(main);
                    redrawwin(description);
                    redrawwin(categories);
                    redrawwin(deadline);
                    redrawwin(subtask);

                    refresh();

                    for (int i = subhighlite; i < sub_task_count; i++)
                    {

                        tasks[highlight].subtasks[i] = tasks[highlight].subtasks[i + 1];
                    }
                    subhighlite--;
                    if (subhighlite < 0)
                    {
                        subhighlite++;
                        mvwprintw(subtask, 1, 1, "                 ");
                    }
                    sub_task_count--;
                    mvwprintw(subtask, sub_task_count + 1, 1, "                                            ");

                    wrefresh(main);
                    wrefresh(description);
                    wrefresh(deadline);
                    wrefresh(subtask);
                    wrefresh(categories);
                    break;

                case ' ':
                    if (cathighlite == 0)
                    {
                        if (tasks[highlight].subtasks[subhighlite].subsituation == 0)
                        {
                            tasks[highlight].subtasks[subhighlite].subsituation = 1;
                        }
                        else
                            tasks[highlight].subtasks[subhighlite].subsituation = 0;
                    }

                    break;

                default:
                    break;
                }
                tasks[highlight].num_of_sumtask = sub_task_count;
            }

            break;

        case 'c':

            chc = 'z';
            
            while (chc != 'c')
            {

                refresh();

                chc = getch();
                switch (chc)
                {

                case 'k':

                    cathighlite++;
                    if (cathighlite == cat_count)
                    {
                        cathighlite--;
                    }
                    view_tasks(disc, deadline, subtask1, categories);
                    refresh();
                    break;
                case 'j':

                    cathighlite--;
                    if (cathighlite == -1)
                    {
                        cathighlite++;
                    }
                    view_tasks(disc, deadline, subtask1, categories);
                    refresh();
                    break;
                case 'a':

                    char type_of_category[30];
                    getstr(type_of_category);
                    strcpy(cat[cat_count].type, type_of_category);
                    cat_count++;
                    view_tasks(disc, deadline, subtask1, categories);
                    refresh();
                    break;
                case 'd':

                    deleteln();

                    redrawwin(main);
                    redrawwin(description);
                    redrawwin(categories);
                    redrawwin(deadline);
                    redrawwin(subtask);
                    refresh();

                    for (int i = cathighlite; i < cat_count; i++)
                    {

                        cat[cathighlite] = cat[cathighlite + 1];
                    }
                    cathighlite--;
                    if (cathighlite < 0)
                    {
                        cathighlite++;
                        mvwprintw(categories, 3, 1, "                 ");
                    }
                    cat_count--;
                    mvwprintw(categories, cat_count + 1, 1, "                                            ");

                    wrefresh(main);
                    wrefresh(description);
                    wrefresh(deadline);
                    wrefresh(subtask);
                    wrefresh(categories);
                    view_tasks(disc, deadline, subtask1, categories);
                    refresh();
                    break;
                }
            }

            break;

        case 'v': // add categories

            char catcat[20];
            getstr(catcat);
            strcpy(tasks[highlight].catgor, catcat);
            break;

        case 'w':
            save_tasks_to_json("proj.json");
            save_categories_to_json("categories.json");

            break;
        default:
            break;
        }
        wrefresh(main);
    }

    getch();
    endwin();
}

void add_task(const char *title, int n)
{
    if (task_count < 100)
    {
        tasks[task_count].num = n;
        strcpy(tasks[task_count].title, title);
        tasks[task_count].situation = 0;
        task_count++;
    }
}
void view_tasks(WINDOW *disc, WINDOW *deadline, WINDOW *subtask1, WINDOW *categories)
{

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (cathighlite == 0)
    {
    } 
    if (cathighlite == 1)
    {//break
        for (int k = 0; k < 60; k++)
        {
            sort_by_num[k] = tasks[k];
        }
        for (int i = 1; i < task_count; i++)
        {
            for (int j = 0; j < task_count - 1; j++)
            {

                if (sort_by_num[j].num > sort_by_num[j + 1].num)
                {

                    task b = sort_by_num[j];
                    sort_by_num[j] = sort_by_num[j + 1];
                    sort_by_num[j + 1] = b;
                }
            }
        }
    }
    if (cathighlite == 2)
    {
        for (int k = 0; k < 60; k++)
        {
            sort_by_a_z[k] = tasks[k];
        }

        for (int i = 1; i < task_count; i++)
        {
            for (int j = 0; j < task_count - 1; j++)
            {

                if (sort_by_a_z[j].title[0] > sort_by_a_z[j + 1].title[0])
                {

                    task b = sort_by_a_z[j];
                    sort_by_a_z[j] = sort_by_a_z[j + 1];
                    sort_by_a_z[j + 1] = b;
                }
                else if (sort_by_a_z[j].title[1] > sort_by_a_z[j + 1].title[1])
                {

                    task b = sort_by_a_z[j];
                    sort_by_a_z[j] = sort_by_a_z[j + 1];
                    sort_by_a_z[j + 1] = b;
                }
                else if (sort_by_a_z[j].title[2] > sort_by_a_z[j + 1].title[2])
                {

                    task b = sort_by_a_z[j];
                    sort_by_a_z[j] = sort_by_a_z[j + 1];
                    sort_by_a_z[j + 1] = b;
                }
                else if (sort_by_a_z[j].title[3] > sort_by_a_z[j + 1].title[3])
                {

                    task b = sort_by_a_z[j];
                    sort_by_a_z[j] = sort_by_a_z[j + 1];
                    sort_by_a_z[j + 1] = b;
                }
            }
        }
    }
    if (cathighlite == 3)
    {
        for (int k = 0; k < 60; k++)
        {
            sort_by_dead[k] = tasks[k];
        }

        for (int i = 1; i < task_count; i++)
        {
            for (int j = 0; j < task_count - 1; j++)
            {

                if (sort_by_dead[j].yaer > sort_by_dead[j + 1].yaer)
                {

                    task b = sort_by_dead[j];
                    sort_by_dead[j] = sort_by_dead[j + 1];
                    sort_by_dead[j + 1] = b;
                }
                else if (sort_by_dead[j].month > sort_by_dead[j + 1].month)
                {

                    task b = sort_by_dead[j];
                    sort_by_dead[j] = sort_by_dead[j + 1];
                    sort_by_dead[j + 1] = b;
                }
                else if (sort_by_dead[j].day > sort_by_dead[j + 1].day)
                {

                    task b = sort_by_dead[j];
                    sort_by_dead[j] = sort_by_dead[j + 1];
                    sort_by_dead[j + 1] = b;
                }
            }
        }
    }
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    for (int i = 1; i <= 20; i++)
    {
        mvprintw(i, 1, "                                         ");
    }
    if (cathighlite == 0)
    {
        werase(subtask1);
        for (int i = 0; i < task_count; i++)
        {
            if (i == highlight)
            {

                mvwprintw(disc, 1, 1, "                                                                                                                                                           "); // clear the window
                mvwprintw(disc, 1, 1, "%s", tasks[i].discription);
                wrefresh(disc);

                mvwprintw(deadline, 1, 1, "               ");
                if (tasks[i].yaer < 10)
                {
                    mvwprintw(deadline, 1, 1, "000%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 100)
                {
                    mvwprintw(deadline, 1, 1, "00%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 1000)
                {
                    mvwprintw(deadline, 1, 1, "0%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 10000)
                {
                    mvwprintw(deadline, 1, 1, "%d", tasks[i].yaer);
                }

                if (tasks[i].month < 10)
                {
                    mvwprintw(deadline, 1, 5, "/0%d", tasks[i].month);
                }
                else
                    mvwprintw(deadline, 1, 5, "/%d", tasks[i].month);
                if (tasks[i].day < 10)
                {
                    mvwprintw(deadline, 1, 8, "/0%d", tasks[i].day);
                }
                else
                    mvwprintw(deadline, 1, 8, "/%d", tasks[i].day);

                wrefresh(deadline);
                werase(subtask1);

                for (int j = 0; j < tasks[highlight].num_of_sumtask; j++)
                {

                    if (j == subhighlite)
                    {
                        wattron(subtask1, A_REVERSE);
                    }
                    mvwprintw(subtask1, j + 1, 1, "[%c]%s", tasks[highlight].subtasks[j].subsituation ? 'x' : ' ', tasks[highlight].subtasks[j].subtitle);
                    wattroff(subtask1, A_REVERSE);
                }
                wrefresh(subtask1);
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "[%c]%c.%s", tasks[i].situation ? 'x' : ' ', tasks[i].num, tasks[i].title);
            attroff(A_REVERSE);

            for (int k = 0; k < cat_count; k++)
            {
                if (k == cathighlite)
                {
                    wattron(categories, A_REVERSE);
                }
                mvwprintw(categories, k + 1, 1, "%s", cat[k].type);
                wattroff(categories, A_REVERSE);

                wrefresh(categories);
            }
        }
        refresh();
    }
    else if (cathighlite == 1)
    {

        werase(subtask1);
        for (int i = 0; i < task_count; i++)
        {
            if (i == highlight)
            {

                mvwprintw(disc, 1, 1, "                                                                                                                                                           "); // clear the window
                mvwprintw(disc, 1, 1, "%s", sort_by_num[i].discription);
                wrefresh(disc);

                mvwprintw(deadline, 1, 1, "               ");
                if (sort_by_num[i].yaer < 10)
                {
                    mvwprintw(deadline, 1, 1, "000%d", sort_by_a_z[i].yaer);
                }
                else if (sort_by_num[i].yaer < 100)
                {
                    mvwprintw(deadline, 1, 1, "00%d", sort_by_num[i].yaer);
                }
                else if (sort_by_num[i].yaer < 1000)
                {
                    mvwprintw(deadline, 1, 1, "0%d", sort_by_num[i].yaer);
                }
                else if (sort_by_num[i].yaer < 10000)
                {
                    mvwprintw(deadline, 1, 1, "%d", sort_by_num[i].yaer);
                }

                if (sort_by_num[i].month < 10)
                {
                    mvwprintw(deadline, 1, 5, "/0%d", sort_by_num[i].month);
                }
                else
                    mvwprintw(deadline, 1, 5, "/%d", sort_by_num[i].month);
                if (sort_by_num[i].day < 10)
                {
                    mvwprintw(deadline, 1, 8, "/0%d", sort_by_num[i].day);
                }
                else
                    mvwprintw(deadline, 1, 8, "/%d", sort_by_num[i].day);

                wrefresh(deadline);
                werase(subtask1);

                for (int j = 0; j < sort_by_num[highlight].num_of_sumtask; j++)
                {

                    if (j == subhighlite)
                    {
                        wattron(subtask1, A_REVERSE);
                    }
                    mvwprintw(subtask1, j + 1, 1, "[%c]%s", sort_by_num[highlight].subtasks[j].subsituation ? 'x' : ' ', sort_by_num[highlight].subtasks[j].subtitle);
                    wattroff(subtask1, A_REVERSE);
                }
                wrefresh(subtask1);
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "[%c]%c.%s", sort_by_num[i].situation ? 'x' : ' ', sort_by_num[i].num, sort_by_num[i].title);
            attroff(A_REVERSE);

            for (int k = 0; k < cat_count; k++)
            {
                if (k == cathighlite)
                {
                    wattron(categories, A_REVERSE);
                }
                mvwprintw(categories, k + 1, 1, "%s", cat[k].type);
                wattroff(categories, A_REVERSE);

                wrefresh(categories);
            }
        }
        refresh();
    }

    else if (cathighlite == 2)
    {
        werase(subtask1);
        for (int i = 0; i < task_count; i++)
        {
            if (i == highlight)
            {

                mvwprintw(disc, 1, 1, "                                                                                                                                                           "); // clear the window
                mvwprintw(disc, 1, 1, "%s", sort_by_a_z[i].discription);
                wrefresh(disc);

                mvwprintw(deadline, 1, 1, "               ");
                if (sort_by_a_z[i].yaer < 10)
                {
                    mvwprintw(deadline, 1, 1, "000%d", sort_by_a_z[i].yaer);
                }
                else if (sort_by_a_z[i].yaer < 100)
                {
                    mvwprintw(deadline, 1, 1, "00%d", sort_by_a_z[i].yaer);
                }
                else if (sort_by_a_z[i].yaer < 1000)
                {
                    mvwprintw(deadline, 1, 1, "0%d", sort_by_a_z[i].yaer);
                }
                else if (sort_by_a_z[i].yaer < 10000)
                {
                    mvwprintw(deadline, 1, 1, "%d", sort_by_a_z[i].yaer);
                }

                if (sort_by_a_z[i].month < 10)
                {
                    mvwprintw(deadline, 1, 5, "/0%d", sort_by_a_z[i].month);
                }
                else
                    mvwprintw(deadline, 1, 5, "/%d", sort_by_a_z[i].month);
                if (sort_by_a_z[i].day < 10)
                {
                    mvwprintw(deadline, 1, 8, "/0%d", sort_by_a_z[i].day);
                }
                else
                    mvwprintw(deadline, 1, 8, "/%d", sort_by_a_z[i].day);

                wrefresh(deadline);
                werase(subtask1);

                for (int j = 0; j < sort_by_a_z[highlight].num_of_sumtask; j++)
                {

                    if (j == subhighlite)
                    {
                        wattron(subtask1, A_REVERSE);
                    }
                    mvwprintw(subtask1, j + 1, 1, "[%c]%s", sort_by_a_z[highlight].subtasks[j].subsituation ? 'x' : ' ', sort_by_a_z[highlight].subtasks[j].subtitle);
                    wattroff(subtask1, A_REVERSE);
                }
                wrefresh(subtask1);
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "[%c]%c.%s", sort_by_a_z[i].situation ? 'x' : ' ', sort_by_a_z[i].num, sort_by_a_z[i].title);
            attroff(A_REVERSE);

            for (int k = 0; k < cat_count; k++)
            {
                if (k == cathighlite)
                {
                    wattron(categories, A_REVERSE);
                }
                mvwprintw(categories, k + 1, 1, "%s", cat[k].type);
                wattroff(categories, A_REVERSE);

                wrefresh(categories);
            }
        }
        refresh();
    }
    else if (cathighlite == 3)
    {
        werase(subtask1);
        for (int i = 0; i < task_count; i++)
        {
            if (i == highlight)
            {

                mvwprintw(disc, 1, 1, "                                                                                                                                                           "); // clear the window
                mvwprintw(disc, 1, 1, "%s", sort_by_dead[i].discription);
                wrefresh(disc);

                mvwprintw(deadline, 1, 1, "               ");
                if (sort_by_dead[i].yaer < 10)
                {
                    mvwprintw(deadline, 1, 1, "000%d", sort_by_dead[i].yaer);
                }
                else if (sort_by_dead[i].yaer < 100)
                {
                    mvwprintw(deadline, 1, 1, "00%d", sort_by_dead[i].yaer);
                }
                else if (sort_by_dead[i].yaer < 1000)
                {
                    mvwprintw(deadline, 1, 1, "0%d", sort_by_dead[i].yaer);
                }
                else if (sort_by_dead[i].yaer < 10000)
                {
                    mvwprintw(deadline, 1, 1, "%d", sort_by_dead[i].yaer);
                }

                if (sort_by_dead[i].month < 10)
                {
                    mvwprintw(deadline, 1, 5, "/0%d", sort_by_dead[i].month);
                }
                else
                    mvwprintw(deadline, 1, 5, "/%d", sort_by_dead[i].month);
                if (sort_by_dead[i].day < 10)
                {
                    mvwprintw(deadline, 1, 8, "/0%d", sort_by_dead[i].day);
                }
                else
                    mvwprintw(deadline, 1, 8, "/%d", sort_by_dead[i].day);

                wrefresh(deadline);
                werase(subtask1);

                for (int j = 0; j < sort_by_dead[highlight].num_of_sumtask; j++)
                {

                    if (j == subhighlite)
                    {
                        wattron(subtask1, A_REVERSE);
                    }
                    mvwprintw(subtask1, j + 1, 1, "[%c]%s", sort_by_dead[highlight].subtasks[j].subsituation ? 'x' : ' ', sort_by_dead[highlight].subtasks[j].subtitle);
                    wattroff(subtask1, A_REVERSE);
                }
                wrefresh(subtask1);
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "[%c]%c.%s", sort_by_dead[i].situation ? 'x' : ' ', sort_by_dead[i].num, sort_by_dead[i].title);
            attroff(A_REVERSE);

            for (int k = 0; k < cat_count; k++)
            {
                if (k == cathighlite)
                {
                    wattron(categories, A_REVERSE);
                }
                mvwprintw(categories, k + 1, 1, "%s", cat[k].type);
                wattroff(categories, A_REVERSE);

                wrefresh(categories);
            }
        }
        refresh();
    }
    else
        werase(subtask1);
    int line = 0;
    for (int i = 0; i < task_count; i++)
    {
        if (strcmp(cat[cathighlite].type, tasks[i].catgor) == 0)
        {
            line++;
            if (i == highlight)
            {

                mvwprintw(disc, 1, 1, "                                                                                                                                                           "); // clear the window
                mvwprintw(disc, 1, 1, "%s", tasks[i].discription);
                wrefresh(disc);

                mvwprintw(deadline, 1, 1, "               ");
                if (tasks[i].yaer < 10)
                {
                    mvwprintw(deadline, 1, 1, "000%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 100)
                {
                    mvwprintw(deadline, 1, 1, "00%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 1000)
                {
                    mvwprintw(deadline, 1, 1, "0%d", tasks[i].yaer);
                }
                else if (tasks[i].yaer < 10000)
                {
                    mvwprintw(deadline, 1, 1, "%d", tasks[i].yaer);
                }

                if (tasks[i].month < 10)
                {
                    mvwprintw(deadline, 1, 5, "/0%d", tasks[i].month);
                }
                else
                    mvwprintw(deadline, 1, 5, "/%d", tasks[i].month);
                if (tasks[i].day < 10)
                {
                    mvwprintw(deadline, 1, 8, "/0%d", tasks[i].day);
                }
                else
                    mvwprintw(deadline, 1, 8, "/%d", tasks[i].day);

                wrefresh(deadline);
                werase(subtask1);

                for (int j = 0; j < tasks[highlight].num_of_sumtask; j++)
                {

                    if (j == subhighlite)
                    {
                        wattron(subtask1, A_REVERSE);
                    }
                    mvwprintw(subtask1, j + 1, 1, "[%c]%s", tasks[highlight].subtasks[j].subsituation ? 'x' : ' ', tasks[highlight].subtasks[j].subtitle);
                    wattroff(subtask1, A_REVERSE);
                }
                wrefresh(subtask1);
                attron(A_REVERSE);
            }
            mvprintw(line, 1, "[%c]%c.%s", tasks[i].situation ? 'x' : ' ', tasks[i].num, tasks[i].title);
            attroff(A_REVERSE);
        }
        for (int k = 0; k < cat_count; k++)
        {
            if (k == cathighlite)
            {
                wattron(categories, A_REVERSE);
            }
            mvwprintw(categories, k + 1, 1, "%s", cat[k].type);
            wattroff(categories, A_REVERSE);
        }
        wrefresh(categories);
    }
    refresh();
}
// }
void mark_task_as_done()
{

    if (tasks[highlight].situation == 0)
        tasks[highlight].situation = 1;
    else
        tasks[highlight].situation = 0;
}
void add_description(const char *descrip)
{

    strcpy(tasks[highlight].discription, descrip);
}
void del_task(int x)
{

    for (int i = highlight; i < task_count; i++)
    {

        tasks[i] = tasks[i + 1];
    }
}
void edit_task(const char *name, WINDOW *disc, WINDOW *deadline, WINDOW *subtask1, WINDOW *categories, int new_num)
{
    tasks[highlight].num = new_num;
    char empty[30] = {"                              "};
    strcpy(tasks[highlight].title, empty);
    view_tasks(disc, deadline, subtask1, categories);
    strcpy(tasks[highlight].title, name);
}
void save_tasks_to_json(const char *filename)
{
    cJSON *root = cJSON_CreateArray();

    for (int i = 0; i < task_count; i++)
    {
        cJSON *task_json = cJSON_CreateObject();

        cJSON_AddNumberToObject(task_json, "num", tasks[i].num);
        cJSON_AddStringToObject(task_json, "title", tasks[i].title);
        cJSON_AddNumberToObject(task_json, "situation", tasks[i].situation);
        cJSON_AddStringToObject(task_json, "description", tasks[i].discription);
        cJSON_AddNumberToObject(task_json, "year", tasks[i].yaer);
        cJSON_AddNumberToObject(task_json, "month", tasks[i].month);
        cJSON_AddNumberToObject(task_json, "day", tasks[i].day);
        cJSON_AddStringToObject(task_json, "category", tasks[i].catgor);

        cJSON *subtasks_array = cJSON_CreateArray();
        for (int j = 0; j < tasks[i].num_of_sumtask; j++)
        {
            cJSON *subtask_json = cJSON_CreateObject();
            cJSON_AddStringToObject(subtask_json, "subtitle", tasks[i].subtasks[j].subtitle);
            cJSON_AddNumberToObject(subtask_json, "subsituation", tasks[i].subtasks[j].subsituation);
            cJSON_AddItemToArray(subtasks_array, subtask_json);
        }
        cJSON_AddItemToObject(task_json, "subtasks", subtasks_array);

        cJSON_AddItemToArray(root, task_json);
    }

    char *json_string = cJSON_Print(root);
    FILE *file = fopen(filename, "w");
    if (file)
    {
        fprintf(file, "%s", json_string);
        fclose(file);
    }
    else
    {
        printf("");
    }

    cJSON_Delete(root);
    free(json_string);
}
void load_tasks_from_json(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *json_data = malloc(file_size + 1);
    if (!json_data)
    {
        printf("");
        fclose(file);
        return;
    }
    fread(json_data, 1, file_size, file);
    fclose(file);
    json_data[file_size] = '\0';

    cJSON *root = cJSON_Parse(json_data);
    if (!root)
    {
        printf("");
        free(json_data);
        return;
    }

    task_count = 0;

    cJSON *task_json;
    cJSON_ArrayForEach(task_json, root)
    {
        task new_task;

        new_task.num = cJSON_GetObjectItem(task_json, "num") ? cJSON_GetObjectItem(task_json, "num")->valueint : 0;
        strcpy(new_task.title, cJSON_GetObjectItem(task_json, "title") ? cJSON_GetObjectItem(task_json, "title")->valuestring : "No Title");
        new_task.situation = cJSON_GetObjectItem(task_json, "situation") ? cJSON_GetObjectItem(task_json, "situation")->valueint : 0;
        strcpy(new_task.discription, cJSON_GetObjectItem(task_json, "description") ? cJSON_GetObjectItem(task_json, "description")->valuestring : "No Description");
        new_task.yaer = cJSON_GetObjectItem(task_json, "year") ? cJSON_GetObjectItem(task_json, "year")->valueint : 0;
        new_task.month = cJSON_GetObjectItem(task_json, "month") ? cJSON_GetObjectItem(task_json, "month")->valueint : 0;
        new_task.day = cJSON_GetObjectItem(task_json, "day") ? cJSON_GetObjectItem(task_json, "day")->valueint : 0;
        strcpy(new_task.catgor, cJSON_GetObjectItem(task_json, "category") ? cJSON_GetObjectItem(task_json, "category")->valuestring : "No Category");

        cJSON *subtasks_array = cJSON_GetObjectItem(task_json, "subtasks");
        new_task.num_of_sumtask = 0;

        if (subtasks_array && cJSON_IsArray(subtasks_array))
        {
            cJSON *subtask_json;
            cJSON_ArrayForEach(subtask_json, subtasks_array)
            {
                if (new_task.num_of_sumtask < 30)
                {

                    cJSON *subtitle = cJSON_GetObjectItem(subtask_json, "subtitle");
                    if (subtitle && cJSON_IsString(subtitle))
                    {
                        strncpy(new_task.subtasks[new_task.num_of_sumtask].subtitle, subtitle->valuestring, 49);
                        new_task.subtasks[new_task.num_of_sumtask].subtitle[49] = '\0';
                    }
                    else
                    {
                        strcpy(new_task.subtasks[new_task.num_of_sumtask].subtitle, "No Subtask");
                    }

                    cJSON *subsituation = cJSON_GetObjectItem(subtask_json, "subsituation");
                    if (subsituation && cJSON_IsNumber(subsituation))
                    {
                        new_task.subtasks[new_task.num_of_sumtask].subsituation = subsituation->valueint;
                    }
                    else
                    {
                        new_task.subtasks[new_task.num_of_sumtask].subsituation = 0;
                    }

                    new_task.num_of_sumtask++;
                }
            }
        }

        tasks[task_count++] = new_task;
    }

    cJSON_Delete(root);
    free(json_data);
}

void save_categories_to_json(const char *filename)
{
    cJSON *root = cJSON_CreateArray();

    for (int i = 0; i < cat_count; i++)
    {
        cJSON *cat_json = cJSON_CreateObject();
        cJSON_AddStringToObject(cat_json, "type", cat[i].type);
        cJSON_AddItemToArray(root, cat_json);
    }

    char *json_string = cJSON_Print(root);
    FILE *file = fopen(filename, "w");
    if (file)
    {
        fprintf(file, "%s", json_string);
        fclose(file);
    }
    else
    {
        printf("");
    }

    cJSON_Delete(root);
    free(json_string);
}
void load_categories_from_json(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *json_data = malloc(file_size + 1);
    fread(json_data, 1, file_size, file);
    fclose(file);
    json_data[file_size] = '\0';

    cJSON *root = cJSON_Parse(json_data);
    if (!root)
    {
        printf("");
        free(json_data);
        return;
    }

    cat_count = 0;

    cJSON *cat_json;
    cJSON_ArrayForEach(cat_json, root)
    {
        strcpy(cat[cat_count].type, cJSON_GetObjectItem(cat_json, "type")->valuestring);
        cat_count++;
    }

    cJSON_Delete(root);
    free(json_data);
}
