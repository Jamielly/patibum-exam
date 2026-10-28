#include <unistd.h>

void putnbr(int n) //--> imprime o numero na tela
{
    if (n > 9)
        putnbr(n / 10); //--> divide ate chegar no primeiro digito (recursao)
    write(1, &"0123456789"[n % 10], 1); //--> converte a matematica em texto e imprime
}

int atoi(char *str) //--> converte o texto do terminal para numero inteiro
{
    int res = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') //--> le os digitos e para se achar letras/lixo
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

int is_prime(int n) //--> valida se o numero é primo
{
    int i = 2; // todo numero primo começa a ser testado pelo 2

    if (n <= 1) //--> 0 e 1 nao sao primos
        return (0);
    
    while (i * i <= n) //--> testa os divisores (ir ate a raiz do numero deixa o codigo rapido)
    {
        if (n % i == 0) //--> se a divisao der resto zero, nao é primo
            return (0);
        i++;
    }
    return (1); //--> ok, é primo
}

int main(int ac, char **av) //--> programa principal
{
    int n;
    int sum = 0; //--> a nossa "sacola" que guarda a soma dos primos

    if (ac == 2) //--> garante que recebeu 1 argumento (ex: ./add_prime_sum 5)
    {
        n = atoi(av[1]); //--> transforma o texto "5" no numero 5

        while (n > 1) //--> contagem regressiva ate chegar no 2
        {
            if (is_prime(n)) //--> confirma se é primo
                sum += n;    //--> se sim, coloca na sacola (sum)
            
            n--; //--> acontece de qualquer forma, vai descendo. Ex: testou 5, agora vira 4, depois 3...
        }
        putnbr(sum); //--> exibe o valor final que juntou na sacola
    }
    else
        write(1, "0", 1); //--> regra do subject: sem argumento, imprime 0
    
    write(1, "\n", 1);
    return (0);
}