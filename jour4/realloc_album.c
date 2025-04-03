#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure représentant un album
typedef struct {
    char title[100];
    int year;
} Album;

Album* realloc_album(Album* albums, size_t, size_t new_size) {
    // Utilisation de realloc pour redimensionner le tableau
    Album* new_albums = (Album*)realloc(albums, new_size * sizeof(Album));
    if (new_albums == NULL) {
        return NULL; // Allocation échouée
    }
    return new_albums;
}

int main() {
    size_t old_size = 2, new_size = 4; 
    Album* albums = (Album*)malloc(old_size * sizeof(Album)); // Allocation initiale
    if (albums == NULL) {
        return 1; // erreur d'allocation 
    }

    // on initialise des albums
    strcpy(albums[0].title, "Album 1");
    albums[0].year = 1990;
    strcpy(albums[1].title, "Album 2");
    albums[1].year = 1995;

    // Réallocation
    albums = realloc_album(albums, old_size, new_size);
    if (albums == NULL) {
        return 1; // erreur de réallocation
    }

    // Ajout de nouveaux albums après la réallocation
    strcpy(albums[2].title, "Album 3");
    albums[2].year = 1998;
    strcpy(albums[3].title, "Album 4");
    albums[3].year = 2002;

    // Affichage des albums après réallocation
    for (size_t i = 0; i < new_size; i++) {
        printf("Album %zu: %s (%d)\n", i + 1, albums[i].title, albums[i].year);
    }

    // Libération finale de la mémoire
    free(albums);

    return 0;
}


//realloc est une solution possible, mais elle :

//peut déplacer les données si la mémoire initiale ne peut pas être étendue, ne garantit pas que les nouveaux espaces car sont initialisés 

//ne copie pas automatiquement les données, il faut gérer cela proprement? en utilisant malloc + free + et une copie manuelle, on garde le contrôle total sur la gestion de la mémoire