#include <stdio.h>
#include <string.h>
#include "app_state.h"
#include "config.h"
state_t main_board(void)
{
    char role[MAX_CHAR];
    printf("---------------------------------\n");
    printf("Welcome to the HifV restaurant!\n");
    printf("---------------------------------");
    printf("\n-----YOU ARE?-----\n");
    printf("1. Admin        --> admin\n");
    printf("2. Customer     --> customer\n");
    printf("3. Exit         --> exit\n");
    printf("Enter your option here: \n");
    scanf("%10s", role);
    if (strcmp(role, "admin") == 0)
    {
        return STATE_ADMIN;
    }
    else if ((strcmp(role, "customer") == 0))
    {
        return STATE_CUSTOMER;
    }
    else if (strcmp(role, "exit") == 0)
    {
        return STATE_EXIT;
    }
    else
    {
        printf("---------------------------------");
        printf("---PLEASE TRY AGAIN AND AGAIN!---\n");
        printf("---------------------------------");
        return STATE_HOME;
    }
}