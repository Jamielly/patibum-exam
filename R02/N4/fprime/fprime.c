#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int n;
    int div = 2;

    if (ac == 2)
    {
        n = atoi(av[1]);
        
        if (n == 1)
            printf("1");
        
        // Alterado: Permite que div seja igual a n (para imprimir o último primo)
        while (n >= div) 
        {
            // Alterado: Verifica se 'div' é realmente um divisor de 'n'
            if (n % div == 0) 
            {
                printf("%d", div);
                n /= div;
                
                // Só imprime o asterisco se ainda sobrarem fatores
                if (n > 1)
                    printf("*");
            }
            else
            {
                // Só avança para o próximo número se não for divisível pelo atual
                div++;
            }
        }
    }
    printf("\n");
    return (0);
}
