#include <stdio.h>
#include <stdlib.h>

void can_profile(char email[], char pass[])
{
    user candidate;
    int opt;
    int found = 0;
    do
    {
        printf("\n");
        printf("\n------- Candidate Profile -------\n");
        FILE *fp = fopen("./data/candidates.txt", "r");
        while (fread(&candidate, sizeof(user), 1, fp))
        {
            if (!strcmp(email, candidate.email))
            {
                printf("Name : %s\n", candidate.name);
                printf("Email : %s\n", candidate.email);
                printf("Password : %s\n", candidate.password);
            }
        }
        fclose(fp);
        printf("\n0 - Back\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
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

void can_tests(char email[20], char name[30])
{
    test test;
    question question;
    master attend;
    int answer;

    printf("\n------- Tests -------\n");
    FILE *fp = fopen("./data/tests.txt", "r");
    FILE *fpq = fopen("./data/questions.txt", "r");
    FILE *fpm = fopen("./data/master.txt", "a");
    while (fread(&test, sizeof(test), 1, fp))
    {
        printf("%d \t %s\n", test.test_id, test.test_desc);
    }
    printf("\nSelect Test to Attend : ");
    scanf("%d", &attend.a_testid);
    fflush(stdin);
    printf("\n");

    strcpy(attend.email, email);
    strcpy(attend.name, name);
    attend.total = 0;
    while (fread(&question, sizeof(question), 1, fpq))
    {
        if (question.que_id == test.id_que1 || question.que_id == test.id_que2 || question.que_id == test.id_que3 || question.que_id == test.id_que4 || question.que_id == test.id_que5)
        {
            printf("ID : %d\n", question.que_id);
            printf("Question : %s\n", question.que_text);
            printf("option1 - %s \toption2 - %s\n", question.que_ch1, question.que_ch2);
            printf("option3 - %s \toption4 - %s\n", question.que_ch3, question.que_ch4);
            printf("Answer No : ");
            scanf("%d", &answer);
            fflush(stdin);
            if (answer == question.que_ans)
            {
                attend.total += 4;
            }
            
            printf("\n");
        }
    }
    fwrite(&attend, sizeof(master), 1, fpm);
    fclose(fpm);
    fclose(fpq);
    fclose(fp);
}


void can_result(char email[20]){
    master attend;
    FILE *fp = fopen("./data/master.txt", "r");
    printf("%s \t %s\n", "test id", "total marks");
    while (fread(&attend, sizeof(master), 1, fp))
    {
        if (!strcmp(email, attend.email))
        {
            printf("%d \t %d\n", attend.a_testid, attend.total);
        }
        
    }
    
    fclose(fp);
}