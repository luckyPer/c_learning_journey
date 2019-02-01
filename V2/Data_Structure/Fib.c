#include <stdio.h>
#include <stdlib.h>


int Fib1(int n)// O(2^n)
{
    if(n <=2) return 1;
    return Fib1(n-1) + Fib1(n-2);
}

int Fib2(int n) {// O(n)
    int result = 0;
    if(n<= 2)   return 1;

    int first = 1;
    int second = 0;
    while( n > 0)
    {            
        result = first + second;
        first = result;
        second = first;
        n--;
    }
    return result;
}

int Fib3(int first, int second, int n) { // O(n)
    if(n <= 2)
    {
        return 1;
    } else if( n== 3 )
    {
        return first + second;
    }       
    return Fib3(second, second + first, n-1);  
}

main()
{
    int v = Fib3(1, 1, 3);
    printf("%d", v);
    system("pause");
}
 