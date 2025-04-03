#include <stddef.h> // pour NULL

// définition de la structure album
typedef struct Album {
    char *titre;
    struct Album *suivant;
} Album;

// fonction pour ajouter un album en début de liste
void push_front_album(Album **liste, Album *nouvel_album) {
    if (liste == NULL || nouvel_album == NULL) {
        return;
    }
    nouvel_album->suivant = *liste;
    *liste = nouvel_album;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    Album *liste = NULL;

    Album *album1 = (Album *)malloc(sizeof(Album));
    if (album1 == NULL) return 1;
    album1->titre = "album 2";
    album1->suivant = NULL;

    push_front_album(&liste, album1);

    Album *album2 = (Album *)malloc(sizeof(Album));
    if (album2 == NULL) return 1;
    album2->titre = "album 1";
    album2->suivant = NULL;

    push_front_album(&liste, album2);

    Album *temp = liste;
    while (temp) {
        printf("%s\n", temp->titre);
        temp = temp->suivant;
    }

    while (liste) {
        Album *tmp = liste;
        liste = liste->suivant;
        free(tmp);
    }

    return 0;
}

/*
- on définit la structure album avec un titre et un pointeur vers l'album suivant
- la fonction push_front_album ajoute un album au début de la liste :
  - on vérifie que les pointeurs ne sont pas null
  - on fait pointer le nouvel album sur l'ancien premier élément
  - on met à jour le pointeur de tête de liste
- dans main :
  - on initialise la liste à null
  - on crée et alloue dynamiquement deux albums
  - on les ajoute en début de liste avec push_front_album
  - on affiche tous les albums de la liste
  - on libère la mémoire allouée pour éviter les fuites
*/
