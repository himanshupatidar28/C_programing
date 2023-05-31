#include <stdio.h>
#include <stdlib.h>

void update()
{
    student s1;
    int search;
    int found = 0;
    printf("--- Update Record --- \n");
    printf("Search Records ( Roll no ) --\n");
    printf("Enter Roll no :- ");
    scanf("%d", &search);
    printf("\n");

    FILE *fp = fopen("data.txt", "r");
    FILE *fptemp = fopen("temp.txt", "w");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.roll_no == search)
        {
            found = 1;
            s1.total = 0;

            printf("Enter Update Record --- \n");
            printf("Enter Roll no : ");
            scanf("%d", &s1.roll_no);
            fflush(stdin);
            printf("Enter Name : ");
            scanf("%[^\n]s", s1.name);
            fflush(stdin);
            printf("Marks out of 100 \n");
            printf("Enter Marks of subject 1 : ");
            scanf("%d", &s1.sub1);
            fflush(stdin);
            printf("Enter Marks of subject 2 : ");
            scanf("%d", &s1.sub2);
            fflush(stdin);
            printf("Enter Marks of subject 3 : ");
            scanf("%d", &s1.sub3);
            fflush(stdin);
            printf("\n");

            s1.total = s1.sub1 + s1.sub2 + s1.sub3;
            s1.per = s1.total / 3;
        }
        fwrite(&s1, sizeof(student), 1, fptemp);
    }
    fclose(fp);
    fclose(fptemp);
    if (found)
    {
        fptemp = fopen("temp.txt", "r");
        fp = fopen("data.txt", "w");

        while (fread(&s1, sizeof(student),1, fptemp))
        {
            fwrite(&s1, sizeof(student),1, fp);
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

void delete()
{
    student s1;
    int search;
    int found = 0;
    printf("--- Delete Record --- \n");
    printf("Search Records ( Roll no ) --\n");
    printf("Enter Roll no :- ");
    scanf("%d", &search);
    printf("\n");

    FILE *fp = fopen("data.txt", "r");
    FILE *fptemp = fopen("temp.txt", "w");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.roll_no == search)
        {
            found = 1;
        }
        else{
        fwrite(&s1, sizeof(student), 1, fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
    if (found)
    {
        fptemp = fopen("temp.txt", "r");
        fp = fopen("data.txt", "w");

        while (fread(&s1, sizeof(student),1, fptemp))
        {
            fwrite(&s1, sizeof(student),1, fp);
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