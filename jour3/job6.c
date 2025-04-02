#include <unistd.h>
#include <stdlib.h>

// Fonction pour convertir un entier en chaîne de caractères
void ft_putnbr(int n)
{
    char c;
    if (n > 9)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

// Fonction pour calculer le nième nombre de Fibonacci
int fibonacci(int n)
{
    if (n <= 1)
        return n;  // Fibonacci(0) = 0, Fibonacci(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);  // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int n = atoi(argv[1]);
        int result = fibonacci(n);
        ft_putnbr(result);
        write(1, "\n", 1);
    }
    return 0;
}
