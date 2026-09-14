#include <stdio.h>
#include <stdlib.h>
// include header files for project
#include "app_state.h"
#include "inventory.h"
#include "customer.h"
#include "admin.h"
#include "config.h"
#include "common.h"

int main()
{
    state_t state = STATE_HOME;
    while (state != STATE_EXIT)
    {
        switch (state)
        {
        case STATE_HOME:
            state = main_board(); // state receive value from main_board
            break;
        case STATE_ADMIN:
            state = adminPanel();
            break;
        case STATE_ADMIN_MENU:
            // state = admin_menu_panel();
            break;
        case STATE_CUSTOMER:
            // state = customerPanel();
            break;
        case STATE_CUSTOMER_MENU:
            // state = customer_menu_panel();
            break;
        default:
            state = STATE_EXIT;
            break;
        }
    }
    printf("Exit the program!\n");
    return 0;
}
