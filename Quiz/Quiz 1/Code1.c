#include <stdio.h>
#include <math.h>


int main (){

    float da ,dam,dammax,dammin,a,b,c;

    scanf("%f%f",&da,&dam);

    dammax = dam +( 2.5 * dam / 100);
    dammin = dam - (2.5 * dam / 100);

   

    if (da > dammax){

        a = da * 20 / 100;

        printf("%.2f",da - a);



    }

    else if (da <= dammax && da >= dammin ){

        b = da *10 / 100;

        printf("%.2f",da - b);


    }

    else if (da < dammin){

        c = da *5 / 100 ;

        printf("%.2f",da - c);


    }
 return 0 ;
}
