#include <stdio.h>

// Vérifie si un caractère est un chiffre
int char_is_digit(char c) 
{
    return (c >= '0' && c <= '9');
}

// Fonction de test
int main() {
    printf("%d\n", char_is_digit('5')); // 1
    printf("%d\n", char_is_digit('a')); // 0
    printf("%d\n", char_is_digit('0')); // 1
    printf("%d\n", char_is_digit('9')); // 1
    printf("%d\n", char_is_digit(' ')); // 0
    return 0;
}