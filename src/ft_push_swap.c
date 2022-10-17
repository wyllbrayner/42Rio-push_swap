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

static  void ft_select_function(List *L_a, List *L_b);
void    ft_sort_two(List *L_a);
void    ft_sort_three_a(List *L_a);
void    ft_sort_three_a_aux(List *L_a);
void    ft_sort_three_b(List *L_b);
void    ft_sort_five(List *L_a, List *L_b);
void    ft_sort_more_than_five(List *L_a, List *L_b);
void    ft_sort_others(List *L_a, List *L_b);
int     *ft_order_arr(int *sort, size_t len);
void    ft_sort_more_than_three(List *L_a, List *L_b, int *sort, int first);

int ft_push_swap(int argc, char **argv)
{
    List        *L_a;
    List        *L_b;
    int         *sort;

    L_a = ft_list_create();
    L_b = ft_list_create();
    if (!L_b || !L_a)
    {
        ft_list_destroy(&L_a);
        ft_list_destroy(&L_b);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    sort = NULL;
    ft_list_to_array(L_a, &sort);
    ft_order_arr(sort, ft_list_size(L_a));
    L_a = ft_put_index(L_a, sort);
/*
    ft_list_print(L_a);
    ft_list_print(L_b);
*/
    if (L_a->ret == 0)
    {
        ft_select_function(L_a, L_b);
    }
/*
    printf("Resultado da ordenação\nValor de ret de l_a: %d\n", L_a->ret);
    ft_list_print(L_a);
    ft_list_print(L_b);
*/
    ft_list_destroy(&L_a);
    ft_list_destroy(&L_b);
    ft_free_sort(&sort);
/*
    printf("L_a == NULL: %d\nL_b == NULL: %d\nsort == NULL: %d\n", L_a == NULL, L_b == NULL, sort == NULL);
*/
    return (0);
}

static void ft_select_function(List *L_a, List *L_b)
{
    if (ft_list_size(L_a) == 2)
        ft_sort_two(L_a);
    else if (ft_list_size(L_a) == 3)
        ft_sort_three_a(L_a);
    else if (ft_list_size(L_a) <= 5)
        ft_sort_five(L_a, L_b);
    else
    {
//        ft_sort_more_than_five(L_a, L_b);
        ft_sort_others(L_a, L_b);
    }
}