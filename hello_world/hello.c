#include <stdio.h>
#include <stdlib.h>

extern int a; //声明变量，未定义，不建立存储空间。 对比 int a

#define LENGTH  10
int getPeachNumber(n)
{
    int num;    //定义所剩桃子数
    if(n==10)
    {
       return 1;
    } 
    else
    {
        num = getPeachNumber(n+1)*2+1;
        printf("%d day%d ---\n", n, num); 
    }
    return num;
}

int main()
{   
    // int num = getPeachNumber(1);
    // printf(":%d。\n", num);
    static int a = 5;
    a++;
    printf("%d is a\n", a);
    const int WIDTH = 5;
    printf(" size : %lu ", sizeof(int) );
    system("pause");
    return 0;
}