#include <stdio.h>
#include <assert.h>
#include "assertion_example.h"

unsigned long long factorial(int n)
{
    assert(n >= 0 && "Factorial input must be non-negative");

    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

void assertion_example_main()
{
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    unsigned long long fact = factorial(n);
    printf("Factorial of %d is %llu\n", n, fact);
}
