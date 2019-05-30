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
