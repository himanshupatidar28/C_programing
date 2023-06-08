#include <stdio.h>
#include <stdlib.h>

void test_cre()
{
    test t1;
    int n;
    printf("\n----------- Create New Test -----------\n");

    FILE *fp = fopen("./data/tests.txt", "a");

    printf("Enter Test ID : ");
    scanf("%d", &t1.test_id);
    fflush(stdin);
    printf("Enter Test Desc : ");
    scanf("%s", t1.test_desc);
    fflush(stdin);
    printf("ADD QUESTIONS TO TEST : ----\n");
    printf("Enter Question 1 ID : ");
    scanf("%d", &t1.id_que1);
    fflush(stdin);
    printf("Enter Question 2 ID : ");
    scanf("%d", &t1.id_que2);
    fflush(stdin);
    printf("Enter Question 3 ID : ");
    scanf("%d", &t1.id_que3);
    fflush(stdin);
    printf("Enter Question 4 ID : ");
    scanf("%d", &t1.id_que4);
    fflush(stdin);
    printf("Enter Question 5 ID : ");
    scanf("%d", &t1.id_que5);
    fflush(stdin);

    fwrite(&t1, sizeof(test), 1, fp);

    fclose(fp);
}

void test_dis()
{
    test t1;
    printf("\n----------- Display All Tests -----------\n\n");
    FILE *fp = fopen("./data/tests.txt", "r");

    while (fread(&t1, sizeof(test), 1, fp))
    {
        printf("ID : %d\n", t1.test_id);
        printf("Test tittle : %s\n", t1.test_desc);
        printf("question1 id - %d \tquestion2 id - %d\n", t1.id_que1, t1.id_que2);
        printf("question3 id - %d \tquestion4 id - %d\n", t1.id_que3, t1.id_que4);
        printf("question5 id - %d\n", t1.id_que5);
        printf("\n");
    }

    fclose(fp);
}

void test_up()
{
    test t1;
    int search;
    int found = 0;
    printf("\n----------- Update Test -----------\n");
    printf("search with Test id : ");
    scanf("%d", &search);

    FILE *fp = fopen("./data/tests.txt", "r");
    FILE *fptemp = fopen("./data/temp.txt", "w");

    while (fread(&t1, sizeof(test), 1, fp))
    {
        if (t1.test_id == search)
        {
            found = 1;
            printf("Enter Test ID : ");
            scanf("%d", &t1.test_id);
            fflush(stdin);
            printf("Enter Test Desc : ");
            scanf("%s", t1.test_desc);
            fflush(stdin);
            printf("ADD QUESTIONS TO TEST : ----\n");
            printf("Enter Question 1 ID : ");
            scanf("%d", &t1.id_que1);
            fflush(stdin);
            printf("Enter Question 2 ID : ");
            scanf("%d", &t1.id_que2);
            fflush(stdin);
            printf("Enter Question 3 ID : ");
            scanf("%d", &t1.id_que3);
            fflush(stdin);
            printf("Enter Question 4 ID : ");
            scanf("%d", &t1.id_que4);
            fflush(stdin);
            printf("Enter Question 5 ID : ");
            scanf("%d", &t1.id_que5);
            fflush(stdin);

            fwrite(&t1, sizeof(test), 1, fptemp);
        }
    }
    fclose(fptemp);
    fclose(fp);
    if (found)
    {
        fptemp = fopen("./data/temp.txt", "r");
        fp = fopen("./data/tests.txt", "w");
        while (fread(&t1, sizeof(test), 1, fptemp))
        {
            fwrite(&t1, sizeof(test), 1, fp);
        }
        fclose(fp);
        fclose(fptemp);
        printf("record updated succesfully..\n");
    }
    else
    {
        printf("record not found\n");
    }

    printf("\n");
}

void test_del()
{
        test t1;
        int search;
        int found = 0;
        printf("----------- Delete Test ----------- \n");
        printf("Search Test with ID : ");
        scanf("%d", &search);
        printf("\n");

        FILE *fp = fopen("./data/tests.txt", "r");
        FILE *fptemp = fopen("./data/temp.txt", "w");
        while (fread(&t1, sizeof(test), 1, fp))
        {
            if (t1.test_id == search)
            {
                found = 1;
            }
            else{
            fwrite(&t1, sizeof(test), 1, fptemp);
            }
        }
        fclose(fp);
        fclose(fptemp);
        if (found)
        {
            fptemp = fopen("./data/temp.txt", "r");
            fp = fopen("./data/tests.txt", "w");

            while (fread(&t1, sizeof(test),1, fptemp))
            {
                fwrite(&t1, sizeof(test),1, fp);
            }

            fclose(fp);
            fclose(fptemp);
            printf("record deleted succesfully..\n");
        }
        else{
            printf("record not found\n");
        }

        printf("\n");
}
