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

int	*ft_order_arr(int *sort, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	aux;

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

t_list	*ft_put_index(t_list *l, int *sort)
{
	t_node	*p;
	size_t	i;

	p = l->begin;
	while (p != NULL)
	{
		i = 0;
		while (i < l->size)
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
	return (l);
}
