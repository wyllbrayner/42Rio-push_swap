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

static void	ft_valid_input_amount(int argc, List *L);
static List	*ft_valid_input_character(char **argv, List *L);
static List	*ft_valid_input_duplic(List *L);

List *ft_valid_input(int argc, char **argv, List *L)
{
    ft_valid_input_amount(argc, L);
    if (L->ret < 0)
        return (L);
	L = ft_valid_input_character(argv, L);
    if (L->ret < 0)
	{
		ft_error();
        return (L);
	}
	L = ft_valid_input_duplic(L);
	if (L->ret < 0)
	{
		ft_error();
		return (L);
	}
    L = ft_valid_input_order(L);
	if (L->ret < 0)
		return (L);
    return (L);
}

static void	ft_valid_input_amount(int argc, List *L)
{
    if (argc == 1)
        L->ret = -1;
}

static List	*ft_valid_input_character(char **argv, List *L)
{
    int     i;
    long    input_lg;

    i = 1;
    while (argv[i])
    {
        if (ft_valid_character(argv[i]) < 0)
        {
            L->ret = -2;
            return (L);
        }
        else
        {
            input_lg = ft_atol(argv[i]);
            if ((input_lg > INT_MAX) || (input_lg < INT_MIN))
            {
                L->ret = -3;
                return (L);
            }
            else
                ft_list_add_last(L, input_lg);
        }
        i++;
    }
    return (L);
}

static List	*ft_valid_input_duplic(List *L)
{
	List	*L_aux;
	Node	*p;

	L_aux = ft_list_create();
	if (!L_aux)
	{
		L->ret = -4;
		return (L);
	}
	p = L->begin;
	while (p != NULL)
	{
		if (ft_valid_duplic(L_aux, p->val) == 0)
			ft_list_add_last(L_aux, p->val);
		else
		{
			L->ret = -4;
			ft_list_destroy(&L_aux);
			return (L);
		}
		p = p->next;
	}
	ft_list_destroy(&L_aux);
	return (L);
}

List	*ft_valid_input_order(List *L)
{
	Node	*p;
	Node	*q;

	L->ret = -5;
	if ((ft_list_is_empty(L)) || (ft_list_size(L) == 1))
		return (L);
	p = L->begin;
	q = p->next;
	while (p != NULL && q != NULL)
	{
		if (p->val > q->val)
		{
			L->ret = 0;
			return (L);
		}
		p = p->next;
		q = q->next;
	}
	return (L);
}
