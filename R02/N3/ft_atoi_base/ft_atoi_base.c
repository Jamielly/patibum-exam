static int to_value(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (c - '0'); 
    if (c >= 'A' && c <= 'F') 
        c += 32; // Converte 'A'-'F' para 'a'-'f' 
    if (c >= 'a' && c <= 'f') 
        return (c - 'a' + 10); 
    return (-1); 
} 

int ft_atoi_base(const char *nbr, int base) // No exame, a base costuma ser passada como 'int'
{ 
    int res = 0; 
    int sign = 1; 
    int val; 

    // A base não pode ser vazia, e deve estar entre 2 e 16
    // Note que se o ponteiro nbr for nulo na prova, o comportamento oficial é dar segfault (não precisa proteger !nbr)
    // Mas se quiser proteger, não há problema, porém focar nos limites da base é crucial.
    if (base < 2 || base > 16) 
        return (0); 

    // 1. Pula espaços em branco
    while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)) 
        nbr++; 

    // 2. Trata múltiplos sinais (+ e -)
    while (*nbr == '-' || *nbr == '+') 
    { 
        if (*nbr == '-') 
            sign = -sign; // Inverte o sinal toda vez que acha um '-'
        nbr++; 
    } 

    // 3. Converte a base
    while (*nbr) 
    { 
        val = to_value(*nbr); 
        // Se a letra não for hex, ou o valor for maior que a base (ex: '9' na base 8)
        if (val == -1 || val >= base) 
            break; 
        
        res = res * base + val; 
        nbr++; 
    } 
    return (res * sign); 
}
