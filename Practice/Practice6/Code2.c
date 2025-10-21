#include <stdio.h>
void Roll (char *b);
void roll (char *c);
int n,k;
int main (){

    
    scanf("%d%d",&n,&k);
    char string[n+1];
    scanf("%s",&string);

    for (int i=0;i<k;i++){

        Roll(string);
        roll(string);
    }

    for (int i=0;i<n;i++){

        printf("%c",string[i]);
    }
    
}
void Roll (char *b){

    int hold;
    hold = b[n-1];
    for(int i=n-1;i>0;i--){

        b[i]=b[i-1];
    }
    b[0]=hold;
}
void roll (char *c){

    for (int i=0;i<n;i++){
        if(c[i] == 'z'){c[i] -= 26;}
        c[i] += 1 ;
    }
}
