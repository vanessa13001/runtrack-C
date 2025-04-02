#include <stdio.h>

int power(int x, unsigned int n) {
    // condition de base
    if (n == 0)
        return 1;

    // on récupére le résultat du sous-problème
    int half_power = power(x, n / 2);

    // si n est pair
    if (n % 2 == 0)
        return half_power * half_power;
    else // si n est impair on return *half_power * half_power
        return x * half_power * half_power;
}

int main(void) {
    int x = -2;
    unsigned int n = 10;

    printf("pow(%d, %d) = %d\n", x, n, power(x, n));
    return 0;
}


// explication : 
// Utilisation de unsigned int pour n : évite les erreurs de calcul pour les valeurs négatives

//rappel récursif : on stocke power(x, n/2) dans half_power pour éviter de le recalculer

// gestion des cas pair/impair 

// si seulement n ,  est pair, on retourne: half_power * half_power

// et si n est impair, on retourne : x * half_power * half_power