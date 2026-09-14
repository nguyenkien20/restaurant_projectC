#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "config.h"
#include "common.h"
typedef struct Item
{
    int item_id;         // ma san pham (phan biet bang so nguyen)
    char name[MAX_NAME]; // ten san pham
    double price;        // gia nhap
    int quantity;        // so luong san pham
} item_t;

extern item_t items[MAX_ITEM];

typedef enum state_inventory
{
    INVEN_STATE_HOME,
    INVEN_STATE_ADD,
    INVEN_STATE_DISPLAY,
    INVEN_STATE_UPDATE,
    INVEN_STATE_REMOVE,
    INVEN_STATE_EXIT,
} inventory_state_t;

int inventory_manage();
int item_display(void);
int item_add(void);
int item_update(void);
int item_remove(void);
int item_current(void);

#endif