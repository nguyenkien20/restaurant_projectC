#ifndef ADMIN_H_
#define ADMIN_H_

#include "config.h"
#include "app_state.h"
typedef struct Admin
{
    char username[MAX_NAME];
    char password[MAX_NAME];
} admin_t;

state_t adminPanel(void); 
state_t admin_menu_panel(void);
void admin_login(void); 
void admin_create_account(void);
void admin_change_credentials(void);

#endif