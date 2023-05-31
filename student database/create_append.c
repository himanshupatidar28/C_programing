# include<stdio.h>
# include<stdlib.h>

void create(){
    student *s1;
    int n;
    printf("Create New Record File \n");
    printf("Enter No. of Students : ");
    scanf("%d", &n);
    s1 = (student*) calloc(n, sizeof(student));

    FILE *fp = fopen("data.txt", "w");

    for (int i = 0; i < n; i++)
    {
        s1[i].total = 0;

        printf("Enter Roll no : ");
        scanf("%d", &s1[i].roll_no);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s", s1[i].name);
        fflush(stdin);
        printf("Marks out of 100 \n");
        printf("Enter Marks of subject 1 : ");
        scanf("%d", &s1[i].sub1);
        fflush(stdin);
        printf("Enter Marks of subject 2 : ");
        scanf("%d", &s1[i].sub2);
        fflush(stdin);
        printf("Enter Marks of subject 3 : ");
        scanf("%d", &s1[i].sub3);
        fflush(stdin);
        printf("\n");

        s1[i].total = s1[i].sub1 + s1[i].sub2 + s1[i].sub3;
        s1[i].per = s1[i].total/3;
        fwrite(&s1[i], sizeof(student), 1, fp);
    }
    
    fclose(fp);
}

void append(){
    student *s1;
    int n;
    printf("Create New Record File \n");
    printf("Enter No. of Students : ");
    scanf("%d", &n);
    s1 = (student*) calloc(n, sizeof(student));

    FILE *fp = fopen("data.txt", "a");

    for (int i = 0; i < n; i++)
    {
        s1[i].total = 0;

        printf("Enter Roll no : ");
        scanf("%d", &s1[i].roll_no);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%[^\n]s", s1[i].name);
        fflush(stdin);
        printf("Marks out of 100 \n");
        printf("Enter Marks of subject 1 : ");
        scanf("%d", &s1[i].sub1);
        fflush(stdin);
        printf("Enter Marks of subject 2 : ");
        scanf("%d", &s1[i].sub2);
        fflush(stdin);
        printf("Enter Marks of subject 3 : ");
        scanf("%d", &s1[i].sub3);
        fflush(stdin);
        printf("\n");

        s1[i].total = s1[i].sub1 + s1[i].sub2 + s1[i].sub3;
        s1[i].per = s1[i].total/3;
        fwrite(&s1[i], sizeof(student), 1, fp);
    }
    
    fclose(fp);
}