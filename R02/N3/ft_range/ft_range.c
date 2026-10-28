#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i;
    int *tab;
    int size;

    if (start <= end)
        size = end - start + 1;
    else 
        size = start - end + 1;
    
    tab = malloc(sizeof(int) * size);
    if (!tab)
        return (NULL);

    i = 0;
    while (i < size)
    {
        tab[i] = start;
        if (start < end)
            start++;
        else
            start--;
        i++;
    }
    return (tab);
}