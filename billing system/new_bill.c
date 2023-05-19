#include <stdio.h>
#include <stdlib.h>
#include "products.c"

void new_bill()
{
    products();
    printf("\n");

    printf("---- GENRATING BILL ----\n");
    int n_products;
    printf("Enter no of product purchased :\n");
    scanf("%d", &n_products);
    if (n_products == 0)
    {
        printf("invalid input try again!!!");
    }
    else
    {

        int p_itemid[n_products];
        int quantity[n_products];
        int total[n_products];

        for (int j = 0; j < n_products; j++)
        {
            printf("Enter item ID :\n");
            scanf("%d", &p_itemid[j]);
            printf("Enter Quantity :\n");
            scanf("%d", &quantity[j]);
        }

        printf("\n");
        printf("                   XYZ SHOPPING MARKET                \n");
        printf("                     PRINTING BILL                    \n");
        printf("------------------------------------------------------\n");
        printf(" ID   ITEMS                   |        PRICE        \n");

        for (int a = 0; a < n_products; a++)
        {
            total[a] = item[p_itemid[a]].price * quantity[a];
            printf(" %d    %s           |        %d         \n", p_itemid[a], item[p_itemid[a]].item, total[a]);
        }
        // calculating totalamount
        int totalamount = 0;
        int length = sizeof(total) / sizeof(total[0]);
        for (int i = 0; i < length; i++)
        {
            totalamount += total[i];
        }

        printf("------------------------------------------------------\n");
        printf(" TOTAL (included GST) : %d  \n", totalamount);
        printf("------------------------------------------------------\n");
        // geting records
        FILE *record = fopen("records.txt", "a");
        fprintf(record,"                     PRINTING BILL                    \n------------------------------------------------------\n ID   ITEMS                   |        PRICE        \n");
        for (int a = 0; a < n_products; a++)
        {
            fprintf(record," %d    %s           |        %d         \n", p_itemid[a], item[p_itemid[a]].item, total[a]);
        }
        fprintf(record,"TOTAL (included GST) : %d  \n", totalamount);
        fprintf(record,"------------------------------------------------------\n\n");
        fclose(record);
        printf("Record Succesfully Added....");
    }
}
