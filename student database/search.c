# include<stdio.h>
# include<stdlib.h>

void search(){
    
    student s1;
    int search;
    printf("Search Records ( Roll no ) --\n");
    printf("Enter Roll no :- ");
    scanf("%d", &search);
    printf("\n");

    FILE *fp = fopen("data.txt", "r");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-10s%-20s%-10s%-10s%-10s%-10s%20s %%\n","Roll no","Name","subject1","subject2","subject3","Total","percentage");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.roll_no == search)
        {
            printf("%-10d%-20s%-10d%-10d%-10d%-10f%20f %%\n", s1.roll_no, s1.name, s1.sub1, s1.sub2, s1.sub3, s1.total, s1.per);
        }   
    }
    printf("\n");
    printf("Showing records found \n");
    printf("\n");
    fclose(fp);
}