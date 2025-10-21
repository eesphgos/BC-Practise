# include <stdio.h>

int main (){

    int a , b , c ,score =0 ;

    
   scanf("%d" , &c);
   
   b = c ;

   if ( c <= 5){   printf("Flashlight is ON in room %d.\n" ,c); score += 10; } else 
   if ( c >= 6){   printf("Flashlight is ON in room %d.\n" ,c); score += 20; }
    
   
  
    while ( a != -1){ 

        scanf ("%d" , &a);

        if (a == -1){break;}

      
         if ( b == a){ 
            if ( a<= 5){score += 10;}
            else if ( a >= 6){ score += 20;}
           
        }
    
            
         else if ( a <= 5){
        
            printf("Flashlight is OFF.\n");
            printf("Flashlight is ON in room %d.\n" ,a);
            
            score += 10;}
         else if ( a >= 6 ){
            
            printf("Flashlight is OFF.\n");
            printf("Flashlight is ON in room %d.\n" ,a);
           
            score += 20;
            }
          b = a ;
            }

    printf("Flashlight is OFF.\n");

            
            
           

     score = score ;
    

    printf("Total Score: %d\n" ,score);

    return 0; }
