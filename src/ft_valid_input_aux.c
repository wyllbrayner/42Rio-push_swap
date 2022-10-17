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
    int i;

    i = 0;
    while (ft_isspace(argv[i]))
        i++;
	if (((argv[i] == '-') || (argv[i] == '+')) && (!argv[i + 1]))
		return (-2);
	if ((argv[i] == '-') || (argv[i] == '+'))
    	i++;
    while (argv[i])
    {
		if (!ft_isdigit(argv[i]))
			return (-2);
        i++;
    }
	return (0);
}

int	ft_valid_duplic(List *L, int val)
{
	Node *p;

	if (!ft_list_is_empty(L))
	{
		p = L->begin;
		while (p != NULL)
		{
			if (p->val == val)
				return (1);
			p = p->next;
		}
	}
	return (0);
}