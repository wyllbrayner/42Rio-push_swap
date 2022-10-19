/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

t_node	*ft_node_create(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->index = 0;
	node->group = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_list	*ft_list_create(void)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	l->ret = 0;
	return (l);
}

void	ft_list_destroy(t_list **l_ref)
{
	t_list	*l;
	t_node	*p;
	t_node	*tmp;

	l = *l_ref;
	p = l->begin;
	tmp = NULL;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	free(l);
	*l_ref = NULL;
}

void	ft_list_print(const t_list *l)
{
	t_node	*p;

	p = l->begin;
	ft_putstr_fd("L -> begin -> ", 1);
	while (p != NULL)
	{
		ft_putnbr_fd(p->val, 1);
		ft_putstr_fd(" -> ", 1);
		p = p->next;
	}
	ft_putstr_fd("NULL\n", 1);
	if (l->end == NULL)
		ft_putstr_fd("L -> end == NULL\n", 1);
	else
	{
		ft_putstr_fd("L-> end == ", 1);
		ft_putnbr_fd(l->end->val, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("Size: ", 1);
	ft_putnbr_fd(l->size, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_list_inverted_print(const t_list *L)
{
	t_node	*p;

	ft_putstr_fd("Inverted\n", 1);
	p = L->end;
	ft_putstr_fd("L -> end -> ", 1);
	while (p != NULL)
	{
		ft_putnbr_fd(p->val, 1);
		ft_putstr_fd(" -> ", 1);
		p = p->prev;
	}
	ft_putstr_fd("NULL\n", 1);
	if (L->end == NULL)
		ft_putstr_fd("L-> begin == NULL\n", 1);
	else
	{
		ft_putstr_fd("L-> begin == ", 1);
		ft_putnbr_fd(L->begin->val, 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("Size: ", 1);
	ft_putnbr_fd(L->size, 1);
	ft_putstr_fd("\n", 1);
}
