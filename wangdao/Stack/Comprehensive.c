#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 999

//page 90 栈 队列综合应用


//1
bool judge(char *operation)
{
    int i = 0;
    char stack[maxsize];
    int top = -1;
    while (operation[i] != '\0')
    {
        switch (operation[i])
        {
        case '(':
        case '[':
        case '{':
            stack[++top] = operation[i];   
            break;
        case ')':   
            if (stack[top] == '(')
            {
                stack[top--];
            }
            else
            {
                return false;
            }
            break;
        case ']':   
            if (stack[top] == '[')
            {
                stack[top--];
            }
            else
            {
                return false;
            }
            break;
        case '}':  
            if (stack[top] == '{')
            {
                stack[top--];
            }
            else
            {
                return false;
            } 
            break;
        }
    }  
    if (top != -1)
    {
        return false;
    }
    
    return true;
}


//2
void schedu(char *train)
{
    char stack[maxsize];
    int top = -1;
    char s;
    int i = 0;
    int k = 0;
    while (train[i] != '\0')
    {
        switch (train[i])
        {
        case 'H':
            stack[++top];
            break;
        case 'S':
        train[k++] = train[i];
            break;
        }
        i++;
    }   
    while (top != -1)
    {
        train[k++] = stack[top--];
    }
}

//3
int Pn(int X, int n)
{
    if(n == 0) return 1;
    if(n == 1) return 2*X;

    return 2*X*Pn(X, n-1)-2*(n-1)*Pn(X, n-2);
}

int PnNoneRecursion(int X, int n)
{
    struct 
    {
        int val;
        int no;
    }stk[maxsize];

    int top = -1;
    int v1 = 1,v2 = 2*X;
    int i = n;
    while (i>=2)
    {
        stk[++top].no = i;
        i--;
    }
    while (top != -1)
    {
        stk[top].val = 2*X*v2 - 2*(stk[top].no - 1)*v1;
        v1 = v2;
        v2 = stk[top].val;
        top--;   
    }
    if (n==1)
    {
        return v1;
    }
    
    return v2;
}