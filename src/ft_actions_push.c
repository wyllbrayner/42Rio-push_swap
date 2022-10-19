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

static void	ft_push(t_list *l_source, t_list *L_dest);

void	ft_push_stack(t_list *l_source, t_list *l_dest, char *str)
{
	ft_putendl_fd(str, 1);
	ft_push(l_source, l_dest);
}

static void	ft_push(t_list *l_source, t_list *l_dest)
{
	int	val;
	int	index;

	val = ft_list_get_first_val(l_source);
	index = l_source->begin->index;
	ft_list_remove_first(l_source);
	ft_list_add_first(l_dest, val);
	l_dest->begin->index = index;
}
