#include <stdio.h>
#include <math.h>

int main()
{

    long long i, j = 0, a, b,b1, c, a1, a2, s = 0, s1, z = 0, x = 0, q = 0, k, x1, o,x4,x3;

    scanf("%lld%lld%lld", &a, &b, &c);

    a1 = a;

    while (a1 > 0)
    {
        a1 /= 10;
        j++;
    }

    for (i = 0; i < j; i++)
    {
        a2 = a % 10;

        a /= 10;
        s = s + (a2 * pow(b, i));
    }
     

    while (s >= 1)
    {

        int f = 0;

        f = s % c;
        s = s / c;
        x = x + f * pow(10, z);
        z++;
    }
    x1 = x;

    
    
    while (x1 > 0)
    {

        x1 /= 10;
        q++;
    }
   
    if (q == 1){
        printf("YES");
    return 0 ;}

    x3=x;
    b1 = q;
    for (k = 0; k < q / 2; k++)
    {

        long long a,  e, r, w, t;

        r = x3 %  10 ;
        x3 /= 10 ;

        b1 -- ;

        x4 = x ;

        w = x4 / pow (10,b1);

        e = w % 10 ;
        


        if (r == e)
        {
            o = 1;
            continue;
        }
        if (r != e)
        {
            o = 0;
            printf("NO");
            break;
        }
    }

    if (o == 0)
    {
        return 0;
    }
    else if (o == 1)
    {
        printf("YES");
 
    }
}
