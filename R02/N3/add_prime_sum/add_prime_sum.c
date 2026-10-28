#include <unistd.h>
void putnbr(int n) //--> para imprimir o numero
{
    if (n > 9)
        putnbr (n / 10);
    write (1,&"0123456789"[n % 10],1);
}

int atoi(char *str) //-->para numeros positivos
{
    int res = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

int is_prime(int n) //--> validar para numero primo
{
    int i = 2;
    if (n <= 1)
        return (0);
    
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1); //--> ok, é primo
}
int main(int ac, char **av) //--> programa principal simplificado, semelhante a fprime do N4
{
    int n;
    int sum = 0;
    if (ac == 2)
    {
        n = atoi(av[1]);

        while (n > 1)
        {
        if (is_prime(n))
            sum += n;
        n--;
        }
    putnbr(sum);
    }
    else
        write(1,"0",1);
    write(1,"\n",1);
}
