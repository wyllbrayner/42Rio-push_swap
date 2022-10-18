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

static  void ft_select_function(List *L_a, List *L_b, int *sort);

int ft_push_swap(int argc, char **argv)
{
    List        *L_a;
    List        *L_b;
    int         *sort;

    L_a = ft_list_create();
    L_b = ft_list_create();
    if (!L_b || !L_a)
    {
        ft_free_list(&L_a, &L_b);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    ft_list_to_array(L_a, &sort);
    ft_order_arr(sort, ft_list_size(L_a));
    L_a = ft_put_index(L_a, sort);
    if (L_a->ret == 0)
        ft_select_function(L_a, L_b, sort);
    ft_free_structs(&L_a, &L_b, &sort);
    return (0);
}

static void ft_select_function(List *L_a, List *L_b, int *sort)
{
    if (ft_list_size(L_a) == 2)
        ft_sort_two(L_a);
    else if (ft_list_size(L_a) == 3)
        ft_sort_three_a(L_a);
    else if (ft_list_size(L_a) <= 5)
        ft_sort_five(L_a, L_b);
    else if (ft_list_size(L_a) <= 100)
        ft_sort_one_hundred(L_a, L_b, sort, 1);
    else
        ft_sort_five_hundred(L_a, L_b);
}