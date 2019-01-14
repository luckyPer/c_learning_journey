#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct Person)

struct Person
{
    char name[10];
    int age;
    struct Person *next;
}pan = {"pan", 23};

struct Person * initPerson()
{
    struct Person *p1, *p2, *header;
    header = NULL;
    p1 = (struct Person *) malloc(LEN);
    header = p1;
    p1->age = 10;
    //p1->name ="";  //string 不能用 = 来赋值， 结构体string不定长，不能动态分配内存
    strcpy(p1->name,"Jimy");  
    p2 = (struct Person *) malloc(LEN);
    p1->next = p2; 
    strcpy(p2->name,"Pan"); 
    p2->age = 20;
    p2->next = NULL;
    return header;
}

void printfMyBirthday(struct Person *per)
{
    printf("%s,  %d\n", per->name, per->age);
}
main()
{
    //printf("%s,  %d\n", pan.name, pan.age);
    struct Person * header = initPerson();
    printfMyBirthday(&pan);
    system("pause");
}