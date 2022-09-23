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

Node *Node_create(int val)
{
    Node *node;

    node = (Node *)malloc(sizeof(Node));
    if (!node)
        return (NULL);
    node->prev = NULL;
    node->next = NULL;
    node->val = val;

    return (node);
}

List *List_create()
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

void List_destroy(List **L_ref)
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

bool List_is_empty(const List *L)
{
    return (List_size(L) == 0);
}

size_t List_size(const List *L)
{
    return (L->size);
}

int List_get_first_val(const List *L)
{
    if (List_is_empty(L))
        exit(-0);
    return (L->begin->val);
}

int List_get_last_val(const List *L)
{
    if (List_is_empty(L))
        exit(-0);
    return (L->end->val);
}

void List_add_first(List *L, int val)
{
    Node *p;

    p = Node_create(val);
    if (!p)
        exit(-1);
    if (List_is_empty(L))
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

void List_add_last(List *L, int val)
{
    Node *p;

    p = Node_create(val);
    if (!p)
        exit(-1);
    if (List_is_empty(L))
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

void List_remove_first(List *L)
{
    Node *p;

    if (!List_is_empty(L))
    {
        p = L->begin;
        if (List_size(L) == 1)
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

void List_remove_last(List *L)
{
    Node *p;

    if (!List_is_empty(L))
    {
        p = L->end;
        if (List_size(L) == 1)
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

void List_print(const List *L)
{
    Node *p;

    p = L->begin;
    printf("L -> ");
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
    if (L->end == NULL)
        printf("L-> end == NULL\n");
    else
        printf("L->end == %d\n", L->end->val);
    printf("Size: %lu\n", L->size);
}

void List_inverted_print(const List *L)
{
    printf("Inverted\n");
    Node *p;

    p = L->end;
    printf("L -> end -> ");
    while (p != NULL)
    {
        printf("%d -> ", p->val);
        p = p->prev;
    }
    printf("NULL\n");
    if (L->end == NULL)
        printf("L-> begin == NULL\n");
    else
        printf("L->begin == %d\n", L->begin->val);
    printf("Size: %lu\n", L->size);
}
