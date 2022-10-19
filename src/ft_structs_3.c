/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void	ft_list_add_first(t_list *l, int val)
{
	t_node	*p;

	p = ft_node_create(val);
	if (!p)
		exit(-1);
	if (ft_list_is_empty(l))
	{
		l->end = p;
		l->begin = p;
	}
	else
	{
		p->next = l->begin;
		l->begin->prev = p;
		l->begin = p;
	}
	l->size++;
}

void	ft_list_add_last(t_list *l, int val)
{
	t_node	*p;

	p = ft_node_create(val);
	if (!p)
		exit(-1);
	if (ft_list_is_empty(l))
	{
		l->begin = p;
		l->end = p;
	}
	else
	{
		l->end->next = p;
		p->prev = l->end;
		l->end = p;
	}
	l->size++;
}

void	ft_list_remove_first(t_list *l)
{
	t_node	*p;

	if (!ft_list_is_empty(l))
	{
		p = l->begin;
		if (ft_list_size(l) == 1)
		{
			l->begin = NULL;
			l->end = NULL;
		}
		else
		{
			l->begin = l->begin->next;
			l->begin->prev = NULL;
		}
		free(p);
		l->size--;
	}
}

void	ft_list_remove_last(t_list *l)
{
	t_node	*p;

	if (!ft_list_is_empty(l))
	{
		p = l->end;
		if (ft_list_size(l) == 1)
		{
			l->begin = NULL;
			l->end = NULL;
		}
		else
		{
			l->end = l->end->prev;
			l->end->next = NULL;
		}
		free(p);
		l->size--;
	}
}
