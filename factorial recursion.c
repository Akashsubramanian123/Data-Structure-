#include <stdio.h>
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
    } 
    else {
        unsigned long long fact = factorial(num);
        printf("Factorial of %d = %llu", num, fact);
    }
    return 0;
}
