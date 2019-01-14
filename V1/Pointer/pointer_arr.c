#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    int arr1[10] = {1,2,3};
    int *p;

    for(int i = 0; i<10; i++)
    {
        //printf("%d\n" , *(arr1+ i ));
    }
    for(p = arr1; p<(arr1+10); p++)
    {

        printf("%d\n" , *(p));
    }
    system("pause");
}
 