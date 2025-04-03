#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la structure  qui représente un album
typedef struct album_list {
    char *title;
    char *artist;
    int year;
    struct album_list *next; 
} Album;

// fonction pour créer un album
Album* create_album(const char *artist, const char *title, int year) {
    // allocation mémoire pour l'album
    Album *new_album = (Album*)malloc(sizeof(Album));
    if (new_album == NULL) {
        return NULL; // echec de l'allocation
    }

    // allocation et copie du titre
    new_album->title = (char*)malloc(strlen(title) + 1);
    if (new_album->title == NULL) {
        free(new_album); // Libération mémoire en cas d'erreur
        return NULL;
    }
    strcpy(new_album->title, title);

    // Allocation et copie de l'artiste
    new_album->artist = (char*)malloc(strlen(artist) + 1);
    if (new_album->artist == NULL) {
        free(new_album->title);
        free(new_album);
        return NULL;
    }
    strcpy(new_album->artist, artist);

    // Assignation des autres valeurs
    new_album->year = year;
    new_album->next = NULL; // initinialiser à NULL

    return new_album; // return au nouvel nouvel album
}

// fonction pour afficher un album (optionnel pour tester)
void print_album(Album *album) {
    if (album != NULL) {
        printf("Titre : %s\nArtiste : %s\nAnnee : %d\n", album->title, album->artist, album->year);
    }
}

// liibération de la mémoire allouée pour un album
void free_album(Album *album) {
    if (album != NULL) {
        free(album->title);
        free(album->artist);
        free(album);
    }
}

// exemple d'utilisation
int main() {
    Album *my_album = create_album("Pink Floyd", "The Dark Side of the Moon", 1973);
    if (my_album != NULL) {
        print_album(my_album);
        free_album(my_album); // libérer la mémoire après utilisation
    } else {
        printf("echec de la creation de l'album\n");
    }
    return 0;
}
