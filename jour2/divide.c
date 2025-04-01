#include <stdio.h>

//déclaration de la fonction
int division(int a, int b);

int main() {
    int y = 10;
    int x = 20;
    int resultat;

//appel de la fonction
resultat = division(x, y);
printf("La somme de %d et %d est %d\n", x, y, resultat);

return 0;
}

// definition de la fonction
int division(int a, int b) {
    return a -b;
}


