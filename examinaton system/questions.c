#include <stdio.h>
#include <stdlib.h>
#include "./includes/que_fn.c"

void questions()
{
    int opt;
    do
    {
        printf("\n");
        printf("---------------------------------------------------------\n");
        printf("\t\t\tMANAGE QUESTIONS\t\t\t\n");
        printf("---------------------------------------------------------\n");

        printf("1 - Display\t\t 2 - Add\n");
        printf("3 - Delete\t\t 4 - Update\n");
        printf("0 - Back\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            que_dis();
            break;

        case 2:
            que_add();
            break;

        case 3:
            que_del();
            break;

        case 4:
            que_up();
            break;

        default:
            if (opt != 0)
            {
                printf("Invalid Input, Try Again ...\n");
            }
            break;
        }

    } while (opt != 0);
}