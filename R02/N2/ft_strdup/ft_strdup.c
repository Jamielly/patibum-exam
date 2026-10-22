#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i;
    char *dest;
    int len;
    if (!src)
        return (0);
    len = 0;
    while (src[len])
        len++;
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (0);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest); 
}