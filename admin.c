#include <stdio.h>
#include <string.h>
#include "admin.h"

admin_t admins[MAX_ADMIN_ACCOUNT]; // declare an array with size is 10 admin accounts
admin_panel_state_t adminPanel(void)
{
    int choose1 = 0;
    printf("\n---WELCOME TO ADMIN PANEL!---\n");
    printf("1 -> Log in?\n");
    printf("2 -> Create a new admin account!\n");
    printf("3 -> Back to main board\n");
    printf("-----------------------------\n");
    choose1 = integer_input("Enter your choice: ");
    switch (choose1)
    {
    case 1:
        return ADMIN_PANEL_LOG_IN;
    case 2:
        return ADMIN_PANEL_CREATE_ACCOUNT;
    case 3:
        return ADMIN_PANEL_STATE_EXIT;
    default:
        printf("Invalid input!\n");
        break;
    }
    return ADMIN_PANEL_STATE_HOME;
}
admin_state_t admin_menu_panel(void)
{
    int choose = 0;
    printf("\n----ADMIN MENU PANEL----\n");
    printf("1 -> Manage inventory!\n");              // ADMIN_STATE_IVENTORY
    printf("2 -> Manage customers!\n");              // ADMIN_STATE_CUSTOMER
    printf("3 -> Manage discount!\n");               // ADMIN_STATE_DISCOUNT
    printf("4 -> Change my account information!\n"); // ADMIN_STATE_CHANGE_ACCOUNT
    printf("5 -> Exit panel!!\n");                   // ADMIN_STATE_EXIT
    choose = integer_input("Enter your choice: ");
    switch (choose)
    {
    case 1:
        return ADMIN_STATE_IVENTORY;
    case 2:
        return ADMIN_STATE_CUSTOMER;
    case 3:
        return ADMIN_STATE_DISCOUNT;
    case 4:
        return ADMIN_STATE_CHANGE_ACCOUNT;
    case 5:
        return ADMIN_STATE_EXIT;
    default:
        printf("Invalid input!\n");
        break;
    }
    return ADMIN_STATE_HOME;
}
admin_panel_state_t admin_log_in(void)
{
    admin_t temp_admin_account;
    int login_choose = 0;
    int account_index = -1;
    printf("-----ADMIN LOG IN PANEL-----\n");
    printf("1 -> Enter account and password!\n");
    printf("2 -> Exit the admin login panel!\n");
    login_choose = integer_input("Enter your choice: ");
    if (login_choose == 1)
    {
        printf("Enter name: \n");
        fgets(temp_admin_account.username, MAX_NAME, stdin);
        temp_admin_account.username[strcspn(temp_admin_account.username, "\n")] = '\0'; // remove "\n"
        for (int i = 0; i < MAX_ADMIN_ACCOUNT; i++)
        {
            if ((admins + i)->is_actived) // 1
            {
                if (!(strcmp(temp_admin_account.username, (admins + i)->username)))
                {
                    account_index = i;
                    // fprintf(stderr, "value of account_index (i) is %d\n", account_index);
                    break;
                }
            }
            else
            {
                printf("Account doesnt exist, please create an account!!\n");
                return ADMIN_PANEL_LOG_IN;
            }
        }
#if 1
        printf("Enter password: \n");
        while (1)
        {
            if (fgets(temp_admin_account.password, MAX_NAME, stdin) != NULL)
            {
                // fprintf(stderr, "value of account_index (i) is %d\n", account_index);
                temp_admin_account.password[strcspn(temp_admin_account.password, "\n")] = '\0';
                if (!(strcmp(temp_admin_account.password, ((admins + account_index)->password))))
                {
                    printf("Log in successful!!\n");
                    return ADMIN_PANEL_LOG_IN_SUCCESS;
                }
                else
                {
                    printf("Please enter password again: \n");
                }
            }
            else
            {
                printf("Cant read data!\n");
                return ADMIN_PANEL_LOG_IN;
            }
        }
#endif
    }
    else if (login_choose == 2)
    {
        return ADMIN_PANEL_STATE_HOME;
    }
    return ADMIN_PANEL_LOG_IN;
}
admin_panel_state_t admin_create_account(void)
{
    int create_account_choose = 0;
    int create_flag = 0;
    int index_create_account = 0;
    char twice_password[20];
    char time[20];
    FILE *p_create_account = fopen(ADMIN_LOGIN_ACCOUNT, "a");
    if(p_create_account == NULL){
        printf("Cant open file admin_login_account.txt\n");
        return ADMIN_PANEL_STATE_EXIT;
    }
    printf("-----ADMIN CREATE ACCOUNT PANEL-----\n");
    printf("1 -> Create account and password!\n");
    printf("2 -> Exit the admin create account panel!\n");
    create_account_choose = integer_input("Enter your choice: ");
    if (create_account_choose == 1)
    {
        for (int i = 0; i < MAX_ADMIN_ACCOUNT; i++)
        {
            if (!((admins + i)->is_actived)) // hasnt actived
            {

                printf("Enter exactly time right now: \n");
                fgets(time, 20, stdin);
                time[strcspn(time, "\n")] = 0;

                printf("Enter admin account name: \n");
                fgets(((admins + i)->username), MAX_NAME, stdin);
                (admins + i)->username[strcspn((admins + i)->username, "\n")] = 0; // remove \n character

                printf("Enter password\n");
                fgets(((admins + i)->password), MAX_NAME, stdin);
                (admins + i)->password[strcspn((admins + i)->password, "\n")] = 0; // remove \n character

                printf("Confirm password: \n");
                fgets(twice_password, MAX_NAME, stdin);
                twice_password[strcspn(twice_password, "\n")] = 0; // remove newline character

                (admins + i)->is_actived = 1; // enable account -> active

                if (!(strcmp(twice_password, (admins + i)->password)))
                {
                    create_flag = 1;
                    index_create_account = i;
                    break;
                }
                else
                {
#if 1
                    printf("Password not match. Try again: \n");
                    do
                    {
                        fgets(twice_password, MAX_NAME, stdin);
                        twice_password[strcspn(twice_password, "\n")] = 0;
                        if (((strcmp(twice_password, (admins + i)->password)) != 0))
                        {
                            printf("Password not match again!\n");
                        }
                    } while ((strcmp(twice_password, (admins + i)->password)) != 0);
                    create_flag = 1;
                    index_create_account = i;
                    break;
#endif
                }
            }
        }
        if (create_flag)
        {
            printf("Create admin account succesful!!\n");
            printf("Account has been stored in txt file, please check!!\n");
            fprintf(p_create_account,"\n----ADMIN ACCOUNT CREATE RECORD----\n");
            fprintf(p_create_account,"1. TIME: %s\n", time);
            fprintf(p_create_account,"2. NAME: %s\n", ((admins + index_create_account)->username));
            fprintf(p_create_account,"3. PASSWORD: %s\n", twice_password);
            fprintf(p_create_account,"-----------------------------------\n");
            fclose(p_create_account);
            p_create_account = NULL;
            return ADMIN_PANEL_CREATE_ACCOUNT;
        }
    }
    else if (create_account_choose == 2)
    {
        return ADMIN_PANEL_STATE_HOME;
    }
    else
    {
        printf("Invalid choice! Please try again\n");
    }
    return ADMIN_PANEL_CREATE_ACCOUNT;
}
admin_state_t admin_change_credentials(void) // this function not okay, fix later
{
    int admin_change_credentials_choose = 0;
    printf("-----ADMIN CHANGE CREDENTIALS PANEL-----\n");
    printf("1  -> Change admin account and password?\n");
    printf("2  -> Exit function?\n");
    admin_change_credentials_choose = integer_input("Enter your choice");
    if (admin_change_credentials_choose == 1)
    {
        admin_t temp_admin_account;
        int admin_account_index = -1;
        printf("Enter old admin name's: \n");
        fgets(temp_admin_account.username, MAX_NAME, stdin);
        temp_admin_account.username[strcspn(temp_admin_account.username, "\n")] = 0;
        for (int i = 0; i < MAX_ADMIN_ACCOUNT; i++)
        {
            if (((admins + i)->is_actived)) // checking which accounts is_activated = 1;
            {
                if (!(strcmp(temp_admin_account.username, ((admins + i)->username))))
                {
                    printf("username %s is existed!!\n", temp_admin_account.username);
                    admin_account_index = i;
                    break;
                }
                else
                {
                    printf("User name %s doesnt exist!!\n", temp_admin_account.username);
                }
            }
        }
        if (admin_account_index == -1)
        {
            return ADMIN_STATE_CHANGE_ACCOUNT;
        }
        printf("Enter old admin password's: \n");
        fgets(temp_admin_account.password, MAX_NAME, stdin);
        temp_admin_account.password[strcspn(temp_admin_account.password, "\n")] = 0;
        if (!(strcmp(temp_admin_account.password, ((admins + admin_account_index)->password))))
        {
            printf("Enter new admin password's: \n");
            fgets(((admins + admin_account_index)->password), MAX_NAME, stdin);
            ((admins + admin_account_index)->password)[strcspn(((admins + admin_account_index)->password), "\n")] = 0;
        }
    }
    else if (admin_change_credentials_choose == 2)
    {
        return ADMIN_STATE_HOME;
    }
    return ADMIN_STATE_CHANGE_ACCOUNT;
}
