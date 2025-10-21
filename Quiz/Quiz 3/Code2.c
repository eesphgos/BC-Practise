#include<stdio.h>

int main (){

    int a;
    scanf("%d",&a);

    int aa[a][a];

    for (int i=0;i<a;i++){

        for(int j=0;j<a;j++){

            scanf("%d",&aa[i][j]);
        }
    }

    for (int i=0;i<a;i++){

        for (int j=0;j<a;j++){

            int h;
            h=aa[i][j];
            aa[i][j]=aa[j][i];
            aa[j][i]=h;
        }
    }
    for (int i=0;i<a;i++){

        for (int j=a-1;j>=0;j--){

            int h;

            printf("%d ",aa[j][i]);
        }
        printf("\n");}


return 0 ;

}
