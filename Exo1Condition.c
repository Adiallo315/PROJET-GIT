#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    printf("Donnez un entier:\n");
    scanf("%d",&a);
    if(a%2==1)
    {
       printf("%d est impair\n",a);
    }
    else
    {
       printf("%d est pair\n",a);
    }
    system("pause");
    return 0;
}
