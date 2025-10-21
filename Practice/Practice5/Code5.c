#include <stdio.h>
int main(){

    int b =0;

    char z[6] ;

    scanf("%s",z);

    while(b < 10){

        int a[6];

        for(int i=0;(a[i] = z[i]) != '\0';i++){}

        int black = 0 , whit = 0 ;
        b++;
        char c[6];
        scanf("%s",c);


        for(int i =0;i<5;i++){
            

            for (int j=0;j<5;j++){
                
                if(a[j] == c[j]){black++;a[j] = 0,c[j]=9;if(black == 5){printf("Win");return 0 ;}}
                

                if(a[i] == c[j]){whit++;a[i] = 0;c[j]=9;}
            }
        }
       

        
        
        printf("%d %d\n",black,whit);
    }
    if(b == 10){printf("Lose");}
}
