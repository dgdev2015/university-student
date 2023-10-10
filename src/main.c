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

void show_menu();

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
            printf("Select SORT Command\n");
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