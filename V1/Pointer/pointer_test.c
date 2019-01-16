#include <stdio.h>
#include <stdlib.h>

void bsort()
{
    int arr1[] = {4,6,0};
    int temp;
    for(int i = 0; i<3; i++)
    {
        for(int j =0; j <3; j++)
        {
            if(arr1[i] < arr1[j])
            {
                temp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = temp;
            }
        }
    }
    for(int i = 0; i<3; i++)
    {
        printf("%d  \n", arr1[i]);
    }
}

void exchange(int *num1, int *num2, int *num3)
{
    int temparr[3] = {*num1, *num2, *num3};
    int temp;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(temparr[i] > temparr[j])
            {
                temp = temparr[j];
                temparr[j] = temparr[i];
                temparr[i] = temp;
            }
        }
    }
    for(int i = 0; i<3; i++)
    {
        printf("%d\n", temparr[i]);
    }
}

main(int argc, char const *argv[])
{ 
    int num1 =9;
    int num2 =1;
    int num3 =5;
    exchange(&num1, &num2, &num3);
    system("pause");
}
 