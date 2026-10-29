#include <stdlib.h>

// 1. Verifica se o caractere é um separador (espaço, tab ou quebra de linha)
int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// 2. Conta quantas palavras existem na string
int count_words(char *str)
{
    int count = 0;
    
    while (*str)
    {
        // Pula os espaços em branco
        while (*str && is_space(*str))
            str++;
        // Se achou um caractere válido, conta a palavra e avança até ela acabar
        if (*str && !is_space(*str))
        {
            count++;
            while (*str && !is_space(*str))
                str++;
        }
    }
    return (count);
}

// 3. Aloca memória e copia apenas uma palavra
char *malloc_word(char *str)
{
    char *word;
    int len = 0;
    int i = 0;

    // Descobre o tamanho da palavra atual
    while (str[len] && !is_space(str[len]))
        len++;
        
    // Aloca memória para a palavra + 1 para o '\0'
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
        
    // Copia os caracteres
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    
    return (word);
}

// 4. A função principal que junta tudo
char **ft_split(char *str)
{
    char **split;
    int words;
    int i = 0;

    // Proteção caso a string seja nula (não cobrado no exame puro, mas boa prática)
    if (!str)
        return (NULL);

    words = count_words(str);
    
    // Aloca o array de strings (+1 para o ponteiro NULL final)
    split = (char **)malloc(sizeof(char *) * (words + 1));
    if (!split)
        return (NULL);

    while (*str)
    {
        // Pula os separadores
        while (*str && is_space(*str))
            str++;
            
        // Se encontrou o começo de uma palavra
        if (*str && !is_space(*str))
        {
            // Salva a palavra no array
            split[i] = malloc_word(str);
            i++;
            
            // Pula a palavra que acabamos de salvar para não repeti-la
            while (*str && !is_space(*str))
                str++;
        }
    }
    
    // Finaliza o array com NULL, como pede o exercício
    split[i] = NULL;
    return (split);
}