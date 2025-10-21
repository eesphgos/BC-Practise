#include <stdio.h>
#include <math.h>

int Units(int);
int Rectangle(int);
int power(int);
int Repower(int);

int main()
{
    int a, b, c;
    scanf("%d", &a);
    b = Units(a);
    c = Rectangle(b);
    
    return 0;
}

int Units(int x)
{

    x = x % 10;

    return x;
}

int Rectangle(int x)
{



    for (int j = 1; j <= x; j++)
    {
        for (int i = x-j; i >0; i--)
        {

            printf("*");
        }
        printf("%d\n", power(j));
    }

    for (int j = x;j>=1 ; j--){

        printf("%d", Repower(j));

        for(int i = x - j ;i>0;i--){

            printf("*");
        }
        printf("\n");
    }

    return 0;
}

int power(int x)
{

    int i, j,b=0;

    for (i = 1; i <= x; i++)
    {

        j = i * pow(10, i - 1);

    b = b + j   ;
    }
     
   
    return b;
}
int Repower(int x){
int i , j , b=0;

for (i = x ; i>=1;i--){

   j = i * pow(10,x - i);
   b=b+j;
}
return b ;
}
