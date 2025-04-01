#include <stdlib.h>
#include <stdio.h>

// Fonction pour supprimer les espaces en début et en fin de chaîne
char *trim(const char *str) {
    if (!str) return NULL;
    
    // Trouver le début sans espaces
    while (*str == ' ' || *str == '\t' || *str == '\n') str++;
    
    // Si la chaîne ne contient que des espaces
    if (*str == '\0') return (char *)malloc(1);
    
    // Trouver la fin sans espaces
    const char *end = str;
    while (*end) end++;
    end--;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) end--;
    
    // Calcul de la longueur de la nouvelle chaîne
    int length = end - str + 1;
    char *trimmed_str = (char *)malloc((length + 1) * sizeof(char));
    if (!trimmed_str) return NULL;
    
    // Copier la chaîne sans les espaces
    for (int i = 0; i < length; i++) {
        trimmed_str[i] = str[i];
    }
    trimmed_str[length] = '\0';
    
    return trimmed_str;
}

// Fonction de test
int main() {
    char str[] = "   hello world   ";
    char *trimmed = trim(str);
    
    printf("'%s'\n", trimmed);
    free(trimmed);
    
    return 0;
}
