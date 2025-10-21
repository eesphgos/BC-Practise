# include <stdio.h>

int main (){

    int a,a1,a2,a3,a4;

    scanf ("%d",&a );
     
     if ( a>=0 , a<= 15 ){
  
    a4 = a % 2;
    a = a / 2;
     a3 = a % 2;
    a = a / 2;
     a2 = a % 2;
    a = a / 2;
     a1 = a % 2;
    a = a / 2;

printf("%d%d%d%d",a1,a2,a3,a4);
     }

     return 0 ;}
