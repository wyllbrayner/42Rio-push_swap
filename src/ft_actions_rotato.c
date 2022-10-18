/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_rotato.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_rotato(List *L);

void	ft_rotato_stack(List *L, char *str)
{
	ft_putendl_fd(str, 1);
	ft_rotato(L);
}

void	ft_rotato_stack_both(List *L_a, List *L_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_rotato(L_a);
	ft_rotato(L_b);
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