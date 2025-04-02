#include <stdio.h>
#include <ctype.h>

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    
    // ignorer les espaces initiaux boucle while pointeur string
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v') {
        str++;
    }
    
    // qui gère les signes + ou -
    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }
    
    // converti les chiffres en nombre entier
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return result * sign;
}

// testons la fonction
int main() {
    printf("%d\n", my_atoi("42"));         // 42
    printf("%d\n", my_atoi("   -123"));    // -123
    printf("%d\n", my_atoi("+56"));       // 56
    printf("%d\n", my_atoi("007"));       // 7
    printf("%d\n", my_atoi("-0"));        // 0
    printf("%d\n", my_atoi("123abc"));    // 123 (s'arrête au premier caractère non numérique)
    return 0;
}


//Cette implémentation suit les conventions de atoi de la bibliothèque standard C :

// ignore les espaces au début.

//gère les signes + et -.

// et onvertit les chiffres en un entier jusqu'à un caractère non numérique