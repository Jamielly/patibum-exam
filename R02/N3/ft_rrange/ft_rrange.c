#include <stdlib.h>
int     *ft_rrange(int start, int end)
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
    return(NULL);

  i = 0;
  while (i < size)
  {
    tab[i] = end;
    if (end < start)
      end++;
    else
      end--;
    i++;
  }
  return (tab);
}