#include <stdio.h>
#include <stdlib.h>

double pass_arr_pointer(int *arr, int size) ;


void main()
{
    //firstR();
    //pointerOpertaion();
    int a = 10;
    int b = 20;
    //Swap(a, b);
    //Swap_Pointer(&a, &b);
    //printf("a is %d, b is %d\n", a, b);
    //pointer_arr();
    // int *p1 = &a;
    // int **p2 = &p1;
    // printf("p2 %d\n", **p2);
    int arr1[3] = {1, 1 , 1};
    double avg;
    avg = pass_arr_pointer(arr1, 3);
    printf("avg %f\n", avg);
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
    // int var4 = 1000;
    // int *pp = &var4;
    // printf("value of *pp is %d\n", *pp);
    // printf("value of *pp is %d\n", sizeof(pp));
    // pp = pp +1;
    // printf("value of *pp is %d\n", *pp);
    // printf("value of *pp is %d\n", sizeof(pp));
//      int a = 1;
//     int arr[10] = {1,2,3,4};  
  
//     int *p = &a;  
//     //*p = 10;
//     printf("%d\n",*p);  
//     //printf("%d\n",sizeof(*p) );  
//     p++;
//     //printf("%d\n",sizeof(*p) );  
//     printf("%d\n",*p); 

//     p++;
//     //printf("%d\n",sizeof(*p) );  
//     printf("%d\n",*p);  p++;
//     //printf("%d\n",sizeof(*p) );  
//     printf("%d\n",*p); 
//     // *p = 20;  
//     // printf("%d\n",*p);
    int i[] = {100, 200, 300, 400, 500};
    int *p = i;
    ++*p;
    printf("...%d\n", *p);
    printf("*p = %d\n", *p);
    // printf("...%d\n", *++p);
    // printf("*p = %d\n", *p);
    // printf("...%d\n", ++*p);
    // printf("*p = %d\n", *p);
}

void pointer_arr() {
    int arr1[10] = {100, 200, 300, 400, 500};
    int *p = arr1;
    for(int i = 0; i<10; i++) {
        printf("item %d -- value %d\n",i, *p);
        p++;
    }
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

double pass_arr_pointer(int *arr, int size) {
    int sum = 0;
    double re;
    for (int i = 0; i <size;++i) {
        sum += arr[i];
    }
    re = (double)sum / size;
    return re;
}


