/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_reverse_rotato(List *L);

void	ft_reverse_rotato_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(L);
}

void	ft_reverse_rotato_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(L_a);
	ft_reverse_rotato(L_b);
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