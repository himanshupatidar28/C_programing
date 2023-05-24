# include<stdio.h>
# include<stdlib.h>


int option;
int nav(){
    printf("1. Log-in \n");
    printf("2. Sign-up \n");
    printf("3. Exit\n");
    printf("Select Operation : ");
    scanf("%d", &option);
    printf("\n");
    if (option == 1)
    {
        login();
        nav();
    }
    else if (option == 2)
    {
        signup();
        nav();
    }
    else if (option == 3)
    {
        
    }
    else{
        printf("Invalid Input !!..\n");
        nav();
    }
    
    return 0;
}