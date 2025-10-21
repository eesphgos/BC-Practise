#include <stdio.h>
#include<math.h>
int fun (int x );


int main(){

    int aa,ab,ac,a0,b0,c0;

    scanf("%d%d",&aa,&ab);
    ac = aa +ab;

    a0 = fun(aa);
    b0 = fun(ab);
    c0 = fun(ac);

    if((a0 + b0) == c0){printf("YES");}
    else printf("NO");


    return 0 ;



}

int fun (int x){

int z = 0,q,m=0;

while(x > 0){

q = x % 10;
x /= 10 ;

if (q == 0){continue;}

m += pow (10 , z)*q ; 
z++;


}


return m ;
}
