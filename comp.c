#include <stdio.h>

int main(){
    int num = 1;
    int comp1 = 0;
    int comp2 = 0;
    int comp3 = 0;

   
while(num != 0){ 
    scanf("%d",&num);
    switch (num)
    {
    case 1:
        printf("1\n");
        comp1 += 1;
        break;
    case 2:
        printf("2\n");
        comp2 += 1;
        break;
    case 3:
        printf("3\n");
        comp3 += 1;
        break;
    }
 
}printf("nombre de 1 :%d; nombre de 2 :%d; nombre de 3 :%d;",comp1,comp2,comp3);
}