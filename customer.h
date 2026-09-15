#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "config.h"
#include "app_state.h"
#include "common.h"

typedef struct Customer
{
    char id[MAX_CHAR];
    char name[MAX_NAME];
    char phone_number[PHONENUMBER_LENG];
    int people_number;
    int is_reserved;
    char table_id[MAX_TABLE];
} customer_t;

typedef enum state_customer // this for customer's management
{
    CUSTOMER_STATE_HOME,
    CUSTOMER_STATE_ADD,
    CUSTOMER_STATE_DISPLAY,
    CUSTOMER_STATE_UPDATE,
    CUSTOMER_STATE_REMOVE,
    CUSTOMER_STATE_EXIT,
} customer_state_t;
/* between two enum definition here,
member inside must not have the same name */
typedef enum customer_view // this for customer reserved table
{
    CUSTOMER_VIEW_STATE_HOME,
    DISPLAY_AVALABLE_TABLE,
    RESERVED_ADD,
    RESERVED_DISPLAY,
    RESERVED_UPDATE,
    RESERVED_REMOVE,
    CHANGE_ACCOUNT_CUSTOMER,
    REVERSED_EXIT, 
} customer_view_state_t;

state_t customerPanel(void); // 1
customer_view_state_t customer_menu_panel(void);
void customer_login(void);
void customer_create_account(void);
customer_view_state_t customer_change_credentials(void);
// CUSTOMER CONTROLLER
customer_view_state_t table_available_display();
customer_view_state_t reserve_table_add(void);
customer_view_state_t reserve_table_display(void);
customer_view_state_t reserve_table_update(void);
customer_view_state_t reserve_table_remove(void);
// customer manage main function
customer_state_t customer_manage();
customer_state_t customer_add(void);
customer_state_t customer_display(void);
customer_state_t customer_remove(void);
customer_state_t customer_update(void);
int admin_view_customer_reserved(void);
#endif