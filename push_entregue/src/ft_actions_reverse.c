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

static void	ft_reverse_rotato(t_list *l);

void	ft_reverse_rotato_stack(t_list *l, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(l);
}

void	ft_reverse_rotato_stack_both(t_list *l_a, t_list *l_b, char *str)
{
	ft_putendl_fd(str, 1);
	ft_reverse_rotato(l_a);
	ft_reverse_rotato(l_b);
}

static void	ft_reverse_rotato(t_list *l)
{
	int	val;
	int	index;

	val = ft_list_get_last_val(l);
	index = l->end->index;
	ft_list_remove_last(l);
	ft_list_add_first(l, val);
	l->begin->index = index;
}
