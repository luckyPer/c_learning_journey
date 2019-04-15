#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN sizeof(struct linkList)
typedef int ElementType;

//静态链表
struct staticlinkList 
{
    ElementType Data;
    int next;   //下一个元素的数组下标
};  //以next值是 -1 作为结束 ,代表指向Null