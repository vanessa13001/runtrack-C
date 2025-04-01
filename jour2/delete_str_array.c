#include <stdlib.h>
#include <stdio.h>

void delete_str_array(char ***array) {
    if (!array || !*array) return;
    
    for (int i = 0; (*array)[i] != NULL; i++) {
        free((*array)[i]);
    }
    free(*array);
    *array = NULL;
}

// prgramme de test
int main() {
    char **words = malloc(4 * sizeof(char *));
    if (!words) return 1;
    
    words[0] = malloc(6); // "Hello"
    words[1] = malloc(6); // "World"
    words[2] = malloc(5); // "Test"
    words[3] = NULL;
    
    if (!words[0] || !words[1] || !words[2]) return 1;
    
    snprintf(words[0], 6, "Hello");
    snprintf(words[1], 6, "World");
    snprintf(words[2], 5, "Test");
    
    printf("Before delete: %s, %s, %s\n", words[0], words[1], words[2]);
    
    delete_str_array(&words);
    
    if (words == NULL) {
        printf("Array successfully deleted.\n");
    }
    
    return 0;
}

// explications : #include <stdio.h> : permet d'utiliser printf() pour afficher du texte

//#include <stdlib.h> : permet d'utiliser malloc() pour allouer de la mémoire et free() pour la libérer

// déclaration des pointeurs : int *ptr1 = malloc(sizeof(int)); malloc(sizeof(int)) alloue dynamiquement de la mémoire pour un entier (int).
//ptr1 devient un pointeur qui stocke l'adresse de cette mémoire allouée

//si malloc échoue, ptr1 sera NULL
//int *ptr2 = NULL;

//ptr2 est un pointeur mais il ne pointe vers rien (NULL)

//cela permet d'éviter d'utiliser une adresse invalide par erreur

//verification et assignation d'une valeur , if (ptr1) vérifie que ptr1 n'est pas NULL (c'est-à-dire que malloc() a réussi).*ptr1 = 42;

//*ptr1 signifie que "le contenu de l'adresse pointée par ptr1", on met la valeur 42 dans l adresse mémoire

//affichage : printf("ptr1 pointe vers la valeur : %d\n", *ptr1); affiche la valeur stockée dans ptr1

// resumer : On alloue un entier avec malloc() et on stocke son adresse dans ptr1.on assigne 42 à cette mémoire et on affiche la valeur.

//on crée un pointeur ptr2 qui est NULL et on le vérifie on libère ptr1, puis on le met à NULL pour éviter des erreurs et on affiche un message confirmant que ptr1 est bien libéré.