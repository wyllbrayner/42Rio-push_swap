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

size_t	ft_list_size(const t_list *l)
{
	return (l->size);
}

bool	ft_list_is_empty(const t_list *l)
{
	return (ft_list_size(l) == 0);
}

int	ft_list_get_first_val(const t_list *l)
{
	if (ft_list_is_empty(l))
		exit(0);
	return (l->begin->val);
}

int	ft_list_get_last_val(const t_list *l)
{
	if (ft_list_is_empty(l))
		exit(0);
	return (l->end->val);
}
