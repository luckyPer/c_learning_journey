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
        num = getPeachNumber(n+1)*2+1;   //这里是不应该用递归呢？
        printf("第%d天所剩桃子%d个\n", n, num); //天数，所剩桃子个数
    }
    return num;
}

int main()
{   
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
    const int WIDTH = 5;
    printf(" size : %lu ", sizeof(int) );
    system("pause");
    return 0;
}