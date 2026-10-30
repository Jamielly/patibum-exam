#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int j = 0;

    if (ac == 3)
    {
        while (av[1][i] && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
        }
        
        // A MUDANÇA É SÓ AQUI (de diferente do wdmach):
        if (av[1][i] == '\0')
            write(1, "1", 1); // Achou tudo, imprime 1
        else
            write(1, "0", 1); // Faltou letra, imprime 0
    }
    write(1, "\n", 1);
    return (0);
}