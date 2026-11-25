#include<stdio.h>
int sum(int a , int b);

int main()
{
    printf("\nSum of two numbers is:%d",sum(5,6));
    printf("\nSum of two numbers is:%d",sum(15,6));
    printf("\nSum of two numbers is:%d",sum(25,6));
    printf("\nSum of two numbers is:%d",sum(35,6));
}

int sum(int a ,int b)
{
    int sum;
    sum=a+b;
    return sum;
}
