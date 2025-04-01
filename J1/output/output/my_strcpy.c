#include <stdio.h>

// Fonction my_strcpy qui copie la chaîne source dans la chaîne destination
char *my_strcpy(char *destination, const char *source) {
    if (destination == NULL || source == NULL) {
        return NULL; // Vérification des pointeurs nuls
    }

    char *ptr = destination;

    // Copie chaque caractère de la source vers la destination
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    // Ajoute le caractère de fin de chaîne
    *destination = '\0';

    return ptr;
}

int main() {
    char src[] = "Hello, World!";
    char dest[50];

    // Appel de la fonction my_strcpy
    my_strcpy(dest, src);

    // Affichage du résultat
    printf("Destination: %s\n", dest);

    return 0;
}
