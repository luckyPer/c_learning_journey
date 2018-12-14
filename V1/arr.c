#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 要生成和返回随机数的函数 */
int *getRandom()
{
    static int r[10];
    int i;

    //   /* 设置种子 */
    //   srand( (unsigned)time( NULL ) );
    //   for ( i = 0; i < 10; ++i)
    //   {
    //      r[i] = rand();
    //      printf( "r[%d] = %d\n", i, r[i]);

    //   }
    multi_arr();
    system("pause");
    return r;
}

/* 要调用上面定义函数的主函数 */
int main()
{
    /* 一个指向整数的指针 */
    int *p;
    int i;

    p = getRandom();
    for (i = 0; i < 11; i++)
    {
        printf("*(p + %d) : %d\n", i, *(p + i));
    }
    system("pause");
    return 0;
}

void arr1()
{
    int arr1[10] = {100, 200, 300, 400, 500};
    for (int i = 0; i < 10; i++)
    {
        printf("item %d -- value %d\n", i + 1, arr1[i + 1]);
    }
    printf("item %d -- value %d\n", 10, arr1[10]);
}

void multi_arr()
{
    int arr2[2][3] = {
        {4, 5, 6},
        {7, 8, 9}};
    int a = arr2[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("a[%d][%d] = %d \n", i, j, arr2[i][j]);
        }
    }
}