#ifndef APPLICATION_STATE_H_
#define APPLICATION_STATE_H_

typedef enum state_home
{
    STATE_HOME,          // 0     // main_board
    STATE_ADMIN,         // 1     // admin_panel
    STATE_ADMIN_MENU,    // 2     // admin_menu_panel
    STATE_CUSTOMER,      // 3     // customer_panel
    STATE_CUSTOMER_MENU, // 4     // customer_menu_panel
    STATE_EXIT,          // 5     // exit the program
} state_t;

state_t main_board(void);   


#endif