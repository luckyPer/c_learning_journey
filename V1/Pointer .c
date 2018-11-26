#include <stdio.h>
#include <stdlib.h>

void main()
{
    //firstR();
    //pointerOpertaion();
    int a = 10;
    int b = 20;
    //Swap(a, b);
    //Swap_Pointer(&a, &b);
    //printf("a is %d, b is %d\n", a, b);
    int arr[10] = {1,2,3,4}; int *p = arr; *p = 10; printf("%d\n",*p); p++; *p = 20; printf("%d\n",*p);
    system("pause");
}

void firstR() {
    int var1;
    char var2 = '1';
    printf("var1 memory address is %p\n", &var1);
    printf("var2 memory address is %p\n", &var2);


    int var3 = 20 ;
    int *ip ;
    int *ip2;
    ip = &var3;//assign the variable's address to the pointer

    printf("address value of ip is %p\n", ip);
    printf("value of *ip is %d\n", *ip);
    ip2= ip;
    printf("value of *ip2 is %d\n", *ip2);

    *ip = 100;
    printf("value of var3 is %d\n", var3);
    printf("value of *ip is %d\n", *ip);

    int **pp = &ip;
    printf("value of *pp is %d\n", **pp);
}

void pointerOpertaion() {
    //int *pp = NULL;//no exact address to assign, set NULL -- 0x0
    int var4 = 1000;
    int *pp = 1000;
    pp++;
    printf("value of *pp is %d\n", *pp);
}

void Swap(int a , int b) {
    int temp = a;
    a = b;
    b = temp;
    
    printf("a is %d, b is %d\n", a, b);
}

void Swap_Pointer(int *pa , int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    
    printf("a is %d, b is %d\n", *pa, *pb);
}
