#include <stdio.h>
#include <math.h>

long long reverse ( long long x ){


    long long z=0 , x1 , i ,b , c,s=0;

    x1 = x ;
    while (x1 > 0){
 
        x1 /= 10 ;
        z++ ;
    }
    
    for (i = z; i > 0; i --){

        b = x % 10 ;
        x /= 10 ;

        c = b * pow(10,i);

        s = s + c ;
    }

    return s/10 ;
}


int main (){
long long a ;

scanf ("%lld",&a);

printf("%lld",reverse(a));

}
