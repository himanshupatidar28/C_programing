#include <stdio.h>
#include <stdlib.h>

void records()
{
    printf("\n");
    FILE *record = fopen("records.txt", "r");
    char fetchline[60];
    while (fgets(fetchline, 60, record))
    {
        printf("%s", fetchline);
    }
    fclose(record);
    printf("\n");
}