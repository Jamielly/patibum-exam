#include <unistd.h>
// Biblioteca padrão necessária para usar a função 'write'.

int main (int ac, char **av)
// A função principal onde 'ac' é a quantidade de argumentos e 'av' é um array contendo os argumentos.

{
  int i = 0;      // 'i' será o nosso ponteiro (índice) que vai passear pela string.
  int start;      // Guarda o índice da primeira letra de uma palavra.
  int end;        // Guarda o índice da última letra de uma palavra.

  if (ac == 2)
  // O programa só faz algo se receber exatamente 1 argumento além do nome do programa.

  {
    while (av[1][i])
      i++;
    // Isso é um strlen nativo. Ele empurra o 'i' para frente enquanto o caractere não for '\0'.
    // Quando esse loop termina, 'i' está apontando exatamente em cima do terminador '\0'.

    i--;
    // Recuamos o 'i' uma casa. Agora ele aponta para o último caractere válido da string (antes do '\0').

    while (i >= 0)
    // O loop mestre: vamos varrer a string inteira, de trás para frente, até chegar no começo (índice 0).

    {
      while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
        i--;
      // Fase 1: Limpeza. Se cairmos num espaço ou tabulação no final, voltamos até achar uma letra válida.
      // Como o enunciado diz que não há espaços sobrando, isso raramente roda, mas é uma ótima proteção.

      end = i;
      // Marcamos este índice como o fim da nossa palavra. (A última letra).

      while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t')
        i--;
      // Fase 2: Busca. Continuamos andando para trás, pulando as letras da palavra, até batermos
      // em um espaço, tabulação ou passarmos do começo da string (i virar -1).

      start = i + 1;
      // Como o loop anterior parou em cima do espaço (ou no -1), a nossa palavra começa 
      // uma casa para a direita. Então 'start' recebe 'i + 1'.

      if (start <= end)
      // Proteção de segurança: garante que nós realmente achamos uma palavra para imprimir.

      {
        write (1, &av[1][start], (end - start + 1));
        // A MÁGICA: Em vez de fazer um loop 'while' para imprimir letra por letra, usamos o poder do 'write'.
        // Argumento 1: '1' significa saída padrão (a tela).
        // Argumento 2: '&av[1][start]' passa o endereço de memória de onde a palavra COMEÇA.
        // Argumento 3: '(end - start + 1)' calcula o tamanho exato da palavra.
        // Ex: Se end é 5 e start é 3, (5 - 3 + 1) = 3 letras. Ele imprime o bloco inteiro de uma vez!

        if (i > 0)
          write (1, " ", 1);
        // Se ainda não chegamos no começo da string (i > 0 significa que batemos num espaço e ainda há 
        // coisas pra trás), ele imprime o espaço para separar esta palavra da próxima.
      }
    }
  }
  
  write (1, "\n", 1);
  // Independentemente de qualquer coisa, o programa sempre fecha com uma quebra de linha,
  // como exigido por quase todos os exercícios da 42.
}