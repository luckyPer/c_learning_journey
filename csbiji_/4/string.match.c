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
    int i,j = 0;
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

int getNext(Str str, int next[])
{
    int j = 1;
    int k = 0;
    next[1] = 0;
    while (j < str.len)
    {
        if(k == 0 || str.ch[j] == str.ch[k])
        {
            next[j+1] = k+1;
            j++;
            k++;
        }
        else
        {
            k = next[k];
        }
        
    }
    
}
