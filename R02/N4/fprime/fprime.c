#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int n = atoi(av[1]);
        int div = 2;
        if (n == 1)
            printf("1");
        while (n >= div)
        {
            if (n % div == 0)
            {
                printf("%d",div);
                n /= div;
                if (n > 1)
                    printf("*");
            }
            else
                div++;
        }
    }
    printf ("\n");
}