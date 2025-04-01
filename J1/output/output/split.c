#include <stdlib.h>
#include <stdio.h>

// Fonction pour compter le nombre de mots dans la chaîne
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;
    
    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Fonction pour copier un mot dans une nouvelle chaîne
char *copy_word(const char *start, const char *end) {
    int length = end - start;
    char *word = (char *)malloc((length + 1) * sizeof(char));
    if (!word) return NULL;
    
    for (int i = 0; i < length; i++) {
        word[i] = start[i];
    }
    word[length] = '\0';
    
    return word;
}

// Fonction principale de séparation de la chaîne
char **split(const char *str) {
    if (!str) return NULL;
    
    int num_words = count_words(str);
    char **result = (char **)malloc((num_words + 1) * sizeof(char *));
    if (!result) return NULL;
    
    int index = 0;
    while (*str) {
        while (*str == ' ' || *str == '\t' || *str == '\n') str++; // Sauter les espaces
        
        if (*str) {
            const char *start = str;
            while (*str && *str != ' ' && *str != '\t' && *str != '\n') str++;
            result[index++] = copy_word(start, str);
        }
    }
    
    result[index] = NULL; // Terminer le tableau par NULL
    return result;
}

// Fonction de test
int main() {
    char str[] = " hello world have fun ";
    char **words = split(str);
    
    for (int i = 0; words[i]; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);
    
    return 0;
}