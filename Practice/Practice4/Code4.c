#include <stdio.h>

int fun (int x);
int main(){

    int r=0,v=0,sum=1;
    
    char a[100];

    scanf("%s",a);

    if (a[0] == '0'){printf("0");return 0 ;}
     for (int i =0;a[i] != '\0';i++){
 
        if(a[i+1] == '\0' && a[i] <= '2'){r = 5;}
        if (a[i+1] == '0' && a[i] >= '3'){printf("0");return 0 ;}}
    

    for (int i =0;a[i] != '\0';i++){
        if(r == 5 && a[i+1] == '\0'){sum *= fun(v);}

        if (a[i+1] == '0' && a[i] >= '3'){printf("0");return 0 ;}
     

        if( a[i] >= '3' || a[i] == '0'){;sum *= fun(v);v = 0 ;}
        else if (a[i]=='1' && a[i+1] != '0' && a[i+2] != '0'){;v++;}
        else if (a[i]=='2' && a[i+1] != '0' && a[i+1] <= '6' && a[i+2] != '0'){;v++;}


          
    }
 printf("%d",sum);

return 0;
}

int fun (int x){
int z0=0,z1=1,z2;

for(int i = 0 ; i<=x;i++){
z2=z1+z0;
z0=z1;
z1=z2;
}
return z2 ;
}
