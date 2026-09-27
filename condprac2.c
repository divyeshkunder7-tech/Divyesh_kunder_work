#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter two numbers to compare");
    scanf("%d %d",&a,&b);
    if(a>b){
        printf("\n%d is greater",a);
    }
    else
    {
        printf("\n%d is greater",b);
    }
    return 0;
}