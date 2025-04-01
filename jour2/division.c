#include "divide.c"

void divide(int *n) {
    if (n) {
        *n /= 2;
    }
}
// Cette fonction vérifie d'abord si le pointeur est valide (non nul) avant de diviser la valeur pointée par 2.