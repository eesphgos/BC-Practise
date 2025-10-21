#include <stdio.h>
#include <math.h>


int main (){

int m=0 , n=0 ,a=0,sum=0;

scanf ("%d%d",&n,&m);

for (int i = -10 ; i<=m ; i++){



    for ( int j = 1 ; j <=n;j++){

        a = pow((i+j),3) / pow((j),2);

        sum += a;

    }
}

printf("%d",sum);

return 0 ;
}
