#include<stdio.h>
#include<string.h>
int main()
{
    char name[]="Mukesh";
    int len=strlen(name);
    int temp;
    for(int i=0;i<len/2;i++)
    {
        temp=name[i];
        name[i]=name[len-i-1];
        name[len-i-1]=temp;
    }
    printf("\nReversed string is:%s",name);
}
