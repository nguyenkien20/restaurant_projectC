#include <stdio.h>
#include "common.h"

// this function just using for integer input 
int integer_input(const char *message)
{
    int value = 0;
    int character_check = 0;
    printf("%s\n", message);
    while (scanf("%d", &value) != 1)
    {
        while ((character_check = getchar()) != '\n' && character_check != EOF) // getchar return an int -> check if EOF or newline
            ;
        printf("Please enter again: \n");
        printf("%s", message);
    }
    while ((character_check = getchar()) != '\n' && character_check != EOF) 
        ;
    return value;
}