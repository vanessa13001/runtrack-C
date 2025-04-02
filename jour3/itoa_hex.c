//  la fonction itoa_hex, qui convertit un entier en une chaîne de caractères en base hexadécimale 
#include <stdio.h>
#include <stdlib.h>

char *itoa_hex(int n) {
    // gestion du cas où la valeur est nulle
    if (n == 0) {
        char *result = (char *)malloc(2 * sizeof(char));  // 1 caractère + '\0'
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // variables pour gérer la conversion
    int len = 0;
    int temp = n;
    char hex_digits[] = "0123456789ABCDEF";  // caractères hexadécimaux (majuscule)

    // calcul de la longueur nécessaire pour la chaîne
    while (temp != 0) {
        temp /= 16;
        len++;
    }

    // allocation de mémoire pour la chaîne de caractères
    char *result = (char *)malloc((len + 1) * sizeof(char));  // +1 pour le '\0'
    result[len] = '\0';  // le dernier caractère est le '\0'

    // remplissage de la chaîne de droite à gauche
    for (int i = len - 1; i >= 0; i--) {
        result[i] = hex_digits[n % 16];  // récupération du dernier chiffre hexadécimal
        n /= 16;  // passage à la valeur suivante
    }

    return result;
}

int main() {
    int number = 1234;  // exemple de nombre à convertir
    char *hex_string = itoa_hex(number);
    printf("Le nombre %d en hexadecimal est : %s\n", number, hex_string);
    free(hex_string);  // libération de la mémoire allouée
    return 0;
}


// explications :

// gestion du cas zéro : Si la valeur est 0, la fonction retourne immédiatement une chaîne "0"

//calcul de la longueur nécessaire : la boucle while calcule combien de chiffres hexadécimaux sont nécessaires pour représenter la valeur

//allocation mémoire : la mémoire pour la chaîne est allouée en fonction de la longueur calculée, et un caractère '\0' est ajouté à la fin pour indiquer la fin de la chaîne

//conversion : la boucle for remplit la chaîne de caractères de droite à gauche en utilisant les valeurs hexadécimale

//retour : la fonction retourne la chaîne de caractères résultante