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

static void		ft_valid_input_amount(int argc, t_list *l);
static t_list	*ft_valid_input_character(char **argv, t_list *l);
static t_list	*ft_valid_input_duplic(t_list *l);

t_list	*ft_valid_input(int argc, char **argv, t_list *l)
{
	if (l->ret < 0)
	{
		ft_putendl_fd("Error", 1);
		return (l);
	}
	ft_valid_input_amount(argc, l);
	if (l->ret < 0)
		return (l);
	l = ft_valid_input_character(argv, l);
	if (l->ret < 0)
	{
		ft_putendl_fd("Error", 1);
		return (l);
	}
	l = ft_valid_input_duplic(l);
	if (l->ret < 0)
	{
		ft_putendl_fd("Error", 1);
		return (l);
	}
	l = ft_valid_input_order_asc(l);
	if (l->ret < 0)
		return (l);
	return (l);
}

static void	ft_valid_input_amount(int argc, t_list *l)
{
	if (argc == 1)
		l->ret = -1;
}

static t_list	*ft_valid_input_character(char **argv, t_list *l)
{
	int		i;
	long	input_lg;

	i = 0;
	while (argv[i])
	{
		if (ft_valid_character(argv[i]) < 0)
		{
			l->ret = -2;
			return (l);
		}
		else
		{
			input_lg = ft_atol(argv[i]);
			if ((input_lg > INT_MAX) || (input_lg < INT_MIN))
			{
				l->ret = -3;
				return (l);
			}
			else
				ft_list_add_last(l, input_lg);
		}
		i++;
	}
	return (l);
}

static t_list	*ft_valid_input_duplic(t_list *l)
{
	t_list	*l_aux;
	t_node	*p;

	l_aux = ft_list_create();
	if (!l_aux)
	{
		l->ret = -4;
		return (l);
	}
	p = l->begin;
	while (p != NULL)
	{
		if (ft_valid_duplic(l_aux, p->val) == 0)
			ft_list_add_last(l_aux, p->val);
		else
		{
			l->ret = -4;
			ft_list_destroy(&l_aux);
			return (l);
		}
		p = p->next;
	}
	ft_list_destroy(&l_aux);
	return (l);
}
