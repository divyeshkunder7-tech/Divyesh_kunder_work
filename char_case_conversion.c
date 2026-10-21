#include<ctype.h>
#include<stdio.h>
int main()
{
    char ch='a';
    if(isupper(ch))
    {
        printf("\ncharacter is in uppercase");
    }
    else
    {
        ch=toupper(ch);
        printf("\nNow character %c is in uppercase",ch);
    }
}
