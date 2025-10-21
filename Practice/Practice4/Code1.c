#include <stdio.h>

int pele(int x);

int main()
{

    int a;

    scanf("%d", &a);

    printf("%d", pele(a));

    return 0;
}

int pele(int x)
{

    if (x == 1)
    {
        return 1;
    }
    if (x == 2)
    {
        return 2;
    }

    return pele(x - 1) + pele(x - 2);
}
