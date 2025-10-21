#include <stdio.h>

int main (void){
    
    int a,b,d;
    char aa ;

    scanf("%d %d %c", &a , &b, &aa );

  
    if (aa==('*')){
        d=(a*b);
        printf("%d",d);
    }
    
    
     else if (aa=='/'){
        if (b != 0){
        d=(a/b);
        
        printf("%d",d);}
        else if (b == 0){ 
            printf("Error: Division by zero is not allowed");
        }
   
    }
    else if (aa==('+')){
        d=(a+b);
        printf("%d",d);
    }
    else if (aa==('-')){
        d=(a-b);
        printf("%d",d);
    }
    

        return 0; }
