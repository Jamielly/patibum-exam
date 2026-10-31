#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int end;

    if (ac > 1)
    {
        // 1. Pula espaços iniciais
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;

        // 2. Salva as coordenadas da primeira palavra
        start = i;
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;

        // 3. Pula os espaços depois da primeira palavra
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;

        // 4. Imprime o resto da string palavra por palavra
        while (av[1][i])
        {
            // Se for uma letra, imprime
            if (av[1][i] != ' ' && av[1][i] != '\t')
            {
                write(1, &av[1][i], 1);
                i++;
            }
            // Se bater num espaço e a próxima letra NÃO for um espaço (e nem fim de string)
            // significa que terminamos uma palavra e vamos começar outra, então imprime 1 espaço
            else if ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] != ' ' && av[1][i + 1] != '\t' && av[1][i + 1] != '\0')
            {
                write(1, " ", 1);
                i++;
            }
            // Senão, é só espaço sobrando, então apenas ignora e pula
            else
            {
                i++;
            }
        }

        // 5. Imprime a primeira palavra no final
        if (start < end) // Se a primeira palavra existe
        {
            // Se o 'i' for maior que o 'end', significa que tinha outras palavras no meio,
            // então precisamos imprimir um espaço antes de jogar a primeira pro final.
            if (i > end) 
                write(1, " ", 1);
            
            // Imprime a 1ª palavra de uma vez só usando o tamanho dela
            write(1, &av[1][start], end - start);
        }
    }
    write(1, "\n", 1);
    return(0);
}

==============OU SIMPLIFICADO======================================================

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    int start;
    int end;

    if (ac > 1)
    {
        // 1. Pula espaços iniciais e salva as coordenadas da primeira palavra
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        
        start = i;
        while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;

        // 2. Procura as próximas palavras. Ao achar, imprime a palavra e 1 espaço.
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            
            if (av[1][i]) // Se não chegou no final, achou uma nova palavra
            {
                while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
                {
                    write(1, &av[1][i], 1);
                    i++;
                }
                write(1, " ", 1); // Adiciona um espaço fixo após cada palavra extra
            }
        }

        // 3. Imprime a primeira palavra por último (se houver alguma)
        if (start < end)
            write(1, &av[1][start], end - start);
    }
    write(1, "\n", 1);
    return (0);
}
