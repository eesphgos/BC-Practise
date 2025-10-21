#include <stdio.h>

int main (){

    int n , k , i , j ;

    scanf("%d" , &n);      
        for (i=n ; i>0; i--)       
            {
            for ( j=1 ; j < i ; j++ ){
              printf(" ");}
            printf("/");
            for (k=0 ; k<(n-i); k = k  +  1  ){
             printf("  ");}
    
            printf("\\\n");}

    return 0; }
