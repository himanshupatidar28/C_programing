#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/datatype.c"
#include "questions.c"
#include "tests.c"
#include "./includes/candidates.c"
#include "result.c"

void admin()
{
    char username[20];
    char password[20];

    printf("\nLogin As Admin :-\n");
    printf("Username : ");
    scanf("%s", username);
    fflush(stdin);
    printf("Password : ");
    scanf("%s", password);
    fflush(stdin);
    if (!strcmp(username, "admin"))
    {
        if (!strcmp(password, "admin@123"))
        {
            int opt;
            do
            {
                printf("\n");
                printf("---------------------------------------------------------\n");
                printf("|\t\t\tADMIN DASHBOARD\t\t\t|\n");
                printf("---------------------------------------------------------\n");

                printf("1 - Manage Questions\t\t 2 - Manage Tests\n");
                printf("3 - Candidates & Results\n");
                printf("0 - Back\n");
                printf("\nEnter Your Choice : ");
                scanf("%d", &opt);
                switch (opt)
                {
                case 1:
                    questions();
                    break;

                case 2:
                    tests();
                    break;

                case 3:
                    result();
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
        else
        {
            printf("\nIncorrect password\n");
        }
    }
    else
    {
        printf("\nIncorrect username\n");
    }
}

void signup()
{
    user candidate;
    char pass[20];
    int id = 0;
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("|\t\t\tNEW CANDIDATE REGISTRATION\t\t\t|\n");
    printf("-------------------------------------------------------------------------\n");

    FILE *fp = fopen("./data/candidates.txt", "a");
    FILE *fpr = fopen("./data/candidates.txt", "r");
    fseek(fpr, 0, SEEK_END);
    id = ftell(fpr) / sizeof(question);

    id++;
    candidate.user_id = id;
    fflush(stdin);
    printf("Name : ");
    scanf("%[^\n]s", candidate.name);
    fflush(stdin);
    printf("E-mail : ");
    scanf("%s", candidate.email);
    fflush(stdin);
    printf("Password : ");
    scanf("%s", candidate.password);
    fflush(stdin);
    printf("Confirm Password : ");
    scanf("%s", pass);
    fflush(stdin);

    if (!strcmp(candidate.password, pass))
    {
        fwrite(&candidate, sizeof(user), 1, fp);
        printf("\nRegistration Successfull !!\n");
    }
    else
    {
        printf("\nPassword Not Match ...\n");
    }

    fclose(fpr);
    fclose(fp);
}

void candidate()
{
    user candidate;
    char email[30];
    char pass[20];
    int opt;
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("|\t\t\tCANDIDATE LOGIN\t\t\t|\n");
    printf("---------------------------------------------------------\n");
    printf("E-mail : ");
    scanf("%s", &email);
    getc(stdin);
    printf("Password : ");
    scanf("%s", &pass);
    getc(stdin);

    FILE *fp = fopen("./data/candidates.txt", "r");
    while (fread(&candidate, sizeof(user), 1, fp))
    {
        if (!strcmp(email, candidate.email) && !strcmp(pass, candidate.password))
        {
            printf("\n");
            printf("---------------------------------------------------------\n");
            printf("|\t\t\tCANDIDATE DASHBOARD\t\t\t|\n");
            printf("---------------------------------------------------------\n");

            printf("1 - Profile\t\t 2 - Tests\n");
            printf("3 - Results\n");
            printf("0 - Back\n");
            printf("\nEnter Your Choice : ");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                can_profile(email, pass);
                break;

            case 2:
                can_tests(email, candidate.name);
                break;

            case 3:
                can_result(email);
                break;

            default:
                if (opt != 0)
                {
                    printf("Invalid Input, Try Again ...\n");
                }
                break;
            }
        }
        else
        {
            printf("Invalid Input, Try Again ...\n");
        }
    }
    fclose(fp);
}

int main()
{
    int opt;
    do
    {
        printf("\n");
        printf("-------------------------------------------------------------------------\n");
        printf("|\t\t\tWELCOME TO EXAMINATION SYSTEM\t\t\t|\n");
        printf("-------------------------------------------------------------------------\n");

        printf("1 - Log-in as Admin\n");
        printf("2 - Log-in as Candidate\n");
        printf("3 - Register as Candidate\n");
        printf("0 - Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            admin();
            break;

        case 2:
            candidate();
            break;

        case 3:
            signup();
            break;

        default:
            if (opt != 0)
            {
                printf("Invalid Input, Try Again ...\n");
            }
            break;
        }

    } while (opt != 0);

    return 0;
}