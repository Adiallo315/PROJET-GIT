#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b;
    printf("Donnez les deux entiers a comparer:\n");
    scanf("%d%d",&a,&b);
    if(a==b)
    {
       printf("%d=%d\n",a,b);
    }
    else
    {
       if(a<b)
       {
          printf("%d<%d\n",a,b);
       } 
       else
       {
          printf("%d>%d\n",a,b);
       }
    }
    system("pause");
    return 0;
}
