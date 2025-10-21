#include <stdio.h>

int main()
{

    int class, member, a, i, j,lowest,highest;
    float average, high = 0, low = 20;

    scanf("%d", &class);

    for (i = 1; i <= class; i++)
    {
        scanf("%d", &member);
        int max = 0, min = 20;
        float count = 0, average;

        for (j = 0; j < member; j++)
        {

            scanf("%d", &a);

            count = count + a;

            if (a < min)
            {
                min = a;
            }
            if (a > max)
            {
                max = a;
            }
        }

        average = count / member;
        printf("Class %d:\n", i);
        printf("Average: %.2f\n", average);
        printf("Max: %d\n", max);
        printf("Min: %d\n", min);

        if (average <= low)
        {
            low = average;
            lowest = i ;
        }
        if (average >= high)
        {
            high = average;
            highest = i;
        }
    }

    printf("Class with highest average: %d\n", highest);
    printf("Class with lowest average: %d\n", lowest);
    return 0;
}
