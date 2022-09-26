/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

size_t ft_list_size(const List *L)
{
    return (L->size);
}

bool ft_list_is_empty(const List *L)
{
    return (ft_list_size(L) == 0);
}

int ft_list_get_first_val(const List *L)
{
    if (ft_list_is_empty(L))
        exit(-0);
    return (L->begin->val);
}

int ft_list_get_last_val(const List *L)
{
    if (ft_list_is_empty(L))
        exit(-0);
    return (L->end->val);
}
