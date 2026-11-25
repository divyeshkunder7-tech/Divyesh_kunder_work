#include <stdio.h>

int Factorial(int n);

int main() {
    int n, result;
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid Input\n");
        return 0; 
    }

    result = Factorial(n);

    printf("Factorial of number = %d\n", result);

    return 0; 
}

int Factorial(int n) {
    if n == 0 or n == 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    if n > 1, return n * Factorial(n - 1)
    else {
        return n * Factorial(n - 1);
    }
}
