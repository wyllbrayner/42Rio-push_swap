/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_easy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_sort_five_aux(t_list *l_a);

void	ft_sort_two(t_list *l_a)
{
	ft_swap_stack(l_a, "sa");
}

void	ft_sort_three_a(t_list *l_a)
{
	t_node	*p[3];

	p[0] = l_a->begin;
	p[1] = p[0]->next;
	p[2] = l_a->end;
	while (l_a->ret == 0)
	{
		if ((p[0]->val > p[1]->val) && (p[0]->val > p[2]->val))
			ft_rotato_stack(l_a, "ra");
		else if ((p[0]->val > p[1]->val && p[0]->val < p[2]->val)
			|| (p[0]->val < p[1]->val && p[0]->val > p[2]->val))
		{
			if ((p[1]->val < p[0]->val) && (p[1]->val < p[2]->val))
				ft_swap_stack(l_a, "sa");
			else
				ft_reverse_rotato_stack(l_a, "rra");
		}
		else
			ft_reverse_rotato_stack(l_a, "rra");
		p[0] = l_a->begin;
		p[1] = p[0]->next;
		p[2] = l_a->end;
		l_a = ft_valid_input_order_asc(l_a);
	}
}

void	ft_sort_five(t_list *l_a, t_list *l_b)
{
	t_node	*p[2];

	p[0] = l_a->begin;
	p[1] = l_a->end;
	while ((ft_list_size(l_b) != 0) || (l_a->ret == 0))
	{
		ft_sort_five_aux(l_a);
		l_a = ft_valid_input_order_asc(l_a);
		if (l_a->ret == 0)
			ft_push_stack(l_a, l_b, "pb");
		l_a = ft_valid_input_order_asc(l_a);
		if ((ft_list_size(l_a) == 3) && (l_a->ret == 0))
			ft_sort_three_a(l_a);
		l_b = ft_valid_input_order_desc(l_b);
		if ((ft_list_size(l_b) == 2) && (l_b->ret == 0))
			ft_swap_stack(l_b, "sb");
		l_a = ft_valid_input_order_asc(l_a);
		l_b = ft_valid_input_order_desc(l_b);
		if (l_a->ret != 0 && (l_b->ret != 0 && ft_list_size(l_b) != 0))
			ft_push_stack(l_b, l_a, "pa");
		p[0] = l_a->begin;
		p[1] = l_a->end;
		l_a = ft_valid_input_order_asc(l_a);
	}
}

static void	ft_sort_five_aux(t_list *l_a)
{
	t_node	*p[2];

	p[0] = l_a->begin;
	p[1] = l_a->end;
	if (p[0]->next->val < p[0]->val && p[0]->next->val < p[1]->val)
		ft_swap_stack(l_a, "sa");
	else if (p[1]->val < p[0]->val && p[1]->val < p[0]->next->val)
		ft_reverse_rotato_stack(l_a, "rra");
}
