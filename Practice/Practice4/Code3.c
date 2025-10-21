
#include <stdio.h>

int numtoword(int);

int main()
{

    int t, g1, g2, g3, r1, r2, r3, gg1, gg2, gg3, rr1, rr2, rr3,l1=0,l2=0,l3=0;

    scanf("%d %d %d %d %d %d %d", &t, &g1, &g2, &g3, &r1, &r2, &r3);

    enum color
    {
        Red=0,
        Green=1,
        Yellow=2
    };
   

    enum color light1;
    enum color light2;
    enum color light3;

    
   

    gg1 = g1;
    gg2 = g2;
    gg3 = g3;
    rr1 = r1;
    rr2 = r2;
    rr3 = r3;
    light1 = Red ;
    light2 = Red ;
    light3 = Red ;

    if(rr1 == 0 && gg1 != 0){light1 = Green; gg1 = 120;}
    if(rr2 == 0 && gg2 != 0){light2 = Green; gg2 = 120;}
    if(rr3 == 0 && gg3 != 0){light3 = Green; gg3 = 120;}

    if(gg1 == 0 && rr1 != 0){light1 = Red; rr1 = 120; l1 =10;}
    if(gg2 == 0 && rr2 != 0){light2 = Red; rr2 = 120; l2 =10;}
    if(gg3 == 0 && rr3 != 0){light3 = Red; rr3 = 120; l3 =10;}
    


    for (int i = 0; i < t; i++)
    {
        if (light1 == Yellow){light1 = Red;}
        if (light2 == Yellow){light2 = Red;}
        if (light3 == Yellow){light3 = Red;}

        if (rr1 == 0){light1 = Green ; rr1 = r1 ; }
        if (rr2 == 0){light2 = Green ; rr2 = r2 ; }
        if (rr3 == 0){light3 = Green ; rr3 = r3 ; }
        
        if (gg1 == 0 ){light1 = Yellow ; gg1 = g1 ; }
        if (gg2 == 0 ){light2 = Yellow ; gg2 = g2 ; }
        if (gg3 == 0 ){light3 = Yellow ; gg3 = g3 ; }

        if (l1 == 10){light1 = Red;}
        if (l2 == 10){light2 = Red;}
        if (l3 == 10){light3 = Red;}




        printf("Second %d: Lane 1: ", i );
        numtoword(light1);
        printf (" | Lane 2: ");
        numtoword(light2);
        printf(" | Lane 3: ");
        numtoword(light3);
        printf("\n");

        if(light1 == Red){rr1 -- ;} 
        if(light2 == Red){rr2 -- ;}
        if(light3 == Red){rr3 -- ;}

        if(light1 == Green){gg1 -- ;}
        if(light2 == Green){gg2 -- ;}
        if(light3 == Green){gg3 -- ;}
       
    }
    return 0;
}

int numtoword (int x){

    switch (x){

        case 0 :

        printf("Red");
        break;

        case 1 :

        printf("Green");
        break;

        case 2 :

        printf("Yellow");
        break;
    }
}
