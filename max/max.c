int max(int* tab, unsigned int len)
{
    unsigned int i;
    int res;
    if (!tab || len == 0)
        return (0);
    res = tab[0];
    i = 1;
    while (i < len)
    {
        if (tab[i] > res)
            res = tab[i];
        i++;
    }
    return (res);
}