#include <stdio.h>
#include <stdlib.h>
#include "signup.c"

void display(struct users userdata){
    printf("Name : %s %s\n", userdata.name_f, userdata.name_l);
    printf("Email : %s\n", userdata.email);
    printf("Phone : %s\n", userdata.phone);
    printf("Password : %s\n", userdata.password);
    printf("\n");



}

int login()
{
    char email[30], pass[30];
    struct users userdata;
    FILE *users = fopen("user.txt", "r");
    while (fread(&userdata, sizeof(userdata), 1, users))
    {
        printf("Log-In here ---\n");
        printf("Enter Your Email :\t");
        scanf("%s", &email);
        printf("Enter Password :\t");
        scanf("%s", &pass);
        for (int i = 0; i < 30; i++)
        {
            if (!strcmp(userdata.email, email))
            {
                if (!strcmp(userdata.password, pass))
                {
                    if ((i + 1) == 30)
                    {
                        printf("\nLogin successfully..\nWelcome %s %s\n\n", userdata.name_f, userdata.name_l);
                        display(userdata);
                    }
                }
            }
            else
            {
                printf("wrong credentials pleasetry again...\n");
            }
        }
    }
    return 0;
}