/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_swap(List *L);
static void	ft_rotato(List *L);
static void	ft_reverse_rotato(List *L);
static void	ft_push(List *L_source, List *L_dest);

void	ft_swap_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(L_a);
	ft_swap(L_b);
}

void	ft_swap_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_swap(L);
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

void	ft_rotato_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_rotato(L_a);
	ft_rotato(L_b);
}

void	ft_rotato_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_rotato(L);
}

static void	ft_rotato(List *L)
{
	int	val;
	int index;

	val = ft_list_get_first_val(L);
	index = L->begin->index;
	ft_list_remove_first(L);
	ft_list_add_last(L, val);
	L->end->index = index;
}

void	ft_reverse_rotato_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(L_a);
	ft_reverse_rotato(L_b);
}

void	ft_reverse_rotato_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(L);
}

static void	ft_reverse_rotato(List *L)
{
	int	val;
	int	index;

	val = ft_list_get_last_val(L);
	index = L->end->index;
	ft_list_remove_last(L);
	ft_list_add_first(L, val);
	L->begin->index = index;
}

void	ft_push_stack(List *L_source, List *L_dest, char *str)
{
	ft_putendl_fd(str, 1);
	ft_push(L_source, L_dest);
}

static void	ft_push(List *L_source, List *L_dest)
{
	int	val;
	int index;

	val = ft_list_get_first_val(L_source);
	index = L_source->begin->index;
	ft_list_remove_first(L_source);
	ft_list_add_first(L_dest, val);
	L_dest->begin->index = index;
}