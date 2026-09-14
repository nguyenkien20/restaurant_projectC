#ifndef COMMON_H_
#define COMMON_H_
// file header for other files .h
#include <stdint.h>
// function pointer
typedef struct RolePanel {
    const char *label;
    int (*handler)(void);   // require int type
} role_t;
int integer_input(const char *message, const int min_value, const int max_value); // function take %d and check value correct or not 
void menu_display(const role_t *pMenu, int size);
void menu_choose(const role_t *pMenu, uint8_t choose_index);

#endif