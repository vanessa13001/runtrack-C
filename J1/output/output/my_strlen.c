#include <stdio.h>

// Fonction qui calcule la longueur d'une chaîne de caractères
int my_strlen(const char *str) {
    int length = 0;

    // Parcourir la chaîne jusqu'au caractère de fin '\0'
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    const char *test_str = "Bonjour le monde!";
    int length = my_strlen(test_str);
    printf("La longueur de la chaîne est : %d\n", length);
    return 0;
}
