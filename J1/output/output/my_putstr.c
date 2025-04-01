#include <unistd.h>

// Affiche un seul caractère sur la sortie standard
void my_putchar(char c) {
    write(1, &c, 1);
}

// Affiche une chaîne de caractères en utilisant my_putchar
void my_putstr(const char *str) {
    while (*str) {
        my_putchar(*str);
        str++;
    }
}

// Fonction principale pour tester
int main() {
    my_putstr("Hello, World!\n");
    return 0;
}
