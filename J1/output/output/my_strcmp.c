#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main() {
    const char *str1 = "abc";
    const char *str2 = "abd";
    const char *str3 = "abc";
    const char *str4 = "ab";

    printf("%d\n", my_strcmp(str1, str2)); // Devrait afficher une valeur négative
    printf("%d\n", my_strcmp(str1, str3)); // Devrait afficher 0
    printf("%d\n", my_strcmp(str1, str4)); // Devrait afficher une valeur positive

    return 0;
}
