#include <stdio.h>
#include <stdlib.h>

void swapNumber(int *first, int *second)
{   
    int temp;

    temp = *first;
    *first = *second ;
    *second = temp;
}

main(int argc, char const *argv[])
{
    int *point1, *point2;
    int a, b;
    scanf("%d,%d", &a, &b);

    point1 = &a;
    point2 = &b;
    swapNumber(point1, point2);
    printf("%d", (a>b) ? *point1: *point2);

    system("pause");
}


