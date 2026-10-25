#include <unistd.h>
void putnbr(int n)
{
    if (n > 9)
        putnbr (n / 10);
    write(1,&"0123456789"[n % 10],1);
} // --> para imprimir o numero inteiro com write

int main(int ac, char **av)
{
    (void)av;
    putnbr(ac - 1); //--> imprime a quantidade de parametros
    write (1,"\n",1);
    return (0); 
}