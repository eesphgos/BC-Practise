#include <stdio.h>

long long numpar(int x);

int main()
{

    int a;
    scanf("%d", &a);
    printf("%lld", numpar(a));

    return 0;
}

long long numpar(int x)
{

    if (x == 1)
    {
        return 1;
    }

    return (2*((2*x)-1))*numpar(x-1)/(x+1);
}
