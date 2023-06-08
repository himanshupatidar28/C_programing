#include <stdio.h>
#include <stdlib.h>

void que_add()
{
    question *q;
    int n;
    printf("\n----------- Create New Questions -----------\n");
    printf("Enter No. of Questions : ");
    scanf("%d", &n);
    q = (question *)calloc(n, sizeof(question));

    FILE *fp = fopen("./data/questions.txt", "a");
    FILE *fpr = fopen("./data/questions.txt", "r");
    fseek(fpr, 0, SEEK_END);
    int id = ftell(fpr) / sizeof(question);
    id++;
    for (int i = 0; i < n; i++)
    {
        q[i].que_id = id;
        fflush(stdin);
        printf("Write Question : ");
        scanf("%[^\n]s", q[i].que_text);
        fflush(stdin);
        printf("Write Option1 : ");
        scanf("%[^\n]s", q[i].que_ch1);
        fflush(stdin);
        printf("Write Option2 : ");
        scanf("%[^\n]s", q[i].que_ch2);
        fflush(stdin);
        printf("Write Option3 : ");
        scanf("%[^\n]s", q[i].que_ch3);
        fflush(stdin);
        printf("Write Option4 : ");
        scanf("%[^\n]s", q[i].que_ch4);
        fflush(stdin);
        printf("Write Answer : ");
        scanf("%d", &q[i].que_ans);
        printf("\n");
        fwrite(&q[i], sizeof(question), 1, fp);
    

        id++;
    }
    fclose(fpr);
    fclose(fp);
}

void que_dis()
{
    question q;
    printf("\n----------- Display All Questions -----------\n\n");
    FILE *fp = fopen("./data/questions.txt", "r");

    while (fread(&q, sizeof(question), 1, fp))
    {
        printf("ID : %d\n", q.que_id);
        printf("Question : %s\n", q.que_text);
        printf("option1 - %s \toption2 - %s\n", q.que_ch1, q.que_ch2);
        printf("option3 - %s \toption4 - %s\n", q.que_ch3, q.que_ch4);
        printf("Answer No : %d\n", q.que_ans);
        printf("\n");
    }

    fclose(fp);
}

void que_up()
{
    question q;
    int search;
    int found = 0;
    printf("\n----------- Update Questions -----------\n");
    printf("search with question id : ");
    scanf("%d", &search);

    FILE *fp = fopen("./data/questions.txt", "r");
    FILE *fptemp = fopen("./data/temp.txt", "w");

    while (fread(&q, sizeof(question), 1, fp))
    {
        if (q.que_id == search)
        {
            found = 1;
            printf("Enter Question ID : ");
            scanf("%d", &q.que_id);
            fflush(stdin);
            printf("Write Question : ");
            scanf("%[^\n]s", q.que_text);
            fflush(stdin);
            printf("Write Option1 : ");
            scanf("%[^\n]s", q.que_ch1);
            fflush(stdin);
            printf("Write Option2 : ");
            scanf("%[^\n]s", q.que_ch2);
            fflush(stdin);
            printf("Write Option3 : ");
            scanf("%[^\n]s", q.que_ch3);
            fflush(stdin);
            printf("Write Option4 : ");
            scanf("%[^\n]s", q.que_ch4);
            fflush(stdin);
            printf("Write Answer : ");
            scanf("%d", &q.que_ans);

            fwrite(&q, sizeof(question), 1, fptemp);
        }
    }
    fclose(fptemp);
    fclose(fp);
    if (found)
    {
        fptemp = fopen("./data/temp.txt", "r");
        fp = fopen("./data/questions.txt", "w");
        while (fread(&q, sizeof(question),1, fptemp))
        {
            fwrite(&q, sizeof(question),1, fp);
        }
        fclose(fp);
        fclose(fptemp);
        printf("record updated succesfully..\n");
    }
    else{
        printf("record not found\n");
    }
    
    printf("\n");

}

void que_del(){
    question q;
    int search;
    int found = 0;
    printf("----------- Delete Question ----------- \n");
    printf("Search Question with ID : ");
    scanf("%d", &search);
    printf("\n");

    FILE *fp = fopen("./data/questions.txt", "r");
    FILE *fptemp = fopen("./data/temp.txt", "w");
    while (fread(&q, sizeof(question), 1, fp))
    {
        if (q.que_id == search)
        {
            found = 1;
        }
        else{
        fwrite(&q, sizeof(question), 1, fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
    if (found)
    {
        fptemp = fopen("./data/temp.txt", "r");
        fp = fopen("./data/questions.txt", "w");

        while (fread(&q, sizeof(question),1, fptemp))
        {
            fwrite(&q, sizeof(question),1, fp);
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
    

