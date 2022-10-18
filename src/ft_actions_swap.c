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

static void	ft_swap(List *L);

void	ft_swap_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(L);
}

void	ft_swap_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(L_a);
	ft_swap(L_b);
}

static void	ft_swap(List *L)
{
	Node *p;
	Node *q;

	p = L->begin;
	q = p->next;
	if (ft_list_size(L) == 2)
		L->end = p;
	else
		q->next->prev = p;
	p->next = q->next;
	q->next = p;
	q->prev = p->prev;
	p->prev = q;
	L->begin = q;
}