#include <stdio.h>

int main (){

    int   a ,grade[101],max = 0 , min = 100;
    float ave=0;
    scanf("%d",&a);
    
for (int i =0;i <a ;i++){
    scanf ("%d",&grade[i]);
}
for (int i=0 ;i<a;i++){
float v ;
v = grade[i];
ave += v / a ; 

if ( grade[i] > max){
    max = grade[i];
}
if ( grade[i] < min){
    min = grade[i];
}
}
printf("Average grade: %.2f\n",ave);
printf("Max grade: %d\n",max);
printf("Min grade: %d\n",min);
printf("Grades entered: %d",grade[0]);
for (int i=1;i<a;i++){

    printf(", %d",grade[i]);
}

return 0 ;
}
