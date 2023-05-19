# include<stdio.h>
# include<stdlib.h>

// product and their prices
    struct products
    {
        char item[20];
        int price;
    };

    struct products item[10] = {{"Sugar        ",110},
                                {"Tuar Dal     ",80},
                                {"Magic cookies",10},
                                {"Apple        ",100},
                                {"Mango        ",40},
                                {"Butter       ",456},
                                {"Curd         ",60},
                                {"T-shirt      ",110},
                                {"Toothbrush   ",15},
                                {"Toothpaste   ",20}};


void products()
{
    printf("--------------- PRODUCTS MENU --------------\n");
    // printing products data
    printf("________________________________________________________\n");
    printf(" ID       ITEMS                          PRICE         \n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d   %s           |        %d         \n", i, item[i].item, item[i].price);
    }
    
    printf("\n");
}
