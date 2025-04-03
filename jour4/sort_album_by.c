#include <stdio.h>
#include <string.h>

typedef struct {
    char *title;
    int year;
    char *artist;
} Album;

/* 
fonction de comparaison pour trier par titre 
compare les titres des albums avec strcmp et retourne un entier pour déterminer l'ordre 
*/
int compare_by_title(const void *a, const void *b) {
    return strcmp(((Album *)a)->title, ((Album *)b)->title);
}

/* 
fonction de comparaison pour trier par année de sortie 
retourne la différence entre les années des deux albums 
*/
int compare_by_year(const void *a, const void *b) {
    return ((Album *)a)->year - ((Album *)b)->year;
}

/* 
fonction de tri des albums, utilisant la fonction de comparaison passée en paramètre 
elle prend en entrée un tableau d'albums, son nombre et un pointeur vers une fonction de comparaison 
elle utilise un algorithme de tri à bulle pour trier les albums selon la fonction de comparaison fournie 
*/
void sort_album_by(Album *albums, int album_count, int (*compare)(const void *, const void *)) {
    for (int i = 0; i < album_count - 1; i++) {
        for (int j = i + 1; j < album_count; j++) {
            if (compare(&albums[i], &albums[j]) > 0) {
                // échange des albums
                Album temp = albums[i];
                albums[i] = albums[j];
                albums[j] = temp;
            }
        }
    }
}

/* 
fonction pour afficher la liste des albums 
affiche les informations de chaque album dans le tableau 
*/
void print_albums(Album *albums, int album_count) {
    for (int i = 0; i < album_count; i++) {
        printf("Titre: %s, Annee: %d, Artiste: %s\n", albums[i].title, albums[i].year, albums[i].artist);
    }
}

int main() {
    // exemple d'album
    Album albums[] = {
        {"slow down", 2016, "chase atlantic"},
        {"invisible", 2024, "bouss"},
        {"talk", 2022, "yeat"},
        {"heat waves", 2020, "glass animal"}
    };
    int album_count = sizeof(albums) / sizeof(albums[0]);

    printf("Albums avant tri par titre :\n");
    print_albums(albums, album_count);

    // tri par titre
    sort_album_by(albums, album_count, compare_by_title);
    printf("\nAlbums trie par titre :\n");
    print_albums(albums, album_count);

    // tri par année
    sort_album_by(albums, album_count, compare_by_year);
    printf("\nAlbums trie par annee :\n");
    print_albums(albums, album_count);

    return 0;
}
