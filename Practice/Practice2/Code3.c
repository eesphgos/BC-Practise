#include <stdio.h>
int main()
{
    int a, i, b, j, k, x, z, s, h;
    scanf("%d", &a);
    for (i = 0; i < a + 1; i++)
    {
        b = a - i + 1;
        for (j = b - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (k = 0; k < i + i - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (x = 1; x < a; x++)
    {

        h = a - x;

        for (z = 0; z < x; z++)
        {

            printf(" ");
        }
        for (s = h + h - 1; s > 0; s--)
        {

            printf("*");
        }
        printf("\n");
    }
    return 0;
}
