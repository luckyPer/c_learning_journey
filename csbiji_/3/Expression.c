#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 999

bool IsNumerical(char num) 
{
    return (num >= '0' && num <= '9');  
}

void push(int num[], int *top, int x)
{
    num[++(*top)] = x;
}

void pop(int num[], int *top, int *x)
{
    *x = num[*top];
    (*top)--;
}

int  operate(int num1, int num2,  char opr)
{
    int result = 0;
   
    switch (opr)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == '0')
        {
            return result = NULL;
        }       
        result = num1 / num2;
        break;
    }
    return result;
}

//用栈求后缀表达式
void calculateEnd(char expression[])
{
    int num[MaxSize];
    int top = -1;
    int num1, num2, result;
    char e;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        e = expression[i];
        if (IsNumerical(e))
        {
            e = e - '0';
            push(num, &top, e);
        }
        else 
        {
            pop(num, &top, &num2);  
            pop(num, &top, &num1);  
            result  = operate(num1, num2, e);
            push(num, &top, result);
        }      
    }
    
}

//用栈求前缀表达式
void calculateFront(char expression[], int len)
{
    int num[MaxSize];
    int top = -1;
    int num1, num2, result;
    char e;
    for (int i = len-1; len >= 0; i--)
    {
        e = expression[i];
        if (IsNumerical(e))
        {
            e = e - '0';
            push(num, &top, e);
        }
        else 
        {
            pop(num, &top, &num1);  
            pop(num, &top, &num2);  
            result  = operate(num1, num2, e);
            push(num, &top, result);
        }      
    }
    
}

int main(int argc, char const *argv[])
{
    char form[] = {'1', '5', '-', '3', '*'};
    calculateFront(form);
    return 0;
}



