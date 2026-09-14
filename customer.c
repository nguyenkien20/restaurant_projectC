#include <stdio.h>
#include "customer.h"


state_t customerPanel(void)
{
    unsigned int choose1 = 0;
    printf("\nWELCOME TO CUSTOMER PANEL!\n");
    printf("--------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new customer account!\n");
    printf("3. Exit to home page\n");
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
    // return
}
state_t customer_menu_panel(void)
{
    int lua_chon = 0;
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
}
void customer_login(void)
{
    printf("---Authentication For Customer---\n");
    printf("enter a customer username:\n");
    printf("enter customer password:\n");
}
void customer_create_account(void){

}
void reserve_table(void){

}
void see_my_reservation(void){

}
void customer_reserved_update(void){

}
void customer_reserved_cancel(void){

}
void customer_menu_display(void){

}
void view_available_tables(void){

}
void customer_manage(const role_t *pCustomer, int size){

}
int customer_add(void){

}
int customer_display(void){

}
int customer_remove(void){

}
int admin_view_customer_reserved(void){
    
}