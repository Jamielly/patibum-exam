#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;

    // Proteção: Se a lista não existe ou chegou ao fim, para a recursão
    if (begin_list == NULL || *begin_list == NULL)
        return;

    // Se o cmp retornar 0, significa que os dados são iguais e devemos remover este nó
    if (cmp((*begin_list)->data, data_ref) == 0)
    {
        // 1. Salva o nó atual em uma variável temporária
        temp = *begin_list;
        
        // 2. Faz o ponteiro da lista pular o nó atual e apontar para o próximo
        *begin_list = (*begin_list)->next;
        
        // 3. Libera a memória do nó isolado
        free(temp);
        
        // 4. Chama a função de novo no MESMO ponteiro (pois o novo nó atual também pode precisar ser removido)
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        // Se não for para remover, avança para testar o próximo nó
        ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
    }
}