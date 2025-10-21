#include <stdio.h>

int main()
{

    long long a, b, sum = 0;

    scanf("%lld", &a);

    if(a<0){a = a * -1;}

    if ( 10 > a &&  a > -10)
    {
        printf("%lld", a);
    }
    else

        if (a >= 10 ||a <= -10)
    {

        while (a >= 1||a<=-1)
        {

            b = a % 10;
            a = a / 10;
            sum = sum + b;
        }

        printf("%lld", sum);
    }
    return 0;
}
