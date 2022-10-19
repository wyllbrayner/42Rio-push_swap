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

static	void	ft_free_sort(int **sort);

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

void	ft_free_list(t_list **l_a, t_list **l_b)
{
	if (*l_a)
		ft_list_destroy(l_a);
	if (*l_b)
		ft_list_destroy(l_b);
}

void	ft_free_structs(t_list **l_a, t_list **l_b, int **sort)
{
	ft_free_list(l_a, l_b);
	if (*sort)
		ft_free_sort(sort);
}

static	void	ft_free_sort(int **sort)
{
	int	*tmp;

	tmp = *sort;
	free(tmp);
	*sort = NULL;
}
