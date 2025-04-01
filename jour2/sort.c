#include <stdio.h>
#include <string.h>

void sort(char *arr[]) {
    if (!arr) return;
    
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; arr[i] && arr[i + 1]; i++) {
            if (strcmp(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    char *arr[] = {"zebra", "apple", "banana", "orange", NULL};
    
    sort(arr);
    
    for (int i = 0; arr[i]; i++) {
        printf("%s\n", arr[i]);
    }
    
    return 0;
}

// cette fonction utilise un tri à bulles pour organiser les chaînes dans l’ordre ASCII croissant, le programme principal permet de tester la fonction avec un tableau d’exemple.