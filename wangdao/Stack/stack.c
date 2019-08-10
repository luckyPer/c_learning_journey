#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 999


int main(int argc, char const *argv[])
{
    char str[] = {'I','I','I', 'O', 'I', 'O', 'I',  'O','\0'};
    int i = judgeOperationIsLegal(str);
    printf("%d", i);
    return 0;
}

//page  66
typedef struct LinkList
{
    char data;
    struct LinkList *next;
}LinkList;

///3
int judgeOperationIsLegal(char str[])
{
    int top = -1;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'O' && top == -1)
        {
            return 0;
        }
        if (str[i] == 'I')
        {
            ++top;
        }
        else
        {
            top --;
        }
        i++;
    }
    if (top != -1)
    {
        return 0;
    }
    
    return 1;
} 

//4
int judgeSymmetry(LinkList *L)
{
    LinkList *p = L;
    int stack[maxsize];
    int top = -1;
    
    while (p ->next)
    {
        stack[++top] = p->next->data;
    }
    p = L->next;
    while (top != -1)
    {
        if (stack[top--] != p->data)
        {
            return 0;
        }
    }
    return 1;
}


//5
typedef struct stack
{
    int data[maxsize];
    int top;
}stack;

//s1 栈底为 -1;
//s2 栈底为 n
int PushS1(stack *s1, stack *s2, int X)
{
    if (s2->top - s1->top == 1)
    {
        return 0;
    }
    s1->data[++(s1->top)] = X;
    return 1;
}

int PushS2(stack *s1, stack *s2, int X)
{
    if (s2->top - s1->top == 1)
    {
        return 0;
    }
    s2->data[--(s2->top)] = X;
    return 1;
}

int PopS1(stack *s1, stack *s2, int *X)
{
    if (s1->top == -1)
    {
        return 0;
    }
    X = s1->data[(s1->top)--];
    return 1;
}

int PopS2(stack *s1, stack *s2, int *X)
{
    if (s2->top == maxsize)
    {
        return 0;
    }
    X = s2->data[(s2->top)++];
    return 1;
}