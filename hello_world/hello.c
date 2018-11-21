#include <stdio.h>
#include <stdlib.h>

extern int a; //声明变量，未定义，不建立存储空间。 对比 int a

#define LENGTH  10

int main()
{
    const int WIDTH = 5;
    printf(" size : %lu ", sizeof(int) );
    system("pause");
    return 0;
}