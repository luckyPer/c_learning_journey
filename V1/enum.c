#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    enum color  {
        red = 1,
        blue
    } color;
    int favourite = 0;
    printf("input your favourite color : red: 1, blue: 2");
    scanf("%d", &favourite);
    switch(favourite)
    {
        case red:
            printf("red");
            break;
        case blue:
            printf("red");
            break;
        default:
            printf("none");
            break;
    }
    system("pause");
    return 0;
}
