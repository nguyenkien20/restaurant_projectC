#ifndef DISCOUNT_H_
#define DISCOUNT_H_

#include "config.h"
#include "common.h"
typedef enum state_discount
{
    DISCOUNT_STATE_ADD,
    DISCOUNT_STATE_DISPLAY,
    DISCOUNT_STATE_REMOVE,
} discount_state_t;

typedef struct Discount
{
    char guest_id[MAX_CHAR]; // discount add depend on guest.id
    double percent;
} discount_t;

void discount_manage(const role_t *pDiscount, int size); 
int discount_add(void);
int discount_remove(void);
int discount_display(void);

#endif