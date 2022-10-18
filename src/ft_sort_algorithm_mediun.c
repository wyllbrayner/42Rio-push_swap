/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_medium.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static int ft_can_swap_a(List *L_a)
{
    Node *top;
    Node *second;

    if (L_a->size < 2)
        return (0);
    top = L_a->begin;
    second = L_a->begin->next;
    if (top->group != second->group)
        return (0);
    if (top->val > second->val)
        return (1);
    return (0);
}

static int ft_can_swap_b(List *L_b)
{
    Node *top;
    Node *second;

    if (L_b->size < 2)
        return (0);
    top = L_b->begin;
    second = L_b->begin->next;
    if (top->group != second->group)
        return (0);
    if (top->val < second->val)
        return (1);
    return (0);
}

void    ft_can_swap(List *L_a, List *L_b)
{
    int sa;
    int sb;

    sa = ft_can_swap_a(L_a);
    sb = ft_can_swap_b(L_b);
    if (sa && sb)
        ft_swap_stack_both(L_a, L_b);
    if (!sa && sb)
        ft_swap_stack(L_b, "sb");
}

static void ft_split_stack(List *L_a, List *L_b, t_pivot pivot)
{
    int qtd;

    qtd = pivot.qtd;
    while (qtd > 0)
    {
        ft_can_swap(L_a, L_b);
        if (L_a->begin->val < pivot.value)
        {
            L_a->begin->group = pivot.index;
            ft_push_stack(L_a, L_b, "pb");
            qtd--;
        }
        else
            ft_rotato_stack(L_a, "ra");
    }
}

static t_pivot ft_get_pivot(int *sort, int size, int first)
{
    t_pivot pivot;

    if (size < 10)
        pivot.index = size / 2;
    else if (size < 50)
        pivot.index = size / 3;
    else if (size < 90)
        pivot.index = size / 5;
    else if (size < 110)
        pivot.index = size / 7;
    else if (size < 150)
        pivot.index = size / 9;
    else
        pivot.index = size / 11;
    if (pivot.index > size - 3)
        pivot.index = size - 3;
    pivot.value = sort[pivot.index];
    pivot.qtd = pivot.index;
    pivot.first = first;
    return (pivot);
}

static int  ft_find_sort_way(List *L_b, t_pivot pivot, int value)
{
    Node *node;
    int count;
    int max;

    node = L_b->begin;
    count = 0;
    max = pivot.qtd;
    if (pivot.first)
        max = pivot.qtd / 2;
    while (count < max)
    {
        if (node->val == value)
            return (0);
        count++;
        node = node->next;
    }
    return (1);
}

void    ft_return_stack(List *L_a, List *L_b, t_pivot pivot, int *sort)
{
    int reverse;

    if (L_b->begin == NULL)
        return ;
    reverse = 0;
    pivot.index--;
    pivot.group = L_b->begin->group;
    while (L_b->size > 0 && pivot.index >= 0)
    {
        reverse = ft_find_sort_way(L_b, pivot, sort[pivot.index]);
        if (L_b->begin->val == sort[pivot.index])
        {
            ft_push_stack(L_b, L_a, "pa");
            pivot.index--;
            pivot.qtd;
        }
        else
        {
            if (reverse)
                ft_reverse_rotato_stack(L_b, "rrb");
            else
                ft_rotato_stack(L_b, "rb");
        }
    }
}

void    ft_sort_all(List *L_a, List *L_b, int *sort, int first)
{
    t_pivot pivot;

    pivot.index = 0;
    if (L_a->size > 3)
    {
        pivot = ft_get_pivot(sort, (int)L_a->size, first);
        ft_split_stack(L_a, L_b, pivot);
        ft_sort_all(L_a, L_b, sort + pivot.index, 0);
    }
    ft_sort_three_a(L_a);
    ft_return_stack(L_a, L_b, pivot, sort);

}