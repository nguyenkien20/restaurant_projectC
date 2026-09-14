#include <stdio.h>
#include "inventory.h"

item_t items[MAX_ITEM];
int main()
{
    int i = inventory_manage();
    return 0;
}
int inventory_manage()
{
    int choose_index = 0;
    int flag_value = 1;
    int return_value = 0;
    while (flag_value) // equal 1 -> loop
    {
        printf("INVENTORY MANAGEMENT ADMIN'S VIEW\n");
        printf("ADD NEW ITEM                -> 1\n");
        printf("DISPLAY ALL ITEM            -> 2\n");
        printf("DELETE ITEM                 -> 3\n");
        printf("EXIT INVENTORY MANAGEMENT   -> 0\n");
        printf("ENTER YOUR CHOICE: \n");
        while (scanf("%d", &choose_index) != 1 || choose_index < 0 || choose_index > 3)
        {
            printf("please enter from 1 to 3!!\n");
            printf("ENTER YOUR CHOICE: \n");
            while (getchar() != '\n')
                ;
        }
        switch (choose_index)
        {
        case 1:
            return_value = item_add();
            return_value ? printf("Add new item succesfully!\n") : printf("Add new item fail!\n");
            break;
        case 2:
            // display all item
            return_value = item_display();
            break;
        case 3:
            return_value = item_remove();
            return_value ? printf("Delete item succesfully!\n") : printf("Delete item fail!\n");
            break;
        default:
            printf("exit!\n");
            flag_value = 0;
            break;
        }
    }
}
int item_display(void)
{
    printf("Success\n");
    printf("Those item in store is:\n");
}
int item_add(void)
{
    // static int item_index = 0;
    //     printf("Value of item index is: %d\n", item_index);
    //     int choose = 0;
    //     printf("1. ADD ITEM\n");
    //     printf("2. EXIT FUNCTION\n");

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
}
int item_update(void)
{
}
int item_remove(void)
{
}
int item_current(void)
{
}
