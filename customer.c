#include <stdio.h>
#include "customer.h"

state_t customerPanel(void)
{
    unsigned int choose1 = 0;
    printf("\n--------------------------------\n");
    printf("---WELCOME TO CUSTOMER PANEL!---\n");
    printf("--------------------------------\n");
    printf("1. Sign in?\n");
    printf("2. Create a new customer account!\n");
    printf("3. Exit to main board\n");
    printf("--------------------------\n");
    printf("Enter your choice:\n");
    while (scanf("%u", &choose1) != 1 || choose1 < 1 || choose1 > 3)
    {
        printf("Please enter value form 1 to 3!!: \n");
        while (getchar() != '\n')
            ;
    }
    switch (choose1)
    {
    case 1:
        customer_login();
        printf("Login succesfully!!!\n");
        return STATE_CUSTOMER_MENU;

    case 2:
        customer_create_account();
        return STATE_CUSTOMER;

    case 3:
        return STATE_HOME;

    default:
        printf("PLEASE TRY AGAIN!\n");
        return STATE_CUSTOMER;
    }
}
customer_view_state_t customer_menu_panel(void)
{
    unsigned int choose = 0;
    printf("\n----CUSTOMER MENU PANEL----\n");
    printf("1. Display available table!\n");
    printf("2. Reserved a table!\n");
    printf("3. See my reservation!!\n");
    printf("4. Update information!\n");
    printf("5. Remove my reservation!!\n");
    printf("6. Change my account security information!!\n");
    printf("7. Back to login page!!\n");
    printf("----------------------\n");
    while (scanf("%d", &choose) != 1 || choose < 1 || choose > 7)
    {
        printf("Please enter again!!\n");
        while (getchar() != '\n')
            ;
    }
    switch (choose)
    {
    case 1:
        return DISPLAY_AVALABLE_TABLE;
    case 2:
        return RESERVED_ADD;
    case 3:
        return RESERVED_DISPLAY;
    case 4:
        return RESERVED_UPDATE;
    case 5:
        return RESERVED_REMOVE;
    case 6:
        return CHANGE_ACCOUNT_CUSTOMER;
    default:
        return REVERSED_EXIT;
    }
    printf("Exit customer menu panel!!!\n");
#if 0
    while (1)
    {
        // menu_display(customer_view, CUSTOMER_PANEL);

        printf("Exit or continues the program in customer view?\n");
        printf("enter 1 to stay, 0 to exit: \n");
        while (scanf("%d", &lua_chon) != 1 || lua_chon < 0 || lua_chon > 1)
        {
            printf("---ENTER 0 OR 1 NIGGA!---\n");
            while (getchar() != '\n')
                ;
        }
        if (lua_chon == 0) // exit
        {
            return STATE_CUSTOMER;
        }
        // lua_chon = 1
        // -> still inside while loop
    }
#endif
}
void customer_login(void)
{
    printf("---Authentication For Customer---\n");
    printf("enter a customer username:\n");
    printf("enter customer password:\n");
}
void customer_create_account(void)
{
}
customer_view_state_t customer_change_credentials(void)
{
}
customer_view_state_t reserve_table_add(void)
{
}
customer_view_state_t reserve_table_display(void)
{
}
customer_view_state_t reserve_table_update(void)
{
}
customer_view_state_t reserve_table_remove(void)
{
}
customer_state_t customer_manage() // this for admin control
{

    int choose_index = 0;
    int flag_value = 1;
    while (flag_value) // equal 1 -> loop
    {
        printf("CUSTOMER MANAGEMENT ADMIN'S VIEW\n");
        printf("ADD NEW CUSTOMER                -> 1\n");
        printf("DISPLAY CUSTOMER                -> 2\n");
        printf("REMOVE CUSTOMER                 -> 3\n");
        printf("UPDATE CUSTOMER                 -> 4\n");
        printf("EXIT CUSTOMER MANAGEMENT        -> 0\n");
        printf("-------ENTER YOUR CHOICE-------\n");
        while (scanf("%d", &choose_index) != 1 || choose_index < 0 || choose_index > 4)
        {
            printf("Please enter from 0 to 4!!\n");
            printf("ENTER YOUR CHOICE: \n");
            while (getchar() != '\n')
                ;
        }
        switch (choose_index)
        {
        case 1:
            printf("1. Add customer !!!\n");
            return CUSTOMER_STATE_ADD;

        case 2:
            printf("2. Display customer !!!\n");
            return CUSTOMER_STATE_DISPLAY;

        case 3:
            printf("3. Remove customer !!!\n");
            return CUSTOMER_STATE_REMOVE;

        case 4:
            printf("4. Update customer !!!\n");
            return CUSTOMER_STATE_UPDATE;
        default:
            printf("Exit customer !!\n");
            flag_value = 0;
            break;
        }
    }
    return CUSTOMER_STATE_EXIT;
}
customer_state_t customer_add(void)
{
}
customer_state_t customer_display(void)
{
}
customer_state_t customer_update(void)
{
}
customer_state_t customer_remove(void)
{
}
int admin_view_customer_reserved(void)
{
}
customer_view_state_t table_available_display()
{
}