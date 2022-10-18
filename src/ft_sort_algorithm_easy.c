/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_easy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void    ft_sort_five_aux(List *L_a);

void    ft_sort_two(List *L_a)
{
    ft_swap_stack(L_a, "sa");
}

void    ft_sort_three_a(List *L_a)
{
    Node    *p[3];

    p[0] = L_a->begin;
    p[1] = p[0]->next;
    p[2] = L_a->end;
    while (L_a->ret == 0)
    {
        if ((p[0]->val > p[1]->val) && (p[0]->val > p[2]->val))
            ft_rotato_stack(L_a, "ra");
        else if (((p[0]->val > p[1]->val) && (p[0]->val < p[2]->val)) ||
         ((p[0]->val < p[1]->val) && (p[0]->val > p[2]->val)))
        {
            if ((p[1]->val < p[0]->val) && (p[1]->val < p[2]->val))
                ft_swap_stack(L_a, "sa");
            else
                ft_reverse_rotato_stack(L_a, "rra");
        }
        else
            ft_reverse_rotato_stack(L_a, "rra");
        p[0] = L_a->begin;
        p[1] = p[0]->next;
        p[2] = L_a->end;
        L_a = ft_valid_input_order_asc(L_a);
    }
}

void    ft_sort_five(List *L_a, List *L_b)
{
	Node	*p[2];

	p[0] = L_a->begin;
	p[1] = L_a->end;
	while ((ft_list_size(L_b) != 0) || (L_a->ret == 0))
	{
        ft_sort_five_aux(L_a);
		L_a = ft_valid_input_order_asc(L_a);
        if (L_a->ret == 0)
            ft_push_stack(L_a, L_b, "pb");
        L_a = ft_valid_input_order_asc(L_a);
        if ((ft_list_size(L_a) == 3) && (L_a->ret == 0))
            ft_sort_three_a(L_a);
        L_b = ft_valid_input_order_desc(L_b);
        if ((ft_list_size(L_b) == 2) && (L_b->ret == 0))
            ft_swap_stack(L_b, "sb");
        L_a = ft_valid_input_order_asc(L_a);
        L_b = ft_valid_input_order_desc(L_b);
        if (L_a->ret != 0 && (L_b->ret != 0 && ft_list_size(L_b) != 0))
            ft_push_stack(L_b, L_a, "pa");
        p[0] = L_a->begin;
        p[1] = L_a->end;
        L_a = ft_valid_input_order_asc(L_a);
	}
}

static void    ft_sort_five_aux(List *L_a)
{
	Node	*p[2];

	p[0] = L_a->begin;
	p[1] = L_a->end;
	if (p[0]->next->val < p[0]->val && p[0]->next->val < p[1]->val)
		ft_swap_stack(L_a, "sa");
	else if (p[1]->val < p[0]->val && p[1]->val < p[0]->next->val)
		ft_reverse_rotato_stack(L_a, "rra");
}