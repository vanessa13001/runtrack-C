// count nombre d'octé a écrire

// fd : fd signifie file descriptor

// buf : adresse de la donnée à afficher

// whrite reste plus rapide que printf mais ne génére pas le formatage %d et %s

//printf plus flexible mais plus lent

//malloc allou la mémoire sur le tas

//free libère la mémoire allouée

//whrite affiche le texte bas niveau

// LES POINTEURS :

// pointeur vers une variable (pointeur de base) un pointeur classique est utilisé pour stocker l'adresse d'une variable simple, 
//comme un entier, un caractère, ou tout autre type primitif

// exemple du pointeur vers une variable : 

int a = 10;
int *p = &a;  // p pointe vers l'adresse de a

// pointeur vers un tableau un pointeur peut pointer vers le premier élément d'un tableau, car le nom du tableau est essentiellement un pointeur vers son premier élément

// exemple du pointeur vers un tableau  : 
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;  // p pointe vers le premier élément de arr


// pointeur vers une structure tu peux créer des pointeurs vers des structures, ce qui est très courant dans la manipulation d'objets complexes

// exemple du pointeur vers une structure : 
struct Person {
    char name[50];
    int age;
};

struct Person p1 = {"Alice", 30};
struct Person *ptr = &p1;  // ptr pointe vers l'adresse de p1


// pointeur vers un pointeur (pointeur de pointeur), c'est un pointeur qui pointe vers un autre pointeur. Les pointeurs de pointeurs sont souvent utilisés dans la gestion de tableaux dynamiques de tableaux ou pour des manipulations avancées de la mémoire

// exemple du pointeur vers un autre pointeur :
int a = 10;
int *p = &a;
int **pp = &p;  // pp pointe vers p, qui pointe vers a


// pointeur  vers une fonction , un pointeur vers une fonction permet de stocker l'adresse d'une fonction. Cela peut être utile pour la gestion des rappels (callbacks) ou la création de tables de fonctions

// exemple du pointeur vers une fonction : 
#include <stdio.h>

void hello() {
    printf("Hello, world!\n");
}

int main() {
    void (*func_ptr)() = hello;  // func_ptr pointe vers la fonction hello
    func_ptr();  // Appel de la fonction hello via le pointeur
    return 0;
}

// pointeur vers un tableau de pointeurs un tableau de pointeurs est une structure qui contient plusieurs pointeurs, souvent utilisée pour gérer des chaînes de caractères ou des tableaux dynamiques

// exemple de pointeur vers un tableau de pointeur : 
char *arr[] = {"Hello", "World", "C", "Programming"};


// pointeur de fonction avec des arguments spécifiques : un pointeur vers une fonction avec des arguments spécifiques permet de pointer vers une fonction ayant un certain type de paramètres. Par exemple, un pointeur vers une fonction prenant deux entiers et retournant un entier

// exemple vers une fonction avec arguments spécifiques : 
int add(int a, int b) {
    return a + b;
}

int (*func_ptr)(int, int) = add;  // Pointeur vers une fonction qui prend deux entiers et retourne un entier


// pointeur de type void * (pointeur générique) un pointeur de type void * est un pointeur générique qui peut pointer vers n'importe quel type de données, sans nécessiter de type spécifique. Cependant, avant de déréférencer un pointeur void *, il doit être casté vers le type réel auquel il se réfère

//exemple de pointeur de type void : 
void *ptr;
int x = 5;
ptr = &x;  // ptr peut pointer vers n'importe quel type

// pointeur constant (pointeur vers une constante) un pointeur vers une constante (ou un pointeur constant) est un pointeur qui ne peut pas être utilisé pour modifier la valeur de la variable qu'il pointe

// exemple de pointeur constant : 
const int a = 10;
const int *p = &a;  // p est un pointeur vers une constante (on ne peut pas modifier la valeur de a via p)


// pointeur constant vers un objet constant un pointeur constant vers une constante est un pointeur qui ne peut ni changer l'adresse qu'il contient ni modifier la valeur de la variable à laquelle il pointe

// exemple de pointeur constant vers un objet: 
int a = 10;
int *const p = &a;  // p est un pointeur constant, l'adresse de p ne peut pas changer


// pointeur vers une constante constante un pointeur vers une constante constante est un pointeur dont ni l'adresse ni la valeur pointée ne peuvent être modifiées

// exemple de pointeur vers une constante constante : 
const int a = 10;
const int *const p = &a;  // p ne peut ni pointer vers autre chose ni modifier la valeur à l'adresse

// pointeur nul (NULL) un pointeur nul est un pointeur qui ne pointe vers aucune adresse mémoire valide. Il est souvent utilisé pour indiquer qu'un pointeur n'a pas été initialisé ou qu'une allocation de mémoire a échoué

//exemple de pointeur NULL : 
int *p = NULL;  // p est un pointeur nul, il ne pointe vers aucune adresse valide

// pointeur de type void (void*) le pointeur void* est un pointeur générique qui peut pointer vers n'importe quel type de données. Ce type de pointeur est souvent utilisé pour les fonctions qui manipulent des données de types variés

// exemple de pointeur void : 
void *ptr;
int x = 10;
ptr = &x;  // ptr peut pointer vers n'importe quel type de donnée

// pointeur vers une matrice (pointeur vers un tableau à plusieurs dimensions) en C, un tableau à plusieurs dimensions est essentiellement un tableau de pointeurs, et il est possible de créer des pointeurs vers des tableaux multidimensionnels. Cela permet de manipuler des matrices et des tableaux de manière flexible

// exemple de pointeur vers une matrice :
int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int (*p)[3] = arr;  // p est un pointeur vers un tableau de 3 entiers

// pointeur  constant vers un objet constant (pointeur "const const") ce type de pointeur a deux niveaux de constance : l'adresse qu'il contient ne peut pas être modifiée, et la valeur pointée ne peut pas être modifiée non plus. Il est souvent utilisé pour des constantes dans des fonctions ou pour garantir que les données ne seront pas modifiées

// exemple de pointeur de constant vers un objet constant : 
const int *const p = &a;  // p ne peut pas être modifié, et la valeur pointée non plus

// pointeur  vers un type défini par l'utilisateur (struct) cela se produit lorsqu'on travaille avec des structures définies par l'utilisateur, et on utilise des pointeurs pour manipuler ces structures efficacement

// exemple pointeur vers un type défini par utilisateur :
struct Person {
    char name[50];
    int age;
};

struct Person *p;
struct Person person1 = {"Alice", 25};
p = &person1;  // p pointe vers une instance de la structure Person

// pointeur vers union : les unions permettent de stocker différentes données dans un même emplacement mémoire, mais elles partagent la même adresse. Un pointeur peut être utilisé pour manipuler les données stockées dans une union

// exemple pointeurs vers union : 
#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    union Data *ptr = &data;

    ptr->i = 10;  // utilise le pointeur pour accéder à la donnée de l'union
    printf("Valeur de i : %d\n", ptr->i);

    return 0;
}


union Data {
    int i;
    float f;
    char str[20];
};





// RESUME DES POINTEURS 

// Résumé des types de pointeurs :pointeur vers une variable (de type simple).

//pointeur vers un tableau.

//pointeur vers une structure.

//pointeur de pointeur.

//pointeur vers une fonction.

//pableau de pointeurs.

//pointeur void * (pointeur générique).

//pointeur vers une constante (lecture seule).

//pointeur constant (adresse constante).

//pointeur vers une constante constante (ni l'adresse ni la valeur ne peuvent être modifiées).

//en résumé, il existe de nombreux types de pointeurs en C, chacun ayant des applications spécifiques en fonction de ce que tu veux faire avec les données. La gestion des pointeurs en C est très puissante, mais elle nécessite de bien comprendre les concepts de mémoire pour éviter les erreurs et les fuites de mémoire.