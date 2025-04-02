#include <stdio.h>
#include <stdbool.h>

#define N 9  // taille de la grille 9x9

// fonction qui permet de vérifier si un nombre peut être placé en toute sécurité
bool isSafe(int grid[N][N], int row, int col, int num) {
    // verifier si le nombre existe déjà dans la ligne
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // verifier si le nombre existe déjà dans la colonne
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // verifier si le nombre existe déjà dans le sous-carré 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (grid[r][c] == num) {
                return false;
            }
        }
    }

    return true;  // Le nombre peut être placé en toute sécurité
}

// fonction pour résoudre le Sudoku avec backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool empty = true;

    // chercher une case vide
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {  // Case vide
                empty = false;
                break;
            }
        }
        if (!empty) break;
    }

    // si aucune case vide n'est trouvée, le Sudoku est résolu
    if (empty) {
        return true;
    }

    // tester les valeurs de 1 à N pour cette case vide
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;  // Placer le numéro

            // appel récursif pour résoudre le reste du Sudoku
            if (solveSudoku(grid)) {
                return true;
            }

            // backtracking : réinitialiser la case à 0
            grid[row][col] = 0;
        }
    }

    // aucune valeur ne peut être placée, retourner false
    return false;
}

// fonction pour afficher la grille de Sudoku
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Fonction principale
int main() {
    // Exemple de grille de Sudoku à résoudre
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Appel à la fonction solveSudoku pour résoudre la grille
    if (solveSudoku(grid)) {
        printf("Solution trouvee !\n");
        // Afficher la grille résolue
        printGrid(grid);
    } else {
        printf("aucune solution n'existe.\n");
    }

    return 0;
}



// isSafe :

//ette fonction vérifie si un numéro donné peut être placé à la position (row, col) dans la grille sans enfreindre les règles du Sudoku. Elle effectue trois vérifications :

//le numéro ne doit pas être dans la même ligne.

//le numéro ne doit pas être dans la même colonne.

//le numéro ne doit pas être dans le même sous-carré 3x3


// solveSudoku :

//cette fonction est l'implémentation du backtracking. Elle recherche d'abord la première case vide. Si aucune case vide n'est trouvée, le Sudoku est déjà résolu. Ensuite, elle essaie de remplir cette case avec des numéros de 1 à 9. Si un numéro est valide (vérifié par la fonction isSafe), elle le place et appelle récursivement solveSudoku pour résoudre le reste de la grille. Si à un moment donné, aucune valeur valide ne peut être placée, elle revient en arrière (backtrack) et réinitialise la case à 0


// Le backtracking est une technique algorithmique utilisée pour résoudre des problèmes de recherche ou d'optimisation, en particulier dans des espaces de recherche combinatoires (comme les problèmes de Sudoku, les puzzles, les problèmes de graphes

// Le backtracking fonctionne en construisant progressivement une solution, en ajoutant étape par étape des choix (appelés "états" ou "décisions"). À chaque étape, il vérifie si le choix est valide. Si le choix mène à une impasse, l'algorithme revient en arrière (backtrack) et essaie une autre voie. Cela permet de ne pas explorer inutilement des solutions qui sont vouées à l'échec

// Processus de Backtracking :
//choix initial :

// l'algorithme commence par la première case vide (celle à la position (0,2)).

//essayer le numéro 1 :

//il essaie de remplir cette case avec un 1, mais comme 1 est déjà dans la colonne, il échoue.

//essayer le numéro 2 :

//il essaie ensuite de remplir la case avec un 2. Cela fonctionne (pas de conflits), alors il passe à la case suivante.

//réussite partielle :

//l'algorithme continue à remplir les cases suivantes de la même manière. Si à un moment donné, une case ne peut pas être remplie, il revient en arrière (backtrack) et essaie un autre numéro pour la case précédente.

//revenir en arrière (backtracking) :

//si l'algorithme se rend compte qu'une solution complète n'est pas possible à un certain point, il annule les derniers choix et essaie une nouvelle voie.

//exemple de retour en arrière :
//disons que l'algorithme a rempli jusqu'à la case (3, 4) et se rend compte qu'il ne peut plus avancer.

//il reviendra à la case précédente (3, 3) et essaiera un autre numéro, puis continuera l'exploration.

//la conclusion :

//le backtracking est une méthode extrêmement utile pour résoudre des problèmes où il y a plusieurs solutions possibles, mais il faut vérifier à chaque étape si une solution partielle est valable. Si ce n'est pas le cas, l'algorithme revient en arrière et essaie d'autres options. Il est largement utilisé dans des problèmes comme le Sudoku, les puzzles, la recherche dans les graphes, etc.