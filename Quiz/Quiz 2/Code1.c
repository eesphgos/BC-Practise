#include<stdio.h>

int fun (int x);

int main (){

    int a ;

    scanf("%d",&a);

    printf("%d",fun(a));

    return 0 ;

}

int fun (int x){

int sum = 1 , z;
    if ((x / 10) < 1){return 0 ;}

    while (x > 0 ){

        z = x % 10 ;

        

        x /= 10 ;

        sum *= z ;
       
    }
return 1 + fun(sum);
}
