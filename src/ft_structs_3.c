/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void ft_list_add_first(List *L, int val)
{
    Node *p;

    p = ft_node_create(val);
    if (!p)
        exit(-1);
    if (ft_list_is_empty(L))
    {
        L->end = p;
        L->begin = p;
    }
    else
    {
        p->next = L->begin; 
        L->begin->prev = p;
        L->begin = p;
    }
    L->size++;
}

void ft_list_add_last(List *L, int val)
{
    Node *p;

    p = ft_node_create(val);
    if (!p)
        exit(-1);
    if (ft_list_is_empty(L))
    {
        L->begin = p;
        L->end = p;
    }
    else
    {
        L->end->next = p;
        p->prev = L->end;
        L->end = p; 
    }
    L->size++;
}

void ft_list_remove_first(List *L)
{
    Node *p;

    if (!ft_list_is_empty(L))
    {
        p = L->begin;
        if (ft_list_size(L) == 1)
        {
            L->begin = NULL;
            L->end = NULL;
        }
        else
        {
            L->begin = L->begin->next;
            L->begin->prev = NULL;
        }
        free(p);
        L->size--;
    }
}

void ft_list_remove_last(List *L)
{
    Node *p;

    if (!ft_list_is_empty(L))
    {
        p = L->end;
        if (ft_list_size(L) == 1)
        {
            L->begin = NULL;
            L->end = NULL;
        }
        else
        {
            L->end = L->end->prev;
            L->end->next = NULL;
        }
        free(p);
        L->size--;
    }
}
