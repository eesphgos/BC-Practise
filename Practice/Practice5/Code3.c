#include <stdio.h>
#include <math.h>

int a(int);

int main()
{

    int x =3;

    scanf("%d", &x);
    int aa[x];
    
    for (int i = 0; i < x; i++)
    {
        // aa[i] = i; 
        scanf("%d", &aa[i]);
    }

    for (int k = 0; k <= x; k++)
    {
        for (int i = 0; i < pow(2, x); i++)
        {
            if (a(i) == k){
            int q = 0;
            printf("[");
            for (int j = 0; j < x; j++)
            {
                
                
                    if (i & (1 << j))
                    {
                        if (q > 0)
                        {
                            printf(", ");
                        }
                        printf("%d", aa[j]);
                        q++;
                    }
                
            
                }
                printf("]\n");
        }
            }
            

        
    }
}
int a(int x)
{
    int b = 0;
    while (x)
    {

        b += x & 1;
        x >>= 1;
    }
    // printf("-%d |",b);
    return b;
}
