#include <stdio.h>
#include <stdlib.h>

int count;
extern void write_extern();

int main()
{
    count = 5;
    write_extern();
    system("pause");
    return 0;
}
