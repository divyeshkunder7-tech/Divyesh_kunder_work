#include<stdio.h>
int main()
{
    int number[7];
    for(int i=0;i<7;i++)
    {
        printf("\nEnter the value for array %d:",i+1);
        scanf("%d",&number[i]);
    }
    for(int i=0;i<7;i++)
    {
        printf("\nThe array is %d",number[i]);
    }
    return 0;
}
