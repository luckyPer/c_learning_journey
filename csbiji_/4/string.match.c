#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxSize 100

typedef struct 
{
    char *ch;
    int len;
}Str;

/*
 *@description: 暴力求解字符串匹配, Str 数组的第0 index 不存数据
 *@params1: 原串
 *@params2: 比配串
 *@return: k 为匹配成功de index
 *@date: 2019-05-30 20:49:29
*/
int naive(Str str, Str subStr)
{
    int i = 1;
    int j = 1;
    int k = i;
    while (i <= str.len && j <= subStr.len)
    {
        if (str.ch[i] == str.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = 1;
            i = ++k;
        }        
    }
    if (j > subStr.len)
    {
        return k;
    }
    else 
    {
        return 0;
    }   
}

/*
 *@description: KMP,i不用回溯
 *@params1: 原串
 *@params2: 比配串
 *@params3: 比配串计算得到的next数组
 *@return: 匹配成功de index
 *@date: 2019-05-30 20:57:57
*/
int KMP(Str str, Str subStr, int next[])
{
    int i,j = 1;
    while (i <= str.len && j <= subStr.len)
    {
        if (j == 0 || str.ch[i] == str.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }        
    }
    if (j > subStr.len)
    {
        return i-subStr.len;
    }
    else 
    {
        return 0;
    }    
}

/*
 *@description: 匹配串下标依旧从1开始, 运用已知的 next[k] 求出 next[k+1]
    j: S(t) 时的状态, 可称为Fr
    k: S(t+1) 时的状态,可称为Fl

    1. str[k] == str[j] 时, next[k+1] = next[k] +1;
    2. str[k] != str[j] 时, 循环, 让next[k] = k, 使得k=0 或者使得满足1. 为止的时候. k= next[j+1] = 1
    3. next[1] = 0
 *@params1: 匹配串
 *@params2: next数组
 *@return: 地址引用next数组
 *@date: 2019-05-31 20:51:22
*/
int getNext(Str str, int next[])
{
    int j = 1;
    int k = 0;
    next[1] = 0;
    while (j < str.len)
    {
        if(k == 0 || str.ch[j] == str.ch[k])
        {
            //next[j+1] = k+1;
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }     
    }  
}

/*
 *@description: 求nextVAL
 先求出对应的next数组
 1. j = 1 时, nextval[1] = 0 ,作为特殊标记
 2. pj != pk 时, nextval[j] = k
 3. pj == pk 时, nextval[j] = nextval[k]
 *@date: 2019-08-13 20:53:24
*/
void getnextval(Str str, int nextval[])
{
    int j = 1, k = 0;
    nextval[1]  =0;
    while (j < str.len)
    {
        if(k == 0 || str.ch[j] == str.ch[k])
        {
            k++;
            j++;
            if (str.ch[j] != str.ch[k])
            {
                nextval[j] = k;
            }
            else
            {
                nextval[j] = nextval[k];
            }
        }
        else
        {
            k = nextval[k];
        }
    } 
}