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

void    ft_sort_three_a(List *L_a);
void    ft_sort_three_a_aux(List *L_a);

void    ft_sort_two(List *L_a)
{
    ft_swap_stack(L_a, "sa");
}

void    ft_sort_three_a(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
    while (L_a->ret == 0)
    {
        if ((p1->val > p2->val) && (p1->val > p3->val))
            ft_rotato_stack(L_a, "ra");
        else if (((p1->val > p2->val) && (p1->val < p3->val)) || ((p1->val < p2->val) && (p1->val > p3->val)))
            ft_sort_three_a_aux(L_a);
        else
            ft_reverse_rotato_stack(L_a, "rra");
        p1 = L_a->begin;
        p2 = p1->next;
        p3 = L_a->end;
        L_a = ft_valid_input_order_asc(L_a);
    }
}

void    ft_sort_three_a_aux(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
    if ((p2->val < p1->val) && (p2->val < p3->val))
        ft_swap_stack(L_a, "sa");
    else
        ft_reverse_rotato_stack(L_a, "rra");
}

void    ft_sort_five(List *L_a, List *L_b)
{
	Node	*p1;
	Node	*p2;
	Node	*p3;

	p1 = L_a->begin;
	p2 = p1->next;
	p3 = L_a->end;
	while ((ft_list_size(L_b) != 0) || (L_a->ret == 0))
	{
		if (p2->val < p1->val && p2->val < p3->val)
			ft_swap_stack(L_a, "sa");
		else if ((p3->val < p1->val) && (p3->val < p2->val))
			ft_reverse_rotato_stack(L_a, "rra");
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
                if ((L_a->ret != 0) && ((L_b->ret != 0) && (ft_list_size(L_b) != 0)))
                    ft_push_stack(L_b, L_a, "pa");
                p1 = L_a->begin;
                p2 = p1->next;
                p3 = L_a->end;
                L_a = ft_valid_input_order_asc(L_a);
	}
}

void    ft_last_move(List *L_a, List *L_b, int digit_move) 
{
//        printf("dentro da last move | digit_move: %d\n", digit_move);
        int     cnt[2];
        int     result;
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_a->size;
        p = L_a->begin;
        while (cnt[0]++ < cnt[1])
        {
//              printf("dentro da last move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                result = ((p->index >> digit_move) % 2 == 0);
//                printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                if (result)
                {
                        ft_push_stack(L_a, L_b, "pb");
                }
                else
                {
                        ft_rotato_stack(L_a, "ra");                
                }
                p = L_a->begin;
        }
        while (L_b->size > 0)
        {
//                printf("dentro da last aux | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                ft_push_stack(L_b, L_a, "pa");
        }
//        printf("dentro da last move | fora do loop | encerra a last move\n");
}

void    ft_move(List *L_a, List *L_b, int digit_move)
{
//        printf("dentro da move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
        int cnt[2];
        int result;
        Node    *p;

        cnt[0] = 0;
        if (L_a->size > 0)
        {
                cnt[1] = L_a->size;
                p = L_a->begin;
                while (cnt[0]++ < cnt[1])
                {
//                        printf("dentro da move | dentro do 1º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                        result = ((p->index >> digit_move) % 2 == 0);
//                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                        if (result)
                        {
                                ft_push_stack(L_a, L_b, "pb");
                        }
                        else
                        {
                                ft_rotato_stack(L_a, "ra");
                        }
                        p = L_a->begin;
                }
                while (L_a->size > 0)
                {
//                        printf("dentro da move | dentro do 2º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_b->size);
                        ft_push_stack(L_a, L_b, "pb");
                }
        }
        else
        {
                cnt[1] = L_b->size;
                p = L_b->begin;
                while (cnt[0]++ < cnt[1])
                {
//                        printf("dentro da move_aux | digit_move: %d | L_b->size: %zu\n", digit_move, L_b->size);
                        result = ((p->index >> digit_move) % 2);
//                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                        if (result)
                        {
                                ft_push_stack(L_b, L_a, "pa");
                        }
                        else
                        {
                                ft_rotato_stack(L_b, "rb");
                        }
                        p = L_b->begin;
                }
                while (L_b->size > 0)
                        ft_push_stack(L_b, L_a, "pa");
        }
//        printf("dentro da move | encerra a move\n");
}

void    ft_sort_others(List *L_a, List *L_b)
{
        int move;
        int now_move;

        move = 0;
        while ((1 << move) < L_a->size)
                ++move;
        now_move = 0;
        while (now_move++ < move)
        {
                if ((now_move == move) && (now_move % 2))
                {
                        ft_last_move(L_a, L_b, (now_move - 1));
                }
                else
                {
                        ft_move(L_a, L_b, (now_move - 1));
                }
        }
        L_a->ret = -5;
}