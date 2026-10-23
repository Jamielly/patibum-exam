#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    char c;
    int k = 1;

    if (ac >= 2)
    {
        while (k < ac)
        {
            i = 0;
            while (av[k][i])
            {
                c = av[k][i];
                if (c >= 'A' && c <= 'Z')
                    c += 32;
                if ((c >= 'a' && c <= 'z') && (av[k][i + 1] == ' ' || av[k][i + 1] == '\t' || av[k][i + 1] == '\0'))
                    c -= 32;
                write(1, &c, 1);
                i++;
            }
        write (1,"\n",1);
        k++;
        }
    }
    else
        write(1, "\n", 1);
}