/*
Author: Himanshu Patidar
Purpose: guess number game project
Date: 06 May 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number, guess, nguesses = 1;
    ;
    // for genrating random number
    srand(time(0));
    number = (rand() % 10) + 1;

    // keep running loop until number guessed
    printf("              WELCOME TO GAME                  \n");
    printf("           GUESS THE NUMBER GAME               \n");
    printf("-----------------------------------------------\n");
    printf("Note : You have 3 attempts to guess the number.\n");
    printf("-----------------------------------------------\n\n");
    printf("Guess the number between 1 to 10\n\n");

    do
    {
        if (nguesses <= 3)
        {
            printf("Enter the number : ");
            scanf("%d", &guess);
            if (guess > number)
            {
                printf("guess lower number..\n\n");
            }
            else if (guess < number)
            {
                printf("guess higher number..\n\n");
            }
            else if (guess = number)
            {
                printf("you Won a match !!..\n");
            }
        }

        else
        {
            printf("Try Again, You Failed..\n");
        }
        nguesses++;
    } while (nguesses <=4 && number != guess);

    return 0;
}