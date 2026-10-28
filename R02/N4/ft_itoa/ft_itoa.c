#include <stdlib.h>

char *ft_itoa(int nbr)
{
    long n = nbr;
    int len = 0;
    long temp;
    char *str;

    // Se o número for menor ou igual a 0, precisamos contar 1 caractere a mais (para o '-' ou para o '0')
    if (n <= 0)
        len = 1;
    
    temp = n;
    if (temp < 0)
        temp = -temp;
    
    // Conta quantos dígitos o número tem
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }

    // Aloca a memória para a string (+1 para o '\0')
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    
    str[len] = '\0';

    // Caso especial para o zero
    if (n == 0)
    {
        str[0] = '0';
        return (str);
    }

    // CORREÇÃO: Se o número for negativo, adiciona o '-' e o torna positivo
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }

    // Preenche a string de trás para frente
    while (n > 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }

    return (str);
}