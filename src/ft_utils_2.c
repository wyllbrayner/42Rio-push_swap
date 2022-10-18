/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_free_sort(int **sort);

int *ft_order_arr(int *sort, size_t len)
{
    size_t    i;
    size_t    j;
    size_t    aux;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (sort[i] > sort[j])
            {
                aux = sort[i];
                sort[i] = sort[j];
                sort[j] = aux; 
            }
            j++;
        }
        i++;
    }
    return (sort);
}

List	*ft_put_index(List *L, int *sort)
{
	Node	*p;
	size_t	i;

	p = L->begin;
	while (p != NULL)
	{
		i = 0;
		while (i < L->size)
		{
			if (p->val == sort[i])
			{
				p->index = i;
				break ;
			} 
			i++;
		}
		p = p->next;
	}
	return (L);
}

void	ft_free_list(List **L_a, List **L_b)
{
    ft_list_destroy(L_a);
    ft_list_destroy(L_b);
}

void ft_free_structs(List **L_a, List **L_b, int **sort)
{
	ft_free_list(L_a, L_b);
	ft_free_sort(sort);
}

static void	ft_free_sort(int **sort)
{
	int *tmp;

	tmp = *sort;
	free(tmp);
	*sort = NULL;

}