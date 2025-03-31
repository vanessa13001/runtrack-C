#include "my_putchar.c"

void my_putstr(const char *str) {
    while (*str) {
        my_putchar(*str);
        str++;
    }
}