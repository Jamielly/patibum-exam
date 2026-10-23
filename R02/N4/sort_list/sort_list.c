#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *start;
    int    temp;

    if (!lst)
        return (0);
    start = lst;
    while (lst->next != 0)
    {
        // Se cmp retornar 0, significa que a ordem está errada
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            temp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = temp;
            lst = start; // Volta para o início para reverificar
        }
        else
            lst = lst->next; // Se está certo, avança
    }
    return (start);
}