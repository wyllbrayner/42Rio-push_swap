/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	ft_valid_character(char *argv)
{
    int     i;
    char    *input;

    i = 0;
    input = "0123456789+-";
    while (argv[i])
    {
        if (!ft_strchr(input, argv[i]) && (!ft_isspace(argv[i])))
            return (-2);
        i++;
    }
    return (0);  
}

int	ft_valid_duplic(List *L_aux, int val)
{
	Node *p;

	if (!List_is_empty(L_aux))
	{
		p = L_aux->begin;
		while (p != NULL)
		{
			if (p->val == val)
				return (1);
			p = p->next;
		}
	}
	return (0);
}