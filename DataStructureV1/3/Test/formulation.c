#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define initSize  1000
#define maxSize 100

typedef char ElementType;
typedef struct Stack
{
    char Data[maxSize];
    int top;
}Stack;

Stack * initStack(Stack *S)
{
    S = (Stack *)malloc(maxSize);
    S->top = -1;
    return S;
}

bool IsEmpty(Stack *S)
{
    if(S->top == -1) return true;
    return false;
}

bool IsFull(Stack *S)
{
    if(S->top == maxSize -1) return true;
    return false;
}

Stack * Push(Stack *S, ElementType X)
{
    S->Data[++S->top] = X;
    return S;
}

ElementType Pop(Stack *S)
{
    ElementType X;
    X = S->Data[S->top --];
    return X;
}

bool IsNumerical(char num)
{
    return (num >= '0' && num <= '9');
}

int  operate(char num1, char num2,  char opr)
{
    int result = 0;
    num1 -= 48;
    num2 -= 48;
    switch (opr)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 / num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    Stack * S;
    S = initStack(S);
    char form[] = {'1', '5', '-', '3', '*'};
    int len = strlen(form);
    for (int i = 0; i < len; i++)
    {
        char n = form[i];
        char num1 , num2;
        if(IsNumerical(n))
        {
            Push(S, n);
        }
        else        
        {
            num2 = Pop(S);
            num1 = Pop(S);
            n = (char)operate(num1, num2, n);
            Push(S, n);
        }
    }
    
    return 0;
}

