#include <stdlib.h>
#include <string.h>
#include <stdio.h> // Ajouté pour les tests

/**
 * my_strdup - Duplique une chaîne de caractères en allouant dynamiquement la mémoire.
 * @str: La chaîne de caractères à dupliquer.
 *
 * Retourne un pointeur vers la nouvelle chaîne allouée, ou NULL en cas d'erreur.
 */
char *my_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    // Allouer la mémoire pour la copie de la chaîne (incluant '\0')
    char *copy = malloc(strlen(str) + 1);
    if (copy == NULL) {
        return NULL; // Échec de l'allocation
    }
    
    // Copier la chaîne source dans la mémoire allouée
    strcpy(copy, str);
    
    return copy;
}

// Fonction de test
int main() {
    const char *original = "Hello, world!";
    char *duplicate = my_strdup(original);
    
    if (duplicate) {
        printf("Copie réussie: %s\n", duplicate);
        free(duplicate); // Libération de la mémoire
    } else {
        printf("Échec de la duplication\n");
    }
    return 0;
}