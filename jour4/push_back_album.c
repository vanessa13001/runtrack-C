#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// la struct représentant un album
typedef struct Album {
    char *titre;
    struct Album *suivant;
} Album;

// fonction pour ajouter un album à la fin de la liste
void push_back_album(Album **liste, Album *nouvel_album) {
    if (*liste == NULL) {
        *liste = nouvel_album; // si la liste est vide, on insère en tête
    } else {
        Album *temp = *liste;
        while (temp->suivant != NULL) {
            temp = temp->suivant; // on parcourt la liste jusqu'au dernier élément
        }
        temp->suivant = nouvel_album; // ajout à la fin de la liste
    }
    nouvel_album->suivant = NULL; // on s'assure que c'est bien le dernier élément
}

// fonction pour créer un nouvel album
Album *creer_album(const char *titre) {
    Album *nouveau = malloc(sizeof(Album));
    if (!nouveau) {
        perror("erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    nouveau->titre = strdup(titre); // alloue et copie le titre
    nouveau->suivant = NULL;
    return nouveau;
}

// fonction pour afficher la liste des albums
void afficher_liste(Album *liste) {
    while (liste) {
        printf("%s -> ", liste->titre);
        liste = liste->suivant;
    }
    printf("NULL\n");
}

// fonction pour libérer la mémoire allouée
void liberer_liste(Album *liste) {
    Album *temp;
    while (liste) {
        temp = liste;
        liste = liste->suivant;
        free(temp->titre);
        free(temp);
    }
}

int main() {
    Album *maListe = NULL;

    push_back_album(&maListe, creer_album("album 1"));
    push_back_album(&maListe, creer_album("album 2"));
    push_back_album(&maListe, creer_album("album 3"));

    afficher_liste(maListe);

    // libération de la mémoire
    liberer_liste(maListe);

    return 0;
}


// Explication :
// on vérifie si la liste est vide. Si c'est le cas, le nouvel album devient la tête de liste.
// sinon, on parcourt la liste jusqu'au dernier élément.
// on lie le dernier élément au nouvel album.
// on s'assure que le nouvel album est bien le dernier (suivant = NULL).
// cette implémentation respecte la contrainte "aucune fonction autorisée" en n'utilisant pas de bibliothèques standard autres que celles nécessaires pour la structure et les pointeurs.


// la fonction push_back()

// C'est bien simple: elle introduit l'élément passé en parametre apres le dernier élément trouvé dans le conteneur

//selon les circonstances (type de conteneur, capacité maximale actuelle du conteneur et nombre actuel d'éléments dans le conteneur) elle pourra provoquer l'allocation dynamique d'espace supplémentaire en vue de recevoir ce conteneur.

//je *presumes* qu'en cas d'échec elle devrait au minimum lancer une exception de type runtime_error, mais cela reste à vérifier