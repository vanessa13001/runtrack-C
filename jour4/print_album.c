#include <stdio.h>


// def de la structure album
struct album 
{
    int annee;     // année de sortie
    char nom[100]; // nom de l'album
    char titre[100]; // nom du groupe
};


// fonction pour afficher les informations de l'album
void print_album(struct album *alb) 
{
    printf("\"%s\" by \"%s\" released in %d.\n", alb->nom, alb->titre, alb->annee);
}

int main(void) 
{
    // on créeb le nom de l'album
    struct album alb1 = {1986, "Master of puppets", "Metallica"}; 

    // on affiche l'album
    print_album(&alb1); // on print le nom de lalbum

    return 0;
}









// explication : 

// Structure album : les attributs sont définis avec des types appropriés. nom et titre sont des chaînes de caractères (char[]), et annee est un entier pour représenter l'année de sortie de l'album.

//fnction print_album : cette fonction prend en paramètre un pointeur vers une structure album et affiche les informations dans le format demandé avec printf.

//dans main : j'initialise un album alb1 avec les informations de "Master of Puppets" et j'appelle print_album pour afficher ces informations.