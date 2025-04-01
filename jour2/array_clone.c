#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char** array_clone(char** array, int n) {
    if (array == NULL || n <= 0) {
        return NULL;
    }

// compter le nombre d'éléments jusqu'à n ou juqu'au pointeur null 

    int count = 0;
    while (count < n && array[count] != NULL ) {
        count++;
    }

//allouer la mémoire pour le tableau des chaines de caractere
char** clone = (char**)malloc((count + 1) * sizeof(char*));
    if (clone == NULL) {
        return NULL;
    }

// copier les chaines de caractere

for (int i = 0; i < count; i++) {
    clone[i] = (char*)malloc((strlen(array[i]) + 1) * sizeof(char));
    if (clone[i] == NULL) {
        // libérer la mémoire allouée en cas d'erreur
        for (int j = 0; j < i; j++) {
            free(clone[j]);
        }
        free(clone);
        return NULL;
    }
    strcpy(clone[i], array[i]);
}

// terminer le tableau par un pointeur NULL
clone[count] = NULL;

return clone;
}

// exemple d'utilisation

int main() {
    char* array[] = {"Bonjour", "le", "peuple", NULL};
    int n = 2;

    char** clone = array_clone(array, n);
    if (clone != NULL) {
        for (int i = 0; clone[i] != NULL; i++) {
            printf("%s\n", clone[i]);
            free(clone[i]);
        }
        free(clone);
    }

    return 0;
}

// expliction, Comptage des éléments : La fonction compte le nombre d'éléments jusqu'à n ou jusqu'au premier pointeur NULL.
// Allocation de mémoire : elle alloue de la mémoire pour le tableau de chaînes de caractères cloné.
//Copie des chaînes : elle copie chaque chaîne de caractères du tableau d'entrée dans le tableau cloné.
//Gestion des erreurs : si une allocation échoue, elle libère toute la mémoire précédemment allouée pour éviter les fuites de mémoire.
// Pointeur NULL final : le tableau cloné se termine par un pointeur NULL.