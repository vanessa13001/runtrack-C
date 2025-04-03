#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// définition de la structure d'un album
typedef struct album {
    char *title;
    struct album *next;
} album;

// fonction pour afficher la liste (utile pour le débogage)
void print_list(album *head) {
    album *temp = head;
    while (temp != NULL) {
        printf("album: %s\n", temp->title);
        temp = temp->next;
    }
}

// fonction pour supprimer un album de la liste
void album_del_one(album **head, const char *title) {
    if (head == NULL || *head == NULL) {
        printf("la liste est vide ou le pointeur est invalide.\n");
        return;  // vérifier que la liste n'est pas vide
    }

    album *temp = *head;

    // cas où l'album à supprimer est en tête de liste
    if (strcmp(temp->title, title) == 0) {
        printf("suppression de l'album en tête: %s\n", temp->title);
        *head = temp->next;  // faire pointer head sur l'album suivant
        free(temp->title);   // libérer la mémoire allouée pour le titre
        free(temp);          // libérer l'album lui-même
        return;
    }

    // recherche de l'album à supprimer
    album *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("suppression de l'album: %s\n", temp->title);
            prev->next = temp->next;  // faire pointer le précédent sur l'album suivant
            free(temp->title);        // libérer le titre de l'album
            free(temp);               // libérer l'album lui-même
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // si l'album n'a pas été trouvé
    printf("l'album \"%s\" n'a pas ete trouve dans la liste.\n", title);
}

// exemple de fonction pour ajouter un album (utile pour tester)
album* add_album(album *head, const char *title) {
    album *new_album = (album*)malloc(sizeof(album));
    new_album->title = strdup(title);
    new_album->next = head;
    return new_album;
}

// fonction principale de test
int main() {
    album *head = NULL;

    // ajout d'albums pour tester
    head = add_album(head, "album 3");
    head = add_album(head, "album 2");
    head = add_album(head, "album 1");

    printf("liste avant suppression:\n");
    print_list(head);

    // suppression d'un album
    album_del_one(&head, "album 2");

    printf("liste apres suppression:\n");
    print_list(head);

    // suppression d'un album qui n'existe pas
    album_del_one(&head, "album 4");

    printf("liste finale:\n");
    print_list(head);

    // libérer la mémoire
    while (head != NULL) {
        album *temp = head;
        head = head->next;
        free(temp->title);
        free(temp);
    }

    return 0;
}


/*
fonction print_list : permet d'afficher les albums dans la liste avant et après la suppression pour observer les changements
messages de débogage : des messages sont ajoutés pour indiquer si l'album à supprimer a été trouvé et supprimé, ou si la liste est vide
fonction add_album : une fonction pour ajouter un album à la liste, utile pour tester la suppression
test dans main : ajout d'albums, suppression et affichage avant/après la suppression pour vérifier le bon fonctionnement de la suppression
*/

/*
**head : 
**head fait référence à un pointeur de pointeur sur une structure album, un pointeur (comme album *head) est une variable qui contient l'adresse mémoire d'un objet, ici un objet de type album

un pointeur de pointeur (album **head) est un pointeur qui contient l'adresse d'un autre pointeur, dans ce cas, il pointe vers le pointeur qui contient l'adresse du premier album de la liste

cela est utilisé ici pour pouvoir modifier directement le début de la liste dans la fonction (car la liste peut changer après la suppression de l'album).

&& signification : 
l'opérateur && est un opérateur logique "et" en c, il est utilisé pour vérifier deux conditions simultanément, les deux conditions doivent être vraies pour que l'expression entière soit vraie

exemple :

if (temp != NULL && strcmp(temp->title, title) == 0)
temp != NULL vérifie si le pointeur temp n'est pas NULL (si la liste n'est pas vide)

strcmp(temp->title, title) == 0 vérifie si le titre de l'album courant (temp->title) est identique à celui passé en paramètre (title)
si les deux conditions sont vraies, l'album est trouvé et il sera supprimé

strcmp signification :

strcmp est une fonction de la bibliothèque standard en c qui compare deux chaînes de caractères
la syntaxe est strcmp(str1, str2), où str1 et str2 sont les deux chaînes de caractères à comparer

la fonction renvoie :
0 si les deux chaînes sont identique
un nombre négatif si str1 est "plus petit" que str2 dans l'ordre lexicographique
un nombre positif si str1 est "plus grand" que str2

dans le code, strcmp(temp->title, title) compare le titre de l'album courant avec celui passé en paramètre. si les titres sont identiques, strcmp retourne 0

temp :
temp est un pointeur qui parcourt la liste des albums

temp commence par pointer vers le premier album de la liste, c'est-à-dire *head

ensuite, temp est déplacé à travers la liste à chaque itération de la boucle while ça permet de parcourir tous les albums jusqu'à ce que celui à supprimer soit trouvé

si l'album à supprimer est trouvé, temp sera le pointeur vers cet album.
*/
