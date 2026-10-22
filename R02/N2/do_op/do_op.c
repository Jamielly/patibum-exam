#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int first;
    int second;
    int op;

    if (ac == 4)
    {
        first = atoi(av[1]);
        second = atoi(av[3]);
        op = av[2][0];

        if (op == '+')
            printf("%d", first + second);
        else if (op == '-')
            printf("%d", first - second);
        else if (op == '*')
            printf ("%d", first * second);
        else if (op == '/')
            printf ("%d", first / second);
        else if (op == '%')
            printf ("%d", first % second);
    }
    printf ("\n");
}