#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int n) {
    int temp = n, len = 0, is_negative = 0;

    if (n == 0) return "0"; // cas spécial pour 0

    if (n < 0) {
        is_negative = 1;
        temp = -n; // on travaille avec la valeur absolue
    }

    // on calcul la longueur de la chaîne nécessaire
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    
    char *res = malloc(len + is_negative + 1); // +1 pour le signe et +1 pour '\0'
    if (!res) return NULL; // on verifie l'allocation

    res[len + is_negative] = '\0'; // fin  de  la chaîne

    temp = is_negative ? -n : n;

    // on rempli la chaîne en partant de la fin
    for (int i = len + is_negative - 1; i >= is_negative; i--) {
        res[i] = (temp % 10) + '0';
        temp /= 10;
    }

    if (is_negative) res[0] = '-'; // on ajoute le signe pour les nombres négatifs

    return res;
}

int main() {
    int numbers[] = {123, -456, 0, 7890, -2147483648};
    for (int i = 0; i < 5; i++) {
        char *str = my_itoa(numbers[i]);
        if (str) {
            printf("%d -> \"%s\"\n", numbers[i], str);
            free(str); // on libére la mémoire allouée avec free
        }
    }
    return 0;
}



//Explication : 

// on doit déterminer la taille de la chaîne puis on compte le nombre de chiffres du nombre (n), on ajoute 1 si 'n' est négatif (pour le signe -).

//on ajoute 1 pour le \0 de fin,( fin de string ) 

//allouer dynamiquement la mémoire, nous utilisons malloc  qui justement alloue de façon dynamique la mémoire

// on remplir la chaîne avec les chiffres

// on extrait les chiffres un à un en commençant par la fin puis on ajouter le signe négatif si nécessaire

// et si n est négatif, on place le signe - au début.

// La fonction itoa (integer to ASCII) convertit un entier (int) en une chaîne de caractères (char *). Contrairement à " atoi "  (ASCII to integer), qui convertit une chaîne en entier, itoa effectue l'opération inverse
