#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
    if (ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        if (a > 0 && b > 0)
        {
            while (b != 0)
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            printf ("%d", a);
        }
    }
    printf ("\n");
}