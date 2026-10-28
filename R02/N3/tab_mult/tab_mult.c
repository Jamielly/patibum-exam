#include <unistd.h>
void putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    write(1,&"0123456789"[n % 10],1);
}

ft_atoi (char *str)
{
    int res = 0;
    while (*str)
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res);
}

int main(int ac, char **av)
{
    int i = 1;
    int n;

    if (ac == 2)
    {
        n = atoi(av[1]); //--> a partir daqui todos possuem uma main semelhante!
        while (i <= 9)
        {
            putnbr(i); //--> trata um valor interior por isso usa o putnbr
            write (1," x ",3);
            putnbr(n);//-->trata de converter a entrada pra str
            write(1," = ",3);
            putnbr(i * n);
            write (1,"\n",1);
            i++;
        }
    }
    else
        write (1,"\n",1);
}