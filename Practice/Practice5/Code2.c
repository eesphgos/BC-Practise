#include<stdio.h>
int main (){

    int n,k,q;

    scanf("%d%d",&n,&k);

    int a[n];

    for (int i =0 ; i<n;i++){

        scanf("%d",&a[i]);
    }

    scanf("%d",&q);
    int qq[q];
    
    for(int i =0;i<q;i++){

        scanf("%d",&qq[i]);
    }

    for(int i=0;i<k;i++){
        
        for(int j=n-1;j>0;j--){

            int hold;
            hold = a[j] ;
            a[j] = a[j-1];
            a[j-1] = hold;

            
        }
       
    }
     for(int i = 0 ; i<q;i++){

    printf("%d\n",a[qq[i]]);
    }

    return 0 ;
}
