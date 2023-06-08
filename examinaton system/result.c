#include <stdio.h>
#include <stdlib.h>

void user_dis()
{
    user candidate;
    printf("\n-------  -------\n");
    FILE *fp = fopen("./data/candidates.txt", "r");
    while (fread(&candidate, sizeof(user), 1, fp))
    {
        printf("ID : %d\n", candidate.user_id);
        printf("Name : %s\n", candidate.name);
        printf("Email : %s\n", candidate.email);
        printf("pass : %s\n", candidate.password);
    }
    fclose(fp);
}

void dis_result(){
    master attend;
    FILE *fp = fopen("./data/master.txt", "r");
    printf("%s \t %s \t %s \t %s\n", "Name", "email", "test id", "marks");
    while (fread(&attend, sizeof(master), 1, fp))
    {
        printf("%s \t %s \t %d \t %d\n", attend.name, attend.email, attend.a_testid, attend.total);
        
    }
    
    fclose(fp);
}

void result()
{

    int opt;
    do
    {
        printf("\n");
        printf("----------- Candidates & Results ----------\n");

        printf("1 - Candidates\t\t 2 - Results\n");
        printf("0 - Back\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            user_dis();
            break;

        case 2:
            dis_result();
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