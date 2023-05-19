# include<stdio.h>
# include<stdlib.h>
# include"new_bill.c"
# include"records.c"

int main(){
    
    int menu;
    printf("\n");
    printf("---------------- WELCOME TO YOUR BILLING SYSTEM ----------------\n\n");
    printf("1. New Bill\n");
    printf("2. Products List\n");
    printf("3. Previous Bills Records\n");
    printf("4. Exit\n");
    printf("\nSelect Option : ");
    scanf("%d", &menu);
    printf("\n");

    if (menu == 1)
    {
        new_bill();
        main();
    }
    else if (menu == 2)
    {
        products();
        main();
    }
    else if (menu == 3)
    {
        records();
        main();
    }
    else if (menu == 4)
    {
        printf("Exit\n");
    }
    else{
        printf("Invalid input\n");
        main();
    }

    return 0;
}