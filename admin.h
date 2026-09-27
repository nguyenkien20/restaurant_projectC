#ifndef ADMIN_H_
#define ADMIN_H_

#include "config.h"
#include "app_state.h"
#include "common.h"
#define ADMIN_LOGIN_ACCOUNT "admin_login_account.txt"
typedef struct Admin
{
    int is_actived; 
    char username[MAX_NAME]; 
    char password[MAX_NAME];
} admin_t;

typedef enum state_admin_panel
{
    ADMIN_PANEL_STATE_EXIT,
    ADMIN_PANEL_STATE_HOME,
    ADMIN_PANEL_LOG_IN,
    ADMIN_PANEL_LOG_IN_SUCCESS,
    ADMIN_PANEL_CREATE_ACCOUNT,
} admin_panel_state_t;

typedef enum state_admin
{
    ADMIN_STATE_EXIT,
    ADMIN_STATE_HOME, 
    ADMIN_STATE_IVENTORY,
    ADMIN_STATE_CUSTOMER,
    ADMIN_STATE_DISCOUNT,
    ADMIN_STATE_CHANGE_ACCOUNT,
} admin_state_t;

admin_panel_state_t adminPanel(void);
admin_state_t admin_menu_panel(void);
admin_panel_state_t admin_log_in(void);
admin_panel_state_t admin_create_account(void);
admin_state_t admin_change_credentials(void);
#endif