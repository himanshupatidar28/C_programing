#include <stdio.h>
#include <stdlib.h>

void display()
{
    student s1;
    printf("Displaying All Records --\n\n");
    FILE *fp = fopen("data.txt", "r");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-10s%-20s%-10s%-10s%-10s%-10s%20s %%\n","Roll no","Name","subject1","subject2","subject3","Total","percentage");
    printf("-------------------------------------------------------------------------------------------\n");

    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf("%-10d%-20s%-10d%-10d%-10d%-10f%20f %%\n", s1.roll_no, s1.name, s1.sub1, s1.sub2, s1.sub3, s1.total, s1.per);
    }
    printf("\n");
    fclose(fp);
}

void sort()
{

    student *s, s1;
    printf("Sorting All Records by --\n\n");
    FILE *fp = fopen("data.txt", "r");
    // no of records
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student *)calloc(n, sizeof(student));

    rewind(fp);
    // store all  record in s
    for (int i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, fp);
    }
    // sort data in s
    int opt;
    printf("1 - Rank\n2 - Roll no (asc)\n3 - Subject1 (desc)\n4 - Subject2 (desc)\n5 - Subject3 (desc)\nSelect option : ");
    scanf("%d", &opt);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            switch (opt)
            {
            case 1:
                if (s[i].total < s[j].total)
                {
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
                break;
            case 2:
                if (s[i].roll_no > s[j].roll_no)
                {
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
                break;
            case 3:
                if (s[i].sub1 < s[j].sub1)
                {
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
                break;
            case 4:
                if (s[i].sub2 < s[j].sub2)
                {
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
                break;
            case 5:
                if (s[i].sub3 < s[j].sub3)
                {
                    s1 = s[i];
                    s[i] = s[j];
                    s[j] = s1;
                }
                break;

            default:
                break;
            }
        }
    }

    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-10s%-20s%-10s%-10s%-10s%-10s%20s %%\n", "Roll no", "Name", "subject1", "subject2", "subject3", "Total", "percentage");
    printf("-------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-10d%-20s%-10d%-10d%-10d%-10f%20f %%\n", s[i].roll_no, s[i].name, s[i].sub1, s[i].sub2, s[i].sub3, s[i].total, s[i].per);
    }

    printf("\n");
    fclose(fp);
}