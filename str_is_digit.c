#include <stdio.h>

// Vérifie si un caractère est un chiffre
int char_is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Vérifie si une chaîne entière est composée de chiffres
int str_is_digit(const char *str) {
    if (*str == '\0') return 0; // Vérifie si la chaîne est vide

    while (*str) {
        if (!char_is_digit(*str)) {
            return 0; // Si un caractère n'est pas un chiffre, renvoie 0
        }
        str++;
    }
    return 1; // Tous les caractères sont des chiffres
}

// Fonction de test
int main() {
    // Test char_is_digit
    printf("char_is_digit:\n");
    printf("%d\n", char_is_digit('5')); // 1
    printf("%d\n", char_is_digit('a')); // 0
    printf("%d\n", char_is_digit('0')); // 1
    printf("%d\n", char_is_digit('9')); // 1
    printf("%d\n", char_is_digit(' ')); // 0

    // Test str_is_digit
    printf("\nstr_is_digit:\n");
    printf("%d\n", str_is_digit("12345")); // 1
    printf("%d\n", str_is_digit("12a45")); // 0
    printf("%d\n", str_is_digit("9876543210")); // 1
    printf("%d\n", str_is_digit("")); // 0 (chaîne vide)

    return 0;
}
