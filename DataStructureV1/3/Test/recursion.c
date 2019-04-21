#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    else 
    {
        return n * factorial(n-1);
    }
}

int Fib(n)
{
    int result = 0;
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else 
    {
        return Fib(n-1) + Fib(n-2);
    }
}

int main(int argc, char const *argv[])
{
    int n = Fib(3);
    return 0;
}
