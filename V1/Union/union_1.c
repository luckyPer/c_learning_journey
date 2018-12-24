#include <stdio.h>
#include <stdlib.h>

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
    printf("%d \n",data2b.age);
    printf("%f \n",data2a.f);
    system("pause");
}
