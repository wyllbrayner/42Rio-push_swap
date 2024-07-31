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

size_t	ft_dlist_size(const t_dlist *l)
{
	return (l->size);
}

bool	ft_dlist_is_empty(const t_dlist *l)
{
	return (ft_dlist_size(l) == 0);
}

int	ft_dlist_get_first_val(const t_dlist *l)
{
	if (ft_dlist_is_empty(l))
		exit(0);
	return (l->begin->val);
}

int	ft_dlist_get_last_val(const t_dlist *l)
{
	if (ft_dlist_is_empty(l))
		exit(0);
	return (l->end->val);
}
