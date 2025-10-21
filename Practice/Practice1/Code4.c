#include <stdio.h>

int main (){

int a ;

scanf("%d", &a);

if ( a < 10) {
    printf("Your password is not secure.");
}
else if (a % 2 == 0){
    printf("Your password is secure.");
} 
else if ( a % 2 != 0){
    printf("Your password is not secure.");
}
return 0 ;}
