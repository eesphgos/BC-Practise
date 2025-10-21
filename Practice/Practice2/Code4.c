#include <stdio.h>

int main()
{

    int a, i, j;

    scanf("%d", &a);

    for (i = 2; i <= a; i++)
    {

        int b = 0;

        for (j = 2; j <= i; j++)
        {

            if (i % j == 0)
            {
                b++;
            }
        }
        if (b < 2)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
