#include <stdio.h>
int main (){

    int m,c=0;

    scanf("%d",&m);

    char a[m],a1[m];

    scanf("%s",a);
    scanf("%s",a1);


    for(int i =0;i<m-2;i++){

        if(a[i] == '_' && a[i+1] == '_' && a[i+2] == '_'){i += 2 ;c++;}
    }
    for(int i =0;i<m-2;i++){

        if(a1[i] == '_' && a1[i+1] == '_' && a1[i+2] == '_'){i += 2 ;c++;}
    }

    printf("%d",c);

    return 0 ;
}
