#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct users
    {
        char name_f[30];
        char name_l[30];
        char email[30];
        char password[30];
        char phone[11];
    };
    struct users user;

int signup()
{

    char con_password[30];
    int i;
    char ch;

    printf("New Registration --\n");
    printf("Please, Enter your details --\n");
    printf("Enter your First Name :\t");
    scanf("%s", &user.name_f);
    getchar();
    printf("Enter your Last Name :\t");
    scanf("%s", &user.name_l);
    getchar();
    printf("Enter your Email :\t");
    scanf("%s", &user.email);
    getchar();
    printf("Enter your Phone no :\t");
    scanf("%s", &user.phone);
    getchar();
    printf("Create password :\t");
    scanf("%s", &user.password);
    getchar();
    printf("Confirm password :\t");
    scanf("%s", &con_password);
    getchar();

    // file storing data

    for (int i = 0; i < strlen(user.password); i++)
    {
        if (con_password[i] == user.password[i])
        {
            if (strlen(con_password) == (i + 1))
            {
                FILE *users = fopen("user.txt", "a");
                fwrite(&user, sizeof(user), 1, users);
                fclose(users);
                printf("Registration successfully..\n\n");
            }
        }
        else
        {
            printf("Password does not matched..\n");
            break;
        }
    }

    return 0;
}