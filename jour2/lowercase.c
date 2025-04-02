#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// fonction pour convertir une chaîne en minuscules
char *to_lowercase(const char *str) {
    if (!str) return NULL;

    int len = strlen(str);
    char *lower_str = malloc(len + 1); // dans la fonction to_lowercase(), on alloue  dynamiquement la mémoire avec malloc() pour stocker la chaîne en minuscule 

    if (!lower_str) return NULL;

    for (int i = 0; i < len; i++) {
        lower_str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
    lower_str[len] = '\0';

    return lower_str;
}

// fonction pour afficher une chaîne avec un retour à la ligne
void my_putstr(const char *str) {
    if (!str) return;
    write(1, str, strlen(str));
    write(1, "\n", 1);  // ajout du retour à la ligne
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "usage: ./lowercase hello world 123 ...\n", 39);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *lower = to_lowercase(argv[i]);
        if (!lower) {
            write(2, "erreur d'allocation mémoire\n", 28); // write() – affichage en sortie write() est une fonction de bas niveau qui fait partie de la bibliothèque unistd.h qui nous permets d'écrire des données brutes dans un fichier ou dans la console (stdout).
            return 1;
        }
        my_putstr(lower);  // affiche chaque mot avec un retour à la ligne
        free(lower);
    }

    return 0;
}


// conclusion résumer , prendre les arguments et convertir chaque arguments en minuscule, 

//explication du code
//to_lowercase() convertit une chaîne en minuscules en vérifiant chaque caractère, utilise malloc() pour allouer une nouvelle chaîne.

//free() est appelé après usage pour éviter une fuite de mémoire, my_putstr() fonction qui affiche une chaîne avec write(), main()

//vérifie si des arguments sont passés convertit chaque argument en minuscules affiche le résultat et libère la mémoire allouée.