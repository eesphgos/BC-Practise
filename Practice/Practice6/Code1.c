#include <stdio.h>

struct Date
    {
        int day;
        int month;
        int year;
    };

void inputDate (struct Date *d);
void displayDate (struct Date d);
struct Date addDays(struct Date d , int days);
int dateDifference(struct Date d1 , struct Date d2);
int isleapyear (int year);
int main (){
    int b;
    struct Date d1;
    struct Date d2;
    struct Date d3;

    
   

b = 10;
int z=0;
while (b != 6){
    
    printf("Menu:\n1. Enter Date\n2. Display Date\n3. Add Days to Date\n4. Calculate Day Difference\n5. Check Leap Year\n6. Exit\nEnter your choice:\n");
    scanf("%d",&b);
    if(z==0 && b != 1 && b!=6){
        printf("\nDate is emply pleas try agane.\n\n");
        continue;
    }

    switch (b)
    {
    case 1:
    inputDate (&d1);
    
    if((d1.day < 0 || d1.day > 31)||(d1.month < 0 || d1.month > 12)){
        printf("\nThe date not true\npleas try agane.\n\n");
        d1.day = 0;
        d1.month = 0;
        d1.year = 0;
        break;
    }
        z=1;
        break;
    case 2:
    displayDate (d1);
        
        break;
    case 3:
    int q;
    printf("Enter the number of days to add:");
    scanf("%d",&q);
    addDays(d1,q);
        
        break;
    case 4:
    dateDifference(d2,d3);
        
        break;
    case 5:
    if(isleapyear (d1.year) == 1){
        printf("\nThe year is leap.\n\n");
    }
    else printf("\nThe year is not leap.\n\n");
        
        break;
    
    }
    
}
return 0 ;
}
void inputDate (struct Date *d){

    printf("\nEnter day:");
    scanf("%d",&d->day);
    printf("Enter month:");
    scanf("%d",&d->month);
    printf("Enter year:");
    scanf("%d",&d->year);
    printf("\n");
   
}
void displayDate (struct Date d){
    printf("\nDate: %d/%d/%d\n\n",d.day,d.month,d.year);
}
struct Date addDays(struct Date d , int days){
    d.day += days;
    if(d.day > 31){
        while(d.day>31){
            d.day -= 31;
            d.month ++;
        }
    }
    if(d.month > 12){
        while(d.month>12){
            d.month -= 12;
            d.year ++;
        }
    }
    printf("\nNew Date: %d/%d/%d\n\n",d.day,d.month,d.year);
}
int dateDifference(struct Date d2 , struct Date d3){
    int sum=0;
    printf("Date one");
    inputDate(&d2);
    printf("Date two");
    inputDate(&d3);
    sum +=(d2.year - d3.year)*360;
    sum +=(d2.month - d3.month)*31;
    sum +=(d2.day - d3.day);
    if(sum < 0){sum *= -1;}

    printf("\nDifference of two date: %d\n\n",sum);

}
int isleapyear (int year){

    if((year+1) % 4 == 0){return 1;}
    else return 0;
}
