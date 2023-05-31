# include<stdio.h>
# include<stdlib.h>
# include"datatype.c"
# include"search.c"
# include"create_append.c"
# include"display_sort.c"
# include"update_delete.c"

int main(){
    int opt;
    printf("---------------------------------------------------------\n");
    printf("|\t\tWELCOME TO STUDENT DATABASE\t\t|\n");
    printf("---------------------------------------------------------\n\n");
    do
    {
        printf("1 - CREATE \t\t\t\t 2 - DELETE\n");
        printf("3 - UPDATE \t\t\t\t 4 - APPEND\n");
        printf("5 - SEARCH \t\t\t\t 6 - DISPLAY\n");
        printf("7 - SORT BY \t\t\t\t 0 - EXIT\n");
        printf("Select the Operation : ");
        scanf("%d", &opt);
        printf("\n");

        switch (opt)
        {
        case 1:
            create();
            break;
        case 2:
            delete();
            break;
        case 3:
            update();
            break;
        case 4:
            append();
            break;
        case 5:
            search();
            break;
        case 6:
            display();
            break;
        case 7:
            sort();
            break;
        case 0:
            break;
        
        default:
            printf("--------------- Invalid Input, Try Again --------------\n");
        }
    } while (opt != 0);
    
    return 0;
}