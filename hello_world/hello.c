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
<<<<<<< HEAD
    // int num = getPeachNumber(1);
    // printf(":%d。\n", num);
    static int a = 5;
    a++;
    printf("%d is a\n", a);
=======
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int i,j;
    int sum=0;
    for(i=0;i<3;i++)
    {
       for(j=0;j<3;j++)
       {
           if((i+j)%2 == 0)
           {
                sum += arr[i][j];
           }
       }
    }
    printf("对角线元素之和是：%d\n",sum);

    int num = getPeachNumber(1);
    printf("猴子第一天摘了:%d个桃子。\n", num);
>>>>>>> a4ed191820704a4d84211c4e147cda5e6fa20f47
    const int WIDTH = 5;
    printf(" size : %lu ", sizeof(int) );
    system("pause");
    return 0;
}