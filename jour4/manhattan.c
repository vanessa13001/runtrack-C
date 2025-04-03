#ifndef MANHATTAN_H
#define MANHATTAN_H

// Définir la macro ABS(x) pour obtenir la valeur absolue de x
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Définir la structure de point avec typedef
typedef struct {
    int x; // coordonnée x
    int y; // coordonnée y
} point;

// Fonction qui calcule la distance de Manhattan entre deux points
int manhattan(point p1, point p2) {
    // Calcul de la somme des différences absolues des coordonnées
    return ABS(p1.x - p2.x) + ABS(p1.y - p2.y);
}

#endif // MANHATTAN_H

// tesston la fonction manhattan_distance
#include <stdio.h>

int main() {
    point p1 = {3, 4};
    point p2 = {1, 1};

    printf("Distance de Manhattan: %d\n", manhattan(p1, p2));
    return 0;
}


// explication : 

// Définition et déclaration dans le même fichier : Ici, nous avons tout dans un seul fichier manhattan.c. La structure point est définie et la fonction manhattan_distance est également définie dans ce fichier.

//macro ABS : la macro pour calculer la valeur absolue est toujours présente. Cela permet de calculer les différences absolues entre les coordonnées.

//utilison la fonction : Nous ajoutons une petite partie main à la fin du fichier pour tester la fonction manhattan_distance. Cela permet de vérifier que le calcul fonctionne bien sans avoir à séparer les fichiers.


// explications :

// Macro ABS(x) : Cette macro permet de calculer la valeur absolue de x. Elle utilise une expression conditionnelle pour vérifier si x est négatif et renvoie la valeur absolue.

//structure point : Cette structure contient les coordonnées x et y de chaque point dans l'espace.

//fonction manhattan_distance : Cette fonction prend en entrée deux points p1 et p2, et renvoie la somme des valeurs absolues des différences entre leurs coordonnées respectives. C'est la définition de la distance de Manhattan.
