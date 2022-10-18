/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

Node *ft_node_create(int val)
{
    Node *node;

    node = (Node *)malloc(sizeof(Node));
    if (!node)
        return (NULL);
    node->val = val;
    node->index = 0;
	node->group = 0;
	node->prev = NULL;
	node->next = NULL;
    return (node);
}

List *ft_list_create(void)
{
    List *L;

    L = (List *)malloc(sizeof(List));
    if (!L)
        return (NULL);
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    L->ret = 0;
    return (L);
}

void ft_list_destroy(List **L_ref)
{
    List    *L;
    Node    *p;
    Node    *tmp;

    L = *L_ref;
    p = L->begin;
    tmp = NULL;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    free(L);
    *L_ref = NULL;
}

void ft_list_print(const List *L)
{
    Node *p;

    p = L->begin;
    ft_putstr_fd("L -> begin -> ", 1);
    while (p != NULL)
    {
        ft_putnbr_fd(p->val, 1);
        ft_putstr_fd(" -> ", 1);
        p = p->next;
    }
    ft_putstr_fd("NULL\n", 1);
    if (L->end == NULL)
        ft_putstr_fd("L -> end == NULL\n", 1);
    else
    {
        ft_putstr_fd("L-> end == ", 1);
        ft_putnbr_fd(L->end->val, 1);
        ft_putstr_fd("\n", 1);
    }
    ft_putstr_fd("Size: ", 1);
    ft_putnbr_fd(L->size, 1);
    ft_putstr_fd("\n", 1);
}

void ft_list_inverted_print(const List *L)
{
    Node *p;
    ft_putstr_fd("Inverted\n", 1);

    p = L->end;
    ft_putstr_fd("L -> end -> ", 1);
    while (p != NULL)
    {
        ft_putnbr_fd(p->val, 1);
        ft_putstr_fd(" -> ", 1);
        p = p->prev;
    }
    ft_putstr_fd("NULL\n", 1);
    if (L->end == NULL)
        ft_putstr_fd("L-> begin == NULL\n", 1);
    else
    {
        ft_putstr_fd("L-> begin == ", 1);
        ft_putnbr_fd(L->begin->val, 1);
        ft_putstr_fd("\n", 1);
    }
    ft_putstr_fd("Size: ", 1);
    ft_putnbr_fd(L->size, 1);
    ft_putstr_fd("\n", 1);
}
