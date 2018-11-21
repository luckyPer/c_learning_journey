#include <stdio.h>
#include <stdlib.h>

int count;
extern void write_extern();

int main()
{
    count = 5;
    //write_extern();
    getPrimeNumber();
    system("pause");
    return 0;
}

void getPrimeNumber()
{
    int i, j;
    for (i = 2; i < 100; i++)
    {
        for (j = 2; j <= (i / j); j++)
        {
            if (!(i % j))
                break;
        }
        if (j > (i / j))
            printf("Prime Number is %d\n", i);
    }
}
