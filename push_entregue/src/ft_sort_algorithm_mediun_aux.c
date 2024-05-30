/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_medium_aux.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static int	ft_can_swap_a(t_list *l_a);
static int	ft_can_swap_b(t_list *l_b);

void	ft_can_swap(t_list *l_a, t_list *l_b)
{
	int	sa;
	int	sb;

	sa = ft_can_swap_a(l_a);
	sb = ft_can_swap_b(l_b);
	if (sa && sb)
		ft_swap_stack_both(l_a, l_b, "ss");
	if (!sa && sb)
		ft_swap_stack(l_b, "sb");
}

static int	ft_can_swap_a(t_list *l_a)
{
	t_node	*p1;
	t_node	*p2;

	if (l_a->size < 2)
		return (FALSE);
	p1 = l_a->begin;
	p2 = l_a->begin->next;
	if (p1->group != p2->group)
		return (FALSE);
	if (p1->val > p2->val)
		return (TRUE);
	return (FALSE);
}

static int	ft_can_swap_b(t_list *l_b)
{
	t_node	*p1;
	t_node	*p2;

	if (l_b->size < 2)
		return (FALSE);
	p1 = l_b->begin;
	p2 = l_b->begin->next;
	if (p1->group != p2->group)
		return (FALSE);
	if (p1->val < p2->val)
		return (TRUE);
	return (FALSE);
}
