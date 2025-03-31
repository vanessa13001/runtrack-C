#include "my_putchar.c"  // Inclu le fichier contenant la fonction my_putchar

void my_putstr(const char *str) {
    while (*str) {
        my_putchar(*str);  // Appeler my_putchar pour chaque caractère de la chaîne
        str++;
    }
}
