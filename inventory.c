#include <stdio.h>
#include "inventory.h"

item_t items[MAX_ITEM];

inventory_state_t inventory_manage()
{
    int choose_index = 0;
    printf("INVENTORY MANAGEMENT ADMIN'S VIEW\n");
    printf("ADD NEW ITEM                -> 1\n");
    printf("DISPLAY ALL ITEM            -> 2\n");
    printf("REMOVE ITEM                 -> 3\n");
    printf("UPDATE ITEM                 -> 4\n");
    printf("EXIT INVENTORY MANAGEMENT   -> 0\n");
    printf("-------ENTER YOUR CHOICE-------\n");
    while (scanf("%d", &choose_index) != 1 || choose_index < 0 || choose_index > 4)
    {
        printf("Please enter from 0 to 4!!\n");
        printf("ENTER YOUR CHOICE: \n");
        while (getchar() != '\n')
            ;
    }
    switch (choose_index)
    {
    case 1:
        printf("1. Add item !!!\n");
        return INVEN_STATE_ADD;

    case 2:
        printf("2. Display item !!!\n");
        return INVEN_STATE_DISPLAY;

    case 3:
        printf("3. Remove item !!!\n");
        return INVEN_STATE_REMOVE;

    case 4:
        printf("4. Update item !!!\n");
        return INVEN_STATE_UPDATE;
    default:
        printf("Exit item !!\n");
        return INVEN_STATE_EXIT;
        break;
    }
}
inventory_state_t item_display(void)
{
    printf("Success\n");
    printf("Those item in store is:\n");
    return INVEN_STATE_HOME;
}
inventory_state_t item_add(void)
{
    // static int item_index = 0;
    //     printf("Value of item index is: %d\n", item_index);
    //     int choose = 0;
    // printf("1. ADD ITEM\n");
    // printf("2. EXIT FUNCTION\n");
    printf("ok\n");

    //     while (scanf("%d", &choose) != 1 || choose > 2 || choose < 1)
    //     {
    //         printf("Please enter 1 or 2\n");
    //     }
    //     // admin enter information
    //     printf("Enter id number %d: \n", item_index + 1);
    //     while (getchar() != '\n')
    //         ;
    //     fgets(items[item_index].id, MAX_CHAR, stdin);
    //     printf("Enter name number %d: \n", item_index + 1);
    //     fgets(items[item_index].name, MAX_NAME, stdin);
    //     printf("Enter price number %d: \n", item_index + 1);
    //     while (scanf("%lf", &(items[item_index].price)) != 1)
    //     {
    //         printf("Please enter valid price number\n");
    //         while (getchar() != '\n')
    //             ;
    //     }
    //     printf("Enter quantity number %d: \n", item_index + 1);
    //     while (scanf("%d", &(items[item_index].quantity)) != 1)
    //     {
    //         printf("Please enter valid quantity number!\n");
    //         while (getchar() != '\n')
    //             ;
    //     }
    //     // display item information
    //     printf("ITEM(%d)-INFORMATION\n", item_index + 1);
    //     printf("1)ID: %s\n", items[item_index].id);
    //     printf("2)Name: %s\n", items[item_index].name);
    //     printf("3)Price: %.2lf\n", items[item_index].price);
    //     printf("4)Quantity: %d\n", items[item_index].quantity);
    // display shouldnt place here -> one function just take a single purpose
    return INVEN_STATE_HOME;
}
inventory_state_t item_update(void)
{
    printf("ok\n");
    return INVEN_STATE_HOME;
}
inventory_state_t item_remove(void)
{
    printf("ok\n");
    return INVEN_STATE_HOME;
}
int item_current(void)
{
}
