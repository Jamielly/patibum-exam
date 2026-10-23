#include <unistd.h>

void putnbr(int n)
{
    if (n >= 10)
        putnbr(n / 10);
    char c = (n % 10) + '0';
    write(1, &c, 1);
}

int is_prime(int n)
{
    int i = 2;
    while (i * i <= n && n % i != 0)
        i++;
    return (n >= 2 && i * i > n);
}

int main(int ac, char **av)
{
    int n = 0;
    int sum = 0;

    if (ac == 2)
    {
        while (*av[1] >= '0' && *av[1] <= '9')
            n = n * 10 + (*av[1]++ - '0');
        while (n >= 2)
        {
            if (is_prime(n))
                sum += n;
            n--;
        }
    }
    putnbr(sum);
    write(1, "\n", 1);
    return (0);
}