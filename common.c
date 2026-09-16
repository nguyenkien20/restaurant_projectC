#include <stdio.h>
#include "common.h"

// this function just using for integer input 
int integer_input(const char *message, const int min_value, const int max_value)
{
    int value = 0;
    int get_character = 0;
    printf("%s", message);
    while (scanf("%d", &value) != 1 || value < min_value || value > max_value)
    {
        while ((get_character = getchar()) != '\n' && get_character != EOF) // getchar return an int -> check if EOF or newline
            ;
        printf("Please enter number from %d to %d: \n", min_value, max_value);
        printf("%s", message);
    }
    while ((get_character = getchar()) != '\n' && get_character != EOF) 
        ;
    return value;
}