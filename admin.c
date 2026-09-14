#include "admin.h"

state_t adminPanel(void)
{
    unsigned int choose1 = 0, choose2 = 0;
    printf("\n-----------------------------\n");
    printf("----WELCOME TO ADMIN PANEL!----\n");
    printf("-----------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new admin account!\n");
    printf("3.Back to main board\n");
    printf("-----------------------------\n");
    printf("Enter your choice:\n");
    while (scanf("%u", &choose1) != 1 || choose1 < 1 || choose1 > 3) // nhap gia tri thanh cong ham scanf tra ve 1
    {
        printf("Must choose 1, 2 or 3!!\n");
        while (getchar() != '\n')
            ;
    }
    switch (choose1)
    {
    case 1:
        admin_login();
        printf("Login succesfully!!!\n");
        return STATE_ADMIN_MENU;

    case 2:
        admin_create_account();
        return STATE_ADMIN;

    case 3:
        return STATE_HOME;

    default:
        printf("PLEASE TRY AGAIN!\n");
        return STATE_ADMIN;
    }
}
state_t admin_menu_panel(void)
{
    int choose = 0;
    printf("--ADMIN MENU PANEL--\n");
    printf("1. Manage inventory!\n");
    printf("2. Manage customers!\n");
    printf("3. Manage discount!\n");
    printf("4. Change admin credentials!\n");
    printf("5. Exit admin menu panel\n");
    printf("----------------------\n");

    printf("enter 5 to exit admin menu:\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        // inventory_manage(inventory_manage_admin, INVENTORY_SIZE);
        
        break;

    case 2:
        // customer_manage(customer_manage_admin, CUSTOMER_SIZE);
        break;

    case 3:
        // discount_manage(discount_manage_admin, DISCOUNT_SIZE);
        break;

    case 4:
        admin_change_credentials();
        break;

    case 5:
        return STATE_ADMIN;

    default:
        printf("PLEASE TRY AGAIN!\n");
        return STATE_ADMIN_MENU;
    }
}
void admin_login(void)
{
    int flag = 0;
    printf("---Authentication For Admin---\n");
    // must create a logic login
    printf("enter admin username:\n");
    // fgets(username, sizeof(username), stdin); co the su dung de nhap chuoi
    // username[ strcspn( username, "\n" ) ] = '\0';
    // scanf("%49s", (pAdmin)->username);
    printf("enter admin password:\n");
    // scanf("%49s", (pAdmin)->password);
}
void admin_create_account(void)
{
    printf("enter an admin account name: \n");
    printf("enter a password\n");
    printf("enter one again password\n");
}
void admin_change_credentials(void)
{
    printf("please enter old account");
    printf("please enter old password");
    printf("please enter new password");
}
