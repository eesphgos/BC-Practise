#include<stdio.h>

int main (){


    int  m ,n , q; 

    scanf("%d%d%d",&m,&n,&q);

    int a[m][n] , b[n][q], c[m][q];


for (int i = 0 ; i < m ; i++){

    for(int j = 0;j < n;j++){

        scanf("%d",&a[i][j]);
    }
}
for (int i = 0 ; i < n ; i++){

    for(int j = 0;j < q;j++){

        scanf("%d",&b[i][j]);
    }
}

for (int i = 0 ; i < m ; i++){

    for(int j = 0;j < q;j++){
        int sum =0;
        for(int k = 0; k<n;k++){

        sum += a[i][k] * b[k][j] ;
         
        }
        c[i][j] = sum;
    }
}
for (int i = 0 ; i < m ; i++){

    for(int j = 0;j < q;j++){

        printf("%d ",c[i][j]);
    }
    printf("\n");
}

    return 0;
}
