# include<stdio.h>
# include<stdlib.h>
#include "./includes/test_fn.c"

void tests(){
    
    int opt;
    do
    {
        printf("\n");
        printf("---------------------------------------------------------\n");
        printf("\t\t\tMANAGE TESTS\t\t\t\n");
        printf("---------------------------------------------------------\n");

        printf("1 - Display \t\t 2 - Create\n");
        printf("3 - Delete\t\t 4 - Update\n");
        printf("0 - Back\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            test_dis();
            break;

        case 2:
            test_cre();
            break;

        case 3:
            test_del();
            break;

        case 4:
            test_up();
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