#include <stdio.h>

int main (){

int a ,b=0;

scanf("%d",&a);

int aa[a];

for (int i=0;i<a;i++){

    scanf("%d",&aa[i]);
}

for (int i=a-1;i>0;i--){

    if (aa[i] > aa[i-1]){

        int h;
        h=aa[i];
        aa[i]=aa[i-1];
        aa[i-1]=h;
        b++;
        break;
    }
}
int r=0;
if (b == 0){


    for (int i = a/2;i>0;i--){

        int h;

        h=aa[r];
        aa[r]=aa[(a-1)-r];
        aa[(a-1)-r]=h;

        r++;

    }
}
// printf("%d",r);
for (int i=0;i<a;i++){

    printf("%d ",aa[i]);
}


    return 0 ;
}
