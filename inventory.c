#include <stdio.h>
#include <string.h>
#include "inventory.h"

static item_t items[MAX_ITEM];

inventory_state_t inventory_manage()
{
    int choose_index = 0;
    printf("INVENTORY MANAGEMENT ADMIN'S VIEW\n");
    printf("ADD ITEM                            -> 1\n");
    printf("DISPLAY ITEM                        -> 2\n");
    printf("REMOVE ITEM                         -> 3\n");
    printf("UPDATE ITEM                         -> 4\n");
    printf("EXIT INVENTORY MANAGEMENT           -> 0\n");
    choose_index = integer_input("-------ENTER YOUR CHOICE-------");
    switch (choose_index)
    {
    case 0:
        return INVEN_STATE_EXIT;
    case 1:
        return INVEN_STATE_ADD;
    case 2:
        return INVEN_STATE_DISPLAY;
    case 3:
        return INVEN_STATE_REMOVE;
    case 4:
        return INVEN_STATE_UPDATE;
    default:
        printf("Please enter from 0 to 4!!\n");
        break;
    }
    return INVEN_STATE_HOME;
}
inventory_state_t item_display(void)
{
    int flag_check = 0;
    int display_choose = 0;
    int count_index = 0;
    printf("----ITEM INFORMATION DISPLAY----\n");
    printf("1. Display all items\n");
    printf("2. Display one item\n");
    printf("3. Exit the fucntion!\n");
    display_choose = integer_input("--Enter your choice: --");
    if (display_choose == 1)
    {
        for (int i = 0; i < MAX_ITEM; i++)
        {
            if (((items + i)->item_id) != 0)
            {
                // display item information
                flag_check = 1;
                printf("ITEM %d \n", ++count_index);
                printf("1)ID: %d\n", (items + i)->item_id);
                printf("2)Name: %s\n", items[i].name);
                printf("3)Price: %.2lf\n", items[i].price);
                printf("4)Quantity: %d\n", items[i].quantity);
            }
        }
        if (!flag_check)
        {
            printf("There is no item in display panel!\n");
        }
    }
    else if (display_choose == 2)
    {
        int single_item_display = 0;
        int single_flag_check = 0;
        single_item_display = integer_input("Enter id's item you want to display:");
        for (int i = 0; i < MAX_ITEM; i++)
        {
            if (single_item_display == ((items + i)->item_id))
            {
                single_flag_check = 1;
                printf("ITEM %d \n", ++count_index);
                printf("1)ID: %d\n", (items + i)->item_id);
                printf("2)Name: %s\n", items[i].name);
                printf("3)Price: %.2lf\n", items[i].price);
                printf("4)Quantity: %d\n", items[i].quantity);
            }
        }
        if (!single_flag_check)
        {
            printf("This %d id number doesnt exist!!!\n", single_item_display);
        }
    }
    else if (display_choose == 3)
    {
        printf("Exit the display function!\n");
        return INVEN_STATE_HOME;
    }
    return INVEN_STATE_DISPLAY;
}
inventory_state_t item_add(void)
{
    FILE *pInventory_record = NULL;
    pInventory_record = fopen(INVENTORY_RECORD, "a"); // read and write
    if (pInventory_record == NULL)
    {
        printf("Can't open file inventor_record.txt\n");
        return (-1);
    }
    int choose = 0;
    printf("1 --> ADD ITEM\n");
    printf("2 --> EXIT FUNCTION\n");
    choose = integer_input("Enter your choice:");
    if (choose == 1)
    {
        int id_number_choose = 0; // id number choose
        int is_exit = 0;
        // admin enter information
        for (int i = 0; i < MAX_ITEM; i++) // i < 100
        {
            if (!((items + i)->item_id))
            {
                id_number_choose = integer_input("Enter item's id number");
                is_exit = item_id_check(id_number_choose); // check whether item's id number is already exist or not
                if (!is_exit)
                {
                    (items + i)->item_id = id_number_choose; // assign value to struct member id_number
                    printf("Enter name's item with id number %d: \n", id_number_choose);
                    fgets(items[i].name, MAX_NAME, stdin);
                    (items[i].name)[strcspn((items[i].name), "\n")] = '\0'; // delete "\n" character in fgets function
                    printf("Enter price's item with id number %d: \n", id_number_choose);
                    while (scanf("%lf", &(items[i].price)) != 1)
                    {
                        printf("Please enter valid price number\n");
                        while (getchar() != '\n')
                            ;
                    }
                    while (getchar() != '\n')
                        ;
                    (items + i)->quantity = integer_input("Enter quantity:");
                    printf("Add succesfully item with id %d!\n", id_number_choose);
                    printf("Item with id: %d also has been recorded in inventor_record.txt\n", id_number_choose);
                    fprintf(pInventory_record, "\n-------INVENTORY ITEM -------\n");
                    fprintf(pInventory_record, "1. Item's id number: %d\n", (items + i)->item_id);
                    fprintf(pInventory_record, "2. Item's name: %s\n", (items + i)->name);
                    fprintf(pInventory_record, "3. Item's price: %.2lf\n", (items + i)->price);
                    fprintf(pInventory_record, "4. Item's quantity: %d\n", (items + i)->quantity);
                    fclose(pInventory_record);
                    pInventory_record = NULL;
                }
                else
                {
                    printf("Item with id number %d has already exist!!\n", id_number_choose);
                    printf("Please choose another id number!\n");
                }
                break;
            }
        }
    }
    else if (choose == 2)
    {
        printf("Exit add item!\n");
        return INVEN_STATE_HOME; // back to inventory_manage();
    }
    return INVEN_STATE_ADD;
}
inventory_state_t item_update(void)
{
    int update_choose = 0;
    printf("1. Update single item!\n");
    printf("2. Exit the function!\n");
    update_choose = integer_input("Enter your choice:");
    if (update_choose == 1)
    {
        int item_id_update = 0;
        int is_exit = 0;
        item_id_update = integer_input("Please enter id's item to update:");
        is_exit = item_id_check(item_id_update); // 0 not exist, 1 -> exist
        if (is_exit)
        {
            for (int i = 0; i < MAX_ITEM; i++)
            {
                if (item_id_update == ((items + i)->item_id))
                {
                    printf("Old name: %s\n", (items + i)->name);
                    printf("New name: \n");
                    fgets(((items + i)->name), MAX_NAME, stdin);
                    ((items + i)->name)[strcspn(((items + i)->name), "\n")] = '\0'; // delete "\n" character in string
                    printf("Old price: %.2lf\n", ((items + i)->price));
                    printf("New price: \n");
                    scanf("%lf", &((items + i)->price));
                    printf("Old quantity: %d\n", ((items + i)->quantity));
                    printf("New quantity: \n");
                    scanf("%d", &((items + i)->quantity));
                }
            }
        }
        else
        {
            printf("Item with id number %d doesnt exist!\n", item_id_update);
        }
    }
    else
    {
        return INVEN_STATE_HOME;
    }
    return INVEN_STATE_UPDATE;
}
inventory_state_t item_remove(void)
{
    int remove_choose = 0;
    int remove_flag = 0;
    printf("1. Delete all item in inventory store!\n");
    printf("2. Delete single item in inventory store!\n");
    printf("3. Exit the function!\n");
    remove_choose = integer_input("Enter your choice:");
    if (remove_choose == 1)
    {
        for (int i = 0; i < MAX_ITEM; i++)
        {
            if (((items + i)->item_id) != 0)
            {
                memset((items + i), 0, sizeof(item_t));
                remove_flag = 1;
            }
        }
        if (remove_flag)
        {
            printf("Remove successful all items\n");
        }
        if (remove_flag == 0)
        {
            printf("There are no items to remove\n");
        }
    }
    else if (remove_choose == 2)
    {
        int single_item_remove = 0;
        int single_remove_flag_check = 0;
        single_item_remove = integer_input("Enter id's item want to remove:");
        for (int i = 0; i < MAX_ITEM; i++)
        {
            if (single_item_remove == ((items + i)->item_id))
            {
                // delete single item
                memset((items + i), 0, sizeof(item_t));
                single_remove_flag_check = 1;
            }
        }
        if (single_remove_flag_check)
        {
            printf("Remove id's item %d successfully!\n", single_item_remove);
        }
        else
        {
            printf("ID number %d doesnt exists!!\n", single_item_remove);
        }
    }
    else if (remove_choose == 3)
    {
        printf("Exit remove function!\n");
        return INVEN_STATE_HOME;
    }
    return INVEN_STATE_REMOVE;
}
int item_id_check(int item_id_number)
{
    int is_exit = 0;
    for (int i = 0; i < MAX_ITEM; i++)
    {
        if (item_id_number == (items + i)->item_id)
        {
            printf("ID number %d already exists!\n", item_id_number);
            is_exit = 1;
            break; // if exist -> break -> return immediately
        }
    }
    return is_exit;
}