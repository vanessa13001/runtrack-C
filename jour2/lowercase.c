#include <stdlib.h>
#include <unistd.h>

// fonction pour convertir une chaîne en minuscules
char *to_lowercase(const char *str) {
    int i = 0;
    char *lower_str = malloc(sizeof(char) * (strlen(str) + 1));

    if (!lower_str)
        return NULL;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            lower_str[i] = str[i] + 32;  // convertir en minuscule
        else
            lower_str[i] = str[i];
        i++;
    }
    lower_str[i] = '\0';  // chaîne fini
    return lower_str;
}

// fonction pour afficher une chaîne avec write()
void my_putstr(const char *str) {
    int len = 0;
    while (str[len]) len++;  // calculer la longueur
    write(1, str, len);
    write(1, "\n", 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        write(1, "Usage: ./lowercase Hello World 123 ...\n", 39);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *lower = to_lowercase(argv[i]);
        if (lower) {
            my_putstr(lower);
            free(lower);
        }
    }

    return 0;
}


// conclusion résumer , prendre les arguments et convertir chaque arguments en minuscule, 

//explication du code
//to_lowercase() convertit une chaîne en minuscules en vérifiant chaque caractère, utilise malloc() pour allouer une nouvelle chaîne.

//free() est appelé après usage pour éviter une fuite de mémoire, my_putstr() fonction qui affiche une chaîne avec write(), main()

//vérifie si des arguments sont passés convertit chaque argument en minuscules affiche le résultat et libère la mémoire allouée.