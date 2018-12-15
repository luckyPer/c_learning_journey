#include <stdio.h>
#include <stdlib.h>

int GetTotalScore(int *score)
{  
    int sum = 0;
    for(int i = 0; i < sizeof(score)/sizeof(score[0]); i++)
    {      
        sum += score[i];
    }
    return sum;
}

int SortScore()
{
    int score[10]={67,98,75,63,82,79,81,91,66,84};
    for(int i = 9; i >=0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(score[i] < score[j])
            {
                int temp = 0;
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
            printf("%d \n", score[i]);  
    }
}



int main()
{
    SortScore();
    int score[10]={67,98,75,63,82,79,81,91,66,84};
    int totalscore = GetTotalScore(score);
    int avgscore = totalscore/10;
    printf("total socres is %d", totalscore);
    printf("avg socres is %d", avgscore);
    system("pause");
    return 0;
}