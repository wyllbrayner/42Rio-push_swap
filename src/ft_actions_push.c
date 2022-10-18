/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_push(List *L_source, List *L_dest);

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