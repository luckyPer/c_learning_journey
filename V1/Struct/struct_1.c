#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct birthday
{
    int month;
    int day;
    int year[2];
};

struct birthday bir = {03, 15, {96,1996}};

struct student  //结构体标签
{
    int num;  //变量定义
    char name[20];
    struct birthday b;
    char sex;
    int age;
    float score;
    char addr[30];
}student1;  //结构变量

struct
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30]; 
}stu3 = {1001, "panpan", 'M', 22, 100.0, "shanghai bababa"};


struct Person
{
    char name[20];
    int count;
};

struct Person leader[3] = {"li", 0, "zz", 1, "ll", 2};

void myprintPerson(struct Person per1)
{
    printf("name : %s, count : %d\n", per1.name, per1.count);
}

void myprintbirthday(struct birthday *b)
{
    printf("day is %d\n", b->day);
    printf("year1 is %d\n", b->year[0]);
    printf("year2 is %d\n", b->year[1]);
}

int main()
{
    myprintbirthday(&bir);
    printf("-----------\n");
    //printf("No.: %d. name is %s. sex is %c. score is %f",stu3.num, stu3.name, stu3.sex, stu3.score);
    char leader_name[20];      
    scanf("%s", &leader_name);
    for(int i = 0; i < 3; i++)
    {
        i++;
        strcpy(leader[i].name, leader_name);
        printf("name : %s, count : %d\n", leader[i].name, leader[i].count);
    }
    printf("-----------\n");

    struct birthday b1;
    struct birthday *p;
    p = &b1;
    b1.day = 11;
    printf("day is %d\n", (*p).day);
    printf("day is %d\n", p->day++);
    printf("day is %d\n", ++p->day);
    printf("day is %d\n", b1.day);    
    printf("-----------\n");

    struct Person *pan;
    for(pan = leader; pan< leader+3; pan++)
    {
        printf("name : %s, count : %d\n", (pan++)->name, (pan++)->count);
        printf("name : %s, count : %d\n", pan->name, pan->count);
    }
    printf("-----------\n");
    
    myprintPerson(leader[0]);


    system("pause");
    return 0;
}
