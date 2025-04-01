#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Avant echange: a = %d, b = %d\n", a, b);
    swap(&a, &b); // passer à l'adresse
    printf("Apres echange: a = %d, b = %d\n", a, b);

return 0;

}