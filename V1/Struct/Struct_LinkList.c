#include <stdio.h>
#include <stdlib.h>
#define NULL 0

struct student
{
    long num;
    float score;
    struct student *next;
};

void main()
{
    struct student a,b,c,*head,*p;
    a.num = 101; a.score = 88;
    b.num = 102; b.score = 86;
    c.num = 103; c.score = 81;
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    //p = head;
    do
    {
        printf("num = %ld , score = %f \n", head->num, head->score);
        head = head->next;
    } while(head!=NULL);

    system("pause");
}
