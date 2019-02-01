#include <stdio.h>
#include <stdlib.h>


arrReverse(int *arr, int len)
{
    int temp;
    int max = (len-1)/2;
    int *p = arr+ max;
    int *i = arr;
    int *j = arr + len - 1;
    for(; i <= p; i++, j--)
    {
        temp = *i;
        *i = *j;
        *j = temp;

    }   
    for(int i = 0; i< len; i++)
    {
        printf("%d\n" , arr[i]);
    }
}

main(int argc, char const *argv[])
{
    int arr1[5] = {1,2,3,7,5};
    int *p;
    p = arr1;
    // for(int i = 0; i<3; i++)
    // {
    //     printf("%d\n" , *(arr1+ i ));
    // }
    // for(p = arr1; p<(arr1+3); p++)
    // {
    //     printf("%d\n" , *(p));
    // }
    //printf("%d\n" , *(p+1));
    arrReverse(arr1, 5);
    system("pause");
}
 