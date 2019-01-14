#include <stdio.h>
#include <stdlib.h>
//同一内存地址上存不同类型的数据类型， 但只能有一个成员带值
//表现结果为  
//     data2a.age = 1;
//     data2a.f = 2.0;
//     printf("%d \n",data2a.age);   莫名其妙的数字
//     printf("%d \n",data2a.f);  2.000000
//age内存坑被f占用了
union data1
{
    int age;
    char name;
    float f;
};

union data1 a,b,c;

union data2
{
    int age;
    char name;
    float f;
} data2a, data2b, data2c;


void main()
{
    data2a.age = 1;
    data2a.f = 2.0;
    printf("%d \n",data2a.age);
    printf("%d \n",data2a.f);
    system("pause");
}
