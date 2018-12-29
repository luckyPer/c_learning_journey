#include <stdio.h>
#include <stdlib.h>

typedef int COUNT;
COUNT i,j;

struct Person
{
    int num;
    char name[10];
    char job;
    union {
        int class;
        char position[10];
    } category;
}person[2];


void main()
{
    int i = 2;
    for(i = 0; i<2 ;i++)
    {
        scanf("%d %s %c", &person[i].num, &person[i].name, &person[i].job);
        if(person[i].job == 's')
        {
            scanf("%d", &person[i].category.class);
        } 
        else if(person[i].job == 't')
        {            
            scanf("%s", &person[i].category.position);
        }
        else 
        {
            printf("input error");
        }
    }

    for(i = 0; i<2 ;i++) 
    {
        if(person[i].job == 's')
        {
            printf("%d, %s, %c, %d\n", person[i].num, person[i].name, person[i].job, person[i].category.class);
        } 
        else if(person[i].job == 't')
        {            
            printf("%d, %s, %c, %s\n", person[i].num, person[i].name, person[i].job,  person[i].category.position);
        }
    }

    system("pause");
}