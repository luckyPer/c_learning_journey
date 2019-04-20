#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define initSize  1000
#define maxSize 100

typedef char ElementType;
struct Stack
{
    char Data[maxSize];
    int top;
};

struct Stack * initStack(struct Stack *s) 
{
    s = (struct Stack *)malloc(maxSize);
    s->top  = -1;
    return s;
}

bool IsEmpty(struct Stack *s)
{
    if(s->top == -1) return true;
    return false;
}

bool IsFull(struct Stack *s)
{
    if(s->top == maxSize-1) return true;
    return false;
}

struct Stack * push(struct Stack *s, ElementType x)
{
    if(IsFull(s)) return s;
    s->Data[++s->top] = x;
    return s;
}

ElementType pop(struct Stack *s)
{
    ElementType x;
    if(IsEmpty(s)) return s;
    x = s->Data[s->top--];
    return x; 
}

ElementType getTop(struct Stack *s, ElementType x)
{
    if(IsEmpty(s)) return NULL;
    x = s->Data[s->top];
    return x;
}

bool checkSymbol(char *str)
{
    struct Stack *s= initStack(s);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char sym = str[i];
        switch (sym)
        {
        case '(':
        case '[':
            s = push(s, sym);
            break;
        case ')':
            if(pop(s) != '(') return false;
            break;
        case ']':
            if(pop(s) != '[') return false;
            break;
        default:
            break;
        }
    }
    if(IsEmpty(s)) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    char str[4] = {'(','[',']',')'};
    checkSymbol(str);
    return 0;
}
