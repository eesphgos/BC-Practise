#include <stdio.h>

int main()
{

    int k, n = 0, a, b = 0;

    scanf("%d %d", &n, &k);
    a = n;

    while (n != 0)
    {

        if (n < 0)
        {
            n = n + a;
        }
        n = n - k;
        b++;
    }
    printf("%d\n", b);
    return 0;
}
