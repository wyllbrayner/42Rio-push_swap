/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_medium.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_return_stack(t_list *l_a, t_list *l_b, t_pivot pivot, int *srt);
static void	ft_split_stack(t_list *l_a, t_list *l_b, t_pivot pivot);
static int	ft_find_best_sort(t_list *l_b, t_pivot pivot, int value);

void	ft_sort_one_hundred(t_list *l_a, t_list *l_b, int *sort, int first)
{
	t_pivot	pivot;

	pivot.index = 0;
	if (l_a->size > 3)
	{
		pivot = ft_put_pivot(sort, (int)l_a->size, first);
		ft_split_stack(l_a, l_b, pivot);
		ft_sort_one_hundred(l_a, l_b, sort + pivot.index, 0);
	}
	ft_sort_three_a(l_a);
	ft_return_stack(l_a, l_b, pivot, sort);
}

t_pivot	ft_put_pivot(int *sort, int size, int first)
{
	t_pivot	pivot;

	if (size < 10)
		pivot.index = size / 2;
	else if (size < 50)
		pivot.index = size / 3;
	else if (size < 90)
		pivot.index = size / 5;
	else if (size < 110)
		pivot.index = size / 7;
	else if (size < 150)
		pivot.index = size / 9;
	else
		pivot.index = size / 11;
	if (pivot.index > size - 3)
		pivot.index = size - 3;
	pivot.value = sort[pivot.index];
	pivot.qtd = pivot.index;
	pivot.first = first;
	return (pivot);
}

static void	ft_split_stack(t_list *l_a, t_list *l_b, t_pivot pivot)
{
	int	qtd;

	qtd = pivot.qtd;
	while (qtd > 0)
	{
		ft_can_swap(l_a, l_b);
		if (l_a->begin->val < pivot.value)
		{
			l_a->begin->group = pivot.index;
			ft_push_stack(l_a, l_b, "pb");
			qtd--;
		}
		else
			ft_rotato_stack(l_a, "ra");
	}
}

static void	ft_return_stack(t_list *l_a, t_list *l_b, t_pivot pivot, int *srt)
{
	int	reverse;

	if (l_b->begin == NULL)
		return ;
	reverse = 0;
	pivot.index--;
	pivot.group = l_b->begin->group;
	while (l_b->size > 0 && pivot.index >= 0)
	{
		reverse = ft_find_best_sort(l_b, pivot, srt[pivot.index]);
		if (l_b->begin->val == srt[pivot.index])
		{
			ft_push_stack(l_b, l_a, "pa");
			pivot.index--;
			pivot.qtd--;
		}
		else
		{
			if (reverse)
				ft_reverse_rotato_stack(l_b, "rrb");
			else
				ft_rotato_stack(l_b, "rb");
		}
	}
}

static int	ft_find_best_sort(t_list *l_b, t_pivot pivot, int value)
{
	t_node	*node;
	int		count;
	int		max;

	node = l_b->begin;
	count = 0;
	max = pivot.qtd;
	if (pivot.first)
		max = pivot.qtd / 2;
	while (count < max)
	{
		if (node->val == value)
			return (FALSE);
		count++;
		node = node->next;
	}
	return (TRUE);
}
