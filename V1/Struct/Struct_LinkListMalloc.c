#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct student)

struct student
{
    int num;
    int score;
    struct student * next;
};

int n;

struct student * creat()
{
    n = 0;
    struct student *head;
    struct student *p1, *p2;
    p1 = p2 = (struct student * ) malloc(LEN);
    head = NULL;
    scanf("%d, %d", &p1->num, &p1->score);
    
    printf("%d, %d\n", p1->num, p1->score);
    while(p1->num != 0)
    {
        n = n + 1;
        if(n == 1) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = (struct student * ) malloc(LEN);
        scanf("%d, %d", &p1->num, &p1->score);
    }
    p2 ->next = NULL;
    return head;
}

void printStudent(struct student *head)
{
    struct student *p;
    if(head==NULL) return;
    p = head;
    do
    {
        printf("num is : %d\n", p->num);
        p = p->next;
    } while(p!= NULL);
}

void deleteStudent(struct student *head, int num)
{
    struct student *p1, *p2;
    if(head == NULL) return;
    
    p1 = head;
    if(p1->num == num)
    {
        head = p1->next;
    }
    else 
    {
        do
        {
            p2 = p1;
            p1 = p1->next;
            if(p1->num == num)
            {
                p2->next = p1->next;
                break;
            }
        } while(p1 != NULL);
    }

}

void appendStudent(struct student *head, int num, int score)
{
    struct student *p1, *p2, *next;
    p1->num = 4;
    p1->score = 66;
    p2 = head;
    if(head == NULL)
    {
        head = p1;
    }
    else 
    {
        do
        {
            next = p2->next;
            if(p2->num > num)
            {
                p2 ->next = p1;
                p1->next = next;
            }
            p2 = p2->next;
        } while(p1 != NULL);
    }
}

void qSortStudent(struct student *head)
{
    int t = 0;
    int s = 0;
    struct student *temp1;
    struct student *temp2;
    for(temp1 = head; temp1->next != NULL ; temp1 = temp1->next)
    {
        for(temp2 = head; temp2->next != NULL ; temp2 = temp2->next)
        {
            if(temp2->num > temp2->next->num)
            {
                t = temp2->num;
                temp2->num = temp2->next->num;
                temp2->next->num = t;

                s = temp2->score;
                temp2->score = temp2->next->score;
                temp2->next->score = s;
            }
        }
    }
}

void main ()
{
    struct student *head = creat();
    qSortStudent(head);
    printStudent(head);
    printf("delect a point\n");
    int num = 0;
    //scanf("%d", &num);
    //deleteStudent(head , num);
appendStudent(head, 4, 66);
    system("pause");
}