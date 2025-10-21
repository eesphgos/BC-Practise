#include <stdio.h>

void performOperation(int (*operation)(int, int), int a , int b);

void displayMenu ();

int add (int a , int b){return a+b;}
int subtract (int a , int b){return a-b;}
int multiply (int a , int b){return a*b;}
int devide (int a , int b){return a/b;}

int b=0,a1,a2;
int main (){
    
    char *opra[4] = {add,subtract,multiply,devide};

while (b != 5){
    displayMenu();
    if (b > 5 || b < 1){printf("Pleas enter a number between 1 and 5\n\n"); continue;}
    if (b==4 && a2 == 0){printf("Error: Division by zero is not allowed!\n\n");continue;}
    if (b==5){break;}
    performOperation(opra[b-1],a1,a2);
}
    
}
void performOperation(int (*operation)(int , int), int a , int b){
   
    printf("%d\n\n",operation (a,b));
}

void displayMenu (){
    printf("Menu:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
    printf("\nEnter your choice:");
    scanf("%d",&b);
    if (b > 5 || b < 1){return;}
    if (b==5){return ;}
    printf("Enter first number:");
    scanf("%d",&a1);
    printf("Enter second number:");
    scanf("%d",&a2);
    if(b==4 && a2 ==0){return;}
    printf("Result: ");


}

