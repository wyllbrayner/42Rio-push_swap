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

void	ft_swap_stack(List *L)
{
	ft_putendl_fd("Dentro da função de swap da stack", 1);
	Node *p;
	Node *q;

	ft_putendl_fd("Antes da troca", 1);
	List_print(L);
	List_inverted_print(L);
	p = L->begin;
	q = p->next;
	if (List_size(L) == 2)
		L->end = p;
	else
		q->next->prev = p;
	p->next = q->next;
	q->next = p;
	q->prev = p->prev;
	p->prev = q;
	L->begin = q;
	ft_putendl_fd("Após a troca", 1);
	List_print(L);
	List_inverted_print(L);
}

void	ft_rotato_stack(List *L)
{
	ft_putendl_fd("Dentro da função de rotato da stack", 1);
	int	val;

	ft_putendl_fd("Antes de rodar", 1);
	List_print(L);
	List_inverted_print(L);
	val = List_get_first_val(L);
	List_remove_first(L);
	List_add_last(L, val);
	ft_putendl_fd("Após rodar", 1);
	List_print(L);
	List_inverted_print(L);
}

void	ft_reverse_rotato_stack(List *L)
{
	ft_putendl_fd("dentro da função de reverse rotato da stack", 1);
	int	val;

	ft_putendl_fd("Antes de reverse totato", 1);
	List_print(L);
	List_inverted_print(L);
	val = List_get_last_val(L);
	List_remove_last(L);
	List_add_first(L, val);
	ft_putendl_fd("Após reverse rotato", 1);
	List_print(L);
	List_inverted_print(L);
}

void	ft_push_stack(List *L_source, List *L_dest)
{
	ft_putendl_fd("dentro da função de push da stack", 1);
	int	val;

	ft_putendl_fd("Antes de realizar o push, a stack origem estava assim:", 1);
	List_print(L_source);
	List_inverted_print(L_source);
	ft_putendl_fd("Antes de realizar o push, a stack destino estava assim:", 1);
	List_print(L_dest);
	List_inverted_print(L_dest);
	val = List_get_first_val(L_source);
	List_remove_first(L_source);
	List_add_first(L_dest, val);
	ft_putendl_fd("Após realizar o push, a stack origem está assim:", 1);
	List_print(L_source);
	List_inverted_print(L_source);
	ft_putendl_fd("Após realizar o push, a stack destino está assim:", 1);
	List_print(L_dest);
	List_inverted_print(L_dest);}