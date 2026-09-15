#include <stdio.h>
#include <stdlib.h>
// include header files for project
#include "app_state.h"
#include "inventory.h"
#include "customer.h"
#include "discount.h"
#include "admin.h"
#include "config.h"
#include "common.h"

// main flow of program
int main()
{
    state_t state = STATE_HOME; // 0
    while (state != STATE_EXIT) // 5
    {
        switch (state)
        {
        case STATE_HOME:
            state = main_board(); // state receive value from main_board -> 1
            break;
        case STATE_ADMIN:
            state = adminPanel();
            // if(state == STATE_ADMIN_MENU)
            break;
        case STATE_ADMIN_MENU:                            // state = STATE_ADMIN_MENU;
            admin_state_t admin_state = ADMIN_STATE_HOME; // after set STATE_ADMIN_MENU, we need to set admin_state_t admin_state = ADMIN_STATE_HOME;
            int menu_flag_admin = 1;                      // flag for main admin manage panel loop
            while (menu_flag_admin)
            {
                switch (admin_state)
                {
                case ADMIN_STATE_HOME:
                    admin_state = admin_menu_panel();
                    break;
                case ADMIN_STATE_IVENTORY:
                    // inventory_manage();
                    // admin_state = ADMIN_STATE_HOME;
                    printf("\nYou are in inventory's manage by admin panel!\n");
                    inventory_state_t item_state = INVEN_STATE_HOME;
                    int inventory_admin_flag = 1; // flag for inventory manage loop
                    while (inventory_admin_flag)
                    {
                        switch (item_state)
                        {
                        case INVEN_STATE_HOME:
                            item_state = inventory_manage();
                            break;
                        case INVEN_STATE_ADD:
                            item_state = item_add(); // 2 case // 1.add 2.exit
                            break;
                        case INVEN_STATE_DISPLAY:
                            item_state = item_display();
                            break;
                        case INVEN_STATE_UPDATE:
                            item_state = item_update();
                            break;
                        case INVEN_STATE_REMOVE:
                            item_state = item_remove();
                            break;
                        default:
                            admin_state = ADMIN_STATE_HOME;
                            inventory_admin_flag = 0;
                            break;
                        }
                    }
                    break;
                case ADMIN_STATE_CUSTOMER:
                    // customer_manage();
                    // admin_state = ADMIN_STATE_HOME;
                    printf("\nYou are in customer's manage by admin panel!\n");
                    customer_state_t customer_state = CUSTOMER_STATE_HOME;
                    int customer_admin_flag = 1; // flag for customer manage loop
                    while (customer_admin_flag)
                    {
                        switch (customer_state)
                        {
                        case CUSTOMER_STATE_HOME:
                            customer_state = customer_manage();
                            break;
                        case CUSTOMER_STATE_ADD:
                            customer_state = customer_add();
                            break;
                        case CUSTOMER_STATE_DISPLAY:
                            customer_state = customer_display();
                            break;
                        case CUSTOMER_STATE_UPDATE:
                            //
                            customer_state = customer_update();
                            break;
                        case CUSTOMER_STATE_REMOVE:
                            customer_state = customer_remove();
                            break;
                        default:
                            admin_state = ADMIN_STATE_HOME;
                            customer_admin_flag = 0;
                            break;
                        }
                    }
                    break;
                case ADMIN_STATE_DISCOUNT:
                    // discount_manage();
                    // admin_state = ADMIN_STATE_HOME;
                    printf("\nYou are in discount's manage by admin panel!\n");
                    discount_state_t discount_state = DISCOUNT_STATE_HOME;
                    int discount_admin_flag = 1; // flag for discount    manage loop
                    while (discount_admin_flag)
                    {
                        switch (discount_state)
                        {
                        case DISCOUNT_STATE_HOME:
                            break;
                        case DISCOUNT_STATE_ADD:
                            break;
                        case DISCOUNT_STATE_DISPLAY:
                            break;
                        case DISCOUNT_STATE_REMOVE:
                            break;
                        default:
                            admin_state = ADMIN_STATE_HOME;
                            discount_admin_flag = 0;
                            break;
                        }
                    }
                    break;
                case ADMIN_STATE_CHANGE_ACCOUNT:
                    // admin_change_credentials();
                    // admin_state = ADMIN_STATE_HOME;
                    printf("\nYou are in change account manage by admin panel!\n");
                    break;
                default:
                    state = STATE_ADMIN;
                    menu_flag_admin = 0;
                    break;
                }
                // if(admin_state != ADMIN_STATE_EXIT)
            }
            break;
        case STATE_CUSTOMER:
            state = customerPanel();
            break;
        case STATE_CUSTOMER_MENU:
            printf("\nYou are in customer view for reserved table!\n");
            customer_view_state_t customer_state_view = CUSTOMER_VIEW_STATE_HOME;
            int reserved_table_flag = 1; // flag for loop
            while (reserved_table_flag)
            {
                switch (customer_state_view)
                {
                case CUSTOMER_VIEW_STATE_HOME:
                    customer_state_view = customer_menu_panel();
                    break;
                case DISPLAY_AVALABLE_TABLE:
                    customer_state_view = table_available_display();
                    break;
                case RESERVED_ADD:
                    customer_state_view = reserve_table_add();
                    break;
                case RESERVED_DISPLAY:
                    customer_state_view = reserve_table_display();
                    break;
                case RESERVED_UPDATE:
                    customer_state_view = reserve_table_update();
                    break;
                case RESERVED_REMOVE:
                    customer_state_view = reserve_table_remove();
                    break;
                case CHANGE_ACCOUNT_CUSTOMER:
                    customer_state_view = customer_change_credentials();
                    break;
                default:
                    // back to log in panel
                    state = STATE_CUSTOMER;
                    reserved_table_flag = 0;
                    break;
                }
            }
            break;
        default:
            state = STATE_EXIT;
            break;
        }
    }
    printf("Exit the program!\n");
    return 0;
}
