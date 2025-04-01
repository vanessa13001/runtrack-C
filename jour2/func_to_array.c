#include <stdio.h>
#include <ctype.h>

// fonction qui applique une fonction à chaque élément d'un tableau de chaînes
void func_to_array(char **array, void (*func)(char *)) {
    if (!array || !func) return;
    
    for (int i = 0; array[i] != NULL; i++) {
        func(array[i]);
    }
}

// exemple de fonction qui met une chaîne en majuscules
void strtoupper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// exemple de fonction qui met une chaîne en minuscules
void strtolower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// exemple de fonction qui affiche une chaîne
void my_putstr(char *str) {
    printf("%s\n", str);
}

// programme de test avec le main 
int main() {
    char *words[] = {"Hello", "World", "Test", NULL};
    
    printf("Original:\n");
    func_to_array(words, my_putstr);
    
    printf("\nUppercase:\n");
    func_to_array(words, strtoupper);
    func_to_array(words, my_putstr);
    
    printf("\nLowercase:\n");
    func_to_array(words, strtolower);
    func_to_array(words, my_putstr);
    
    return 0;
}


// la bibliotheque ctype.h est utiliser pour toupper et tolower qui permet de convertir en minuscule et majuscule
// Applique une fonction à chaque élément d'un tableau de chaînes

//fournit des exemples de fonctions (strtoupper, strtolower, my_putstr)

//teste func_to_array avec plusieurs transformations