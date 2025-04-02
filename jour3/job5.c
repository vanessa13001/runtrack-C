
//#include <unistd.h> : Cette bibliothèque permet d'utiliser la fonction write(), qui écrit directement dans la sortie standard (stdout)

// #include <stdlib.h> : Cette bibliothèque est utilisée pour atoi(), qui convertit une chaîne de caractères en entier

#include <unistd.h>
#include <stdlib.h>

// Cette fonction affiche un entier (n) sous forme de texte, en utilisant uniquement write().

//i n > 9, on divise n par 10 et on rappelle ft_putnbr() (récursion). Cela permet d'afficher le nombre chiffre par chiffre dans le bon ordre.

//ensuite, on extrait le dernier chiffre de n (n % 10), on l'ajoute à '0' pour le convertir en caractère, puis on l'affiche avec write()

// fonction pour convertir un entier en chaîne de caractères
void ft_putnbr(int n)  
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

// fonction qui permet de calculer la factorielle
int factorial(int n)
{
    if (n < 0)
        return 0; // factorielle négative non définie
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int n = atoi(argv[1]);
        int result = factorial(n);
        ft_putnbr(result);
        write(1, "\n", 1);
    }
    return 0;
}


// Vérifie s'il y a un argument.

//cnvertit l'argument en entier (atoi) puis calcule la factorielle de l'entier avec une fonction récursive

//affiche le résultat en utilisant uniquement write

// argc == 2 signifie que le programme a été exécuté avec un seul argument après son nom

// argv[1] est la chaîne de caractères contenant le nombre entré par l'utilisateur.

//atoi(argv[1]) le convertit en entier.

// détail : 

// argv[1] = "3"

//atoi("3") → n = 3

//factorial(3) = 6

//ft_putnbr(6) → affiche 6

//write(1, "\n", 1); → affiche une nouvelle ligne.




//EXPLICATION :

// Explications :

//factorielle(int n) : est une fonction récursive pour calculer la factorielle de n

//main(int argc, char *argv[]) : ce sont des arguments 

//le programme vérifie si un argument est passé (argc == 2)

//il convertit l'argument en entier avec atoi

//on calcul  la factorielle qui est effectué, et le résultat est converti en chaîne de caractères

//cette chaîne est ensuite écrite dans la sortie standard avec la fonction write

// puis un saut de ligne est toujours ajouté après le résultat