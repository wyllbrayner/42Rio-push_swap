/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm_hard.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

void    ft_last_move(List *L_a, List *L_b, int digit_move)
{
//        printf("dentro da last move | digit_move: %d\n", digit_move);
        int     cnt[2];
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_a->size;
        p = L_a->begin;
        while (cnt[0]++ < cnt[1])
        {
//              printf("dentro da last move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
//                printf("Valor de index: %d | val: %d | digit_move: %d\n", p->index, p->val, digit_move);
                if ((p->index >> digit_move))
                        ft_rotato_stack(L_a, "ra");                
                else
                        ft_push_stack(L_a, L_b, "pb");
//                ft_list_print(L_a);
//                ft_list_print(L_b);
                p = L_a->begin;
        }
        while (L_b->size > 0)
        {
//                printf("dentro da last aux | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                ft_push_stack(L_b, L_a, "pa");
//                ft_list_print(L_a);
//                ft_list_print(L_b);
        }
//        printf("dentro da last move | fora do loop | encerra a last move\n");
}

void    ft_move(List *L_a, List *L_b, int digit_move)
{
//        printf("dentro da move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
        int cnt[2];
        Node    *p;

        cnt[0] = 0;
        if (L_a->size > 0)
        {
                cnt[1] = L_a->size;
                p = L_a->begin;
                while (cnt[0]++ < cnt[1])
                {
//                        printf("dentro da move | dentro do 1º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
//                        printf("Valor de index: %d | val: %d | digit_move: %d\n", p->index, p->val, digit_move);
                        if ((p->index >> digit_move) % 2 == 1)
                                ft_rotato_stack(L_a, "ra");
                        else
                                ft_push_stack(L_a, L_b, "pb");
//                        ft_list_print(L_a);
//                        ft_list_print(L_b);
                        p = L_a->begin;
                }
                while (L_a->size > 0)
                {
//                        printf("dentro da move | dentro do 2º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                        ft_push_stack(L_a, L_b, "pb");
//                        ft_list_print(L_a);
//                        ft_list_print(L_b);
                }
        }
        else
        {
                cnt[1] = L_b->size;
                p = L_b->begin;
//                printf("dentro da move_aux | digit_move: %d | L_b->size: %zu\n", digit_move, L_b->size);
                while (cnt[0]++ < cnt[1])
                {
//                        printf("Valor de index: %d | val: %d | digit_move: %d\n", p->index, p->val, digit_move);
                        if ((p->index >> digit_move) % 2)
                                ft_push_stack(L_b, L_a, "pa");
                        else
                                ft_rotato_stack(L_b, "rb");
//                        ft_list_print(L_a);
//                        ft_list_print(L_b);
                        p = L_b->begin;
                }
                while (L_b->size > 0)
                {
                        ft_push_stack(L_b, L_a, "pa");
//                        ft_list_print(L_a);
//                        ft_list_print(L_b);
                }
        }
//        printf("dentro da move | encerra a move\n");
}

void    ft_sort_five_hundred(List *L_a, List *L_b)
{
        int move;
        int now_move;

        move = 0;
        while ((1 << move) < L_a->size)
                ++move;
        now_move = 0;
//        while (now_move++ < move)
        while (L_a->ret != -5 || ft_list_size(L_b) != 0)
        {
//        printf("dentro do loop de sort others\n");
                now_move++;
                if ((now_move == move) && (now_move % 2))
                        ft_last_move(L_a, L_b, (now_move - 1));
                else
                        ft_move(L_a, L_b, (now_move - 1));
                L_a = ft_valid_input_order_asc(L_a);
        }
//        printf("fora do loop de sort others\n");
        L_a->ret = -5;
}

/*
void    ft_last_move(List *L_a, List *L_b, int digit_move)
{
//        printf("dentro da last move | digit_move: %d\n", digit_move);
        int     cnt[2];
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_a->size;
        p = L_a->begin;
        while (cnt[0]++ < cnt[1])
        {
//              printf("dentro da last move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
//                printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                if ((p->index >> digit_move) % 2 == 0)
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
        Node    *p;

        cnt[0] = 0;
        if (L_a->size > 0)
        {
                cnt[1] = L_a->size;
                p = L_a->begin;
                while (cnt[0]++ < cnt[1])
                {
//                        printf("dentro da move | dentro do 1º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
//                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                        if ((p->index >> digit_move) % 2 == 0)
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
//                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                        if ((p->index >> digit_move) % 2)
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
*/