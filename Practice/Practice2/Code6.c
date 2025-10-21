#include <stdio.h>

int main()
{

    long long n, i, n1 = 0, n2 = 1, n3;
    scanf("%lld", &n);

    if (n == 0)
    {
    }
    else if (n == 1)
    {
        printf("0");
    }
    else
    {

        printf("%lld %lld ", n1, n2);

        for (i = 0; i < n - 2; i++)
        {

            n3 = n1 + n2;

            if (n3 < 0)
            {
                n3 = n3 * (-1);
            }

            printf("%lld ", n3);

            n1 = n2;
            n2 = n3;
        }
    }
    return 0;
}
