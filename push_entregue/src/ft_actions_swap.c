/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_swap(t_list *l);

void	ft_swap_stack(t_list *l, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(l);
}

void	ft_swap_stack_both(t_list *l_a, t_list *l_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(l_a);
	ft_swap(l_b);
}

static void	ft_swap(t_list *l)
{
	t_node	*p;
	t_node	*q;

	p = l->begin;
	q = p->next;
	if (ft_list_size(l) == 2)
		l->end = p;
	else
		q->next->prev = p;
	p->next = q->next;
	q->next = p;
	q->prev = p->prev;
	p->prev = q;
	l->begin = q;
}
