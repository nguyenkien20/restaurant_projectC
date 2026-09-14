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

typedef enum state_customer
{
    CUSTOMER_STATE_ADD,
    CUSTOMER_STATE_DISPLAY,
    CUSTOMER_STATE_UPDATE,
    CUSTOMER_STATE_REMOVE,
} customer_state_t;

state_t customerPanel(void); // 1
state_t customer_menu_panel(void);
void customer_login(void);
void customer_create_account(void);
// CUSTOMER CONTROLLER
void reserve_table(void);
void see_my_reservation(void);
void customer_reserved_update(void);
void customer_reserved_cancel(void);
void customer_menu_display(void);
void view_available_tables(void);
// customer manage main function
void customer_manage(const role_t *pCustomer, int size); ///////////
int customer_add(void);
int customer_display(void);
int customer_remove(void);
int admin_view_customer_reserved(void);

#endif