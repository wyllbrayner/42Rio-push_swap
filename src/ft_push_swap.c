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

void    ft_select_function(List *L_a, List *L_b);
void    ft_sort_two(List *L_a);
void    ft_sort_tree(List *L_a);
void    ft_sort_tree_aux(List *L_a);
void    ft_sort_five(List *L_a, List *L_b);

int ft_push_swap(int argc, char **argv)
{
    List    *L_a;
    List    *L_b;

    L_a = ft_list_create();
    L_b = ft_list_create();
    if (!L_b || !L_a)
    {
        ft_list_destroy(&L_a);
        ft_list_destroy(&L_b);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    if (L_a->ret == 0)
    {
        ft_putstr_fd("Valor de ret de l_a: ", 1);
        ft_putnbr_fd(L_a->ret, 1);
        ft_putstr_fd("\n", 1);
    	ft_list_print(L_a);
        ft_select_function(L_a, L_b);
    }
    ft_putstr_fd("Valor de ret de l_a: ", 1);
    ft_putnbr_fd(L_a->ret, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("stack l_a: \n", 1);
	ft_list_print(L_a);
    ft_putstr_fd("stack l_b: \n", 1);
	ft_list_print(L_b);
    ft_list_destroy(&L_a);
    ft_list_destroy(&L_b);
    ft_putstr_fd("L_a == NULL: ", 1);
    ft_putnbr_fd(L_a == NULL, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("L_b == NULL: ", 1);
    ft_putnbr_fd(L_b == NULL, 1);
    ft_putstr_fd("\n", 1);
	return (0);
}

void ft_select_function(List *L_a, List *L_b)
{
//    printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    while ((L_a->ret == 0) && ft_list_is_empty(L_b))
    {
//        printf("Dentro do loop\n");
        if (ft_list_size(L_a) == 2)
            ft_sort_two(L_a);
        else if (ft_list_size(L_a) == 3)
            ft_sort_tree(L_a);
        else if (ft_list_size(L_a) <= 5)
            ft_sort_five(L_a, L_b);
        else
        {
            printf("ordena Padrão\n");
            ft_swap_stack(L_a);
            ft_push_stack(L_a, L_b);
            ft_push_stack(L_a, L_b);
            ft_push_stack(L_a, L_b);
	        ft_rotato_stack(L_a);
	        ft_rotato_stack(L_b);
    	    ft_reverse_rotato_stack(L_a);
	        ft_reverse_rotato_stack(L_b);
	        ft_swap_stack(L_a);
            ft_push_stack(L_b, L_a);
            ft_push_stack(L_b, L_a);
            ft_push_stack(L_b, L_a);
        }
        L_a = ft_valid_input_order(L_a);
//        printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    }
}

void    ft_sort_two(List *L_a)
{
    ft_putstr_fd("sa\n", 1);
    ft_swap_stack(L_a);
}

void    ft_sort_tree(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
    if ((p1->val > p2->val) && (p1->val > p3->val))
    {
        ft_putstr_fd("ra\n", 1);
        ft_rotato_stack(L_a);
    }
    else if (((p1->val > p2->val) && (p1->val < p3->val)) || ((p1->val < p2->val) && (p1->val > p3->val)))
        ft_sort_tree_aux(L_a);
    else
    {
        ft_putstr_fd("rra\n", 1);
        ft_reverse_rotato_stack(L_a);
    }
}

void    ft_sort_tree_aux(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
    if ((p2->val < p1->val) && (p2->val < p3->val))
    {
        ft_putstr_fd("sa\n", 1);
        ft_swap_stack(L_a);
    }
    else
    {
        ft_putstr_fd("rra\n", 1);
        ft_reverse_rotato_stack(L_a);
    }
}

void    ft_sort_five(List *L_a, List *L_b)
{
    ft_putstr_fd("ft_sort_five\n", 1);

}