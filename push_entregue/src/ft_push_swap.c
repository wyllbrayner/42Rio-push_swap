/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_select_function(t_list *l_a, t_list *l_b, int *sort);

int	ft_push_swap(int argc, char **argv)
{
	t_list	*l_a;
	t_list	*l_b;
	int		*sort;

	l_a = ft_list_create();
	l_b = ft_list_create();
	if (!l_a || !l_b)
	{
		ft_free_list(&l_a, &l_b);
		return (-1);
	}
	argv = ft_split_input(l_a, argc, argv);
	l_a = ft_valid_input(argc, argv, l_a);
	sort = NULL;
	if (l_a->ret == 0)
	{
		ft_list_to_array(l_a, &sort);
		ft_order_arr(sort, ft_list_size(l_a));
		l_a = ft_put_index(l_a, sort);
		ft_select_function(l_a, l_b, sort);
	}
	ft_free_structs(&l_a, &l_b, &sort, argv);
	return (0);
}

static void	ft_select_function(t_list *l_a, t_list *l_b, int *sort)
{
	if (ft_list_size(l_a) == 2)
		ft_sort_two(l_a);
	else if (ft_list_size(l_a) == 3)
		ft_sort_three_a(l_a);
	else if (ft_list_size(l_a) <= 5)
		ft_sort_five(l_a, l_b);
	else if (ft_list_size(l_a) <= 100)
		ft_sort_one_hundred(l_a, l_b, sort, 1);
	else
		ft_sort_five_hundred(l_a, l_b);
}
