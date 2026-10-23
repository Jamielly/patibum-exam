int to_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'A' && c <= 'Z')
        c += 32;
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int val;

    if (!str || str_base < 2 || str_base > 16)
        return (0);

    // 1. Trata o sinal apenas se for o primeiríssimo caractere
    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    // 2. Itera caractere por caractere
    while (*str)
    {
        val = to_value(*str);

        // Se não for dígito hexadecimal ou for maior/igual à base, para
        if (val == -1 || val >= str_base)
            break;

        // 3. Aplica o deslocamento da base e soma o novo dígito
        res = res * str_base + val;
        str++;
    }
    return (res * sign);
}