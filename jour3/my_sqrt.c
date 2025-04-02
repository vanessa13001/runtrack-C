#include <stdio.h>

int my_sqrt(int n) {
    if (n < 0) {
        // on return 0 si n est négatif (pas de racine carrée réelle)
        return 0;
    }

    int left = 0, right = n, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int mid_squared = mid * mid;

        if (mid_squared == n) {
            // si on trouve que mid^2 ( racine carré ) est égal à n, alors mid est la racine carrée
            return mid;
        }
        else if (mid_squared < n) {
            left = mid + 1; // on recherche dans la moitié droite
        }
        else {
            right = mid - 1; // on recherche dans la moitié gauche
        }
    }

    // si on ne trouve pas un carré parfait, on retourne 0
    return 0;
}

int main(void) {
    int x = 16;
    printf("La racine carree de %d est : %d\n", x, my_sqrt(x));

    x = 15;
    printf("La racine carree de %d est : %d\n", x, my_sqrt(x));

    return 0;
}


// EXPLICATIONS 

// Validation des entrées : La fonction vérifie d'abord si le nombre est négatif, auquel cas il n'y a pas de racine carrée réelle, donc on retourne 0.

//recherche binaire :

//la recherche binaire est utilisée pour trouver un entier mid tel que  : mid * mid == n, si on trouve ce mid, on retourne mid

//si : mid * mid est plus petit que n, on cherche dans la moitié supérieure, sinon dans la moitié inférieure

//retourne 0 si la racine carrée n'est pas un entier parfait

//cas d'exemple :
//pour n = 16, la fonction retournera 4 (car 4 * 4 = 16)

//our n = 15, la fonction retournera 0 car la racine carrée de 15 n'est pas un entier

//avantages :
// la recherche binaire est efficace avec une complexité de O(log n).

//cette approche ne nécessite aucune fonction mathématique externe.