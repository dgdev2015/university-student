#include <stdio.h>

typedef enum
{
    INPUT = 1,
    DISPLAY,
    MOD,
    DELETE,
    SORT,
    EXIT
} Menu;

typedef enum
{
    CHINUP = 1,
    CHINDOWN,
    MATHUP,
    MATHDOWN,
    ENGUP,
    ENGDOWN,
    SUMUP,
    SUMDOWN
} Sort;

void show_menu();
void sort_menu();

int main()
{
    int menu;

    do
    {
        show_menu();
        scanf("%d", &menu);
        if (menu < INPUT || menu > EXIT)
        {
            continue;
        }
        switch ((Menu)menu)
        {
        case INPUT:
            printf("Select INPUT Command\n");
            break;
        case DISPLAY:
            printf("Select DISPLAY Command\n");
            break;
        case MOD:
            printf("Select MODIFY Command\n");
            break;
        case DELETE:
            printf("Select DELETE Command\n");
            break;
        case SORT:
            sort_menu();
            scanf("%d", &sort);
            if (sort < CHINUP || sort > SUMDOWN)
            {
                continue;
            }
            switch ((Sort)sort)
            {
            case CHINUP:
                printf("Sort by Chinese Score ASC\n");
                break;
            case CHINDOWN:
                printf("Sort by Chinese Score DESC\n");
                break;
            case MATHUP:
                printf("Sort by Math Score ASC\n");
                break;
            case MATHDOWN:
                printf("Sort by Math Score DESC\n");
                break;
            case ENGUP:
                printf("Sort by English Score ASC\n");
                break;
            case ENGDOWN:
                printf("Sort by English Score DESC\n");
                break;
            case SUMUP:
                printf("Sort by Total Score ASC\n");
                break;
            case SUMDOWN:
                printf("Sort by Total Score DESC\n");
                break;
            }
            break;
        }
    } while ((Menu)menu != EXIT);
    return 0;
}

void show_menu()
{
    printf("1.Input Student Info\n");
    printf("2.Show Student Info\n");
    printf("3.Modify Student Info\n");
    printf("4.Delete Student Info\n");
    printf("5.Sort Studetn Info By\n");
    printf("6.Exit\n");
    printf("Please Select number of Command>");
}

void sort_menu()
{
    printf("请选择排序方式\n");
    printf("1.按语文成绩升序排列\n");
    printf("2.按语文成绩降序排列\n");
    printf("3.按数学成绩升序排列\n");
    printf("4.按数学成绩降序排列\n");
    printf("5.按英语成绩升序排列\n");
    printf("6.按英语成绩降序排列\n");
    printf("7.按总成绩升序排列\n");
    printf("8.按总成绩降序排列\n");
}