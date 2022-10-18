/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_medium_aux.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static int  ft_can_swap_a(List *L_a);
static int  ft_can_swap_b(List *L_b);

void    ft_can_swap(List *L_a, List *L_b)
{
    int sa;
    int sb;

    sa = ft_can_swap_a(L_a);
    sb = ft_can_swap_b(L_b);
    if (sa && sb)
        ft_swap_stack_both(L_a, L_b, "ss");
    if (!sa && sb)
        ft_swap_stack(L_b, "sb");
}

static int  ft_can_swap_a(List *L_a)
{
    Node *p1;
    Node *p2;

    if (L_a->size < 2)
        return (FALSE);
    p1 = L_a->begin;
    p2 = L_a->begin->next;
    if (p1->group != p2->group)
        return (FALSE);
    if (p1->val > p2->val)
        return (TRUE);
    return (FALSE);
}

static int  ft_can_swap_b(List *L_b)
{
    Node *p1;
    Node *p2;

    if (L_b->size < 2)
        return (FALSE);
    p1 = L_b->begin;
    p2 = L_b->begin->next;
    if (p1->group != p2->group)
        return (FALSE);
    if (p1->val < p2->val)
        return (TRUE);
    return (FALSE);
}