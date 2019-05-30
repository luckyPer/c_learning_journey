#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 999

void push(char stack[], int *top, int x)
{
    stack[++(*top)] = x;
}

void pop(char stack[], int *top, int *x)
{
    *x = stack[*top];
    (*top)--;
}

void getTop(char stack[], int top, int *x)
{
    *x = stack[top];
}

int isMatched(char right, char left)
{
    if (right == '(' && left ==')')
    {
        return 1;
    }
    else if (right == '[' && left ==']')
    {
        return 1;
    }
    else if (right == '{' && left =='}')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void checkSymblo(char symblo[], int len)
{
    char stack[MaxSize];
    int top = -1;
    char left, right,s, topS;
    for (int i = 0; i < len; i++)
    {
        s = symblo[i];
        if (s == '(' || s == '[' || s == '{')
        {
            push(stack, &top, s);
        }
        if (s == ')' || s == ']' || s == '}')
        {
            if (top == -1 )
            {
                return 0;
            }
            else
            {
                getTop(stack, top, &left);
                if (!isMatched(right, s))
                {
                    return 0;
                }
                else
                {
                    pop(stack, &top, NULL);
                }               
            }
                       
        }
    } 
    if (top > -1)
    {
        return 0;
    }
     
}

int main(int argc, char const *argv[])
{
    char symbol[10] = {'{','}'};

    return 0;
}
