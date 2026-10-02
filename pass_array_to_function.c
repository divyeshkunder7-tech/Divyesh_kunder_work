#include<stdio.h>
void printarray(int arr[],int size){
    for(int i=0;i<size;i++)
    {
        printf("\n%d",arr[i]);
    }
}
int main()
{
    int numbers[]={10,20,30,40,50};
    printarray(numbers,5);
    return 0;
}
