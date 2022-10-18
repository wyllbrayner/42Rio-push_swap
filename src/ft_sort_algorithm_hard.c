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

static void    ft_move(List *L_a, List *L_b, int digit_move);
static void    ft_move_aux(List *L_a, List *L_b, int digit_move);
static void    ft_last_move(List *L_a, List *L_b, int digit_move);

void    ft_sort_five_hundred(List *L_a, List *L_b)
{
        int move;
        int now_move;

        move = 0;
        while ((1 << move) < L_a->size)
                ++move;
        now_move = 0;
        while (L_a->ret != -5 || ft_list_size(L_b) != 0)
        {
                now_move++;
                if ((now_move == move) && (now_move % 2))
                        ft_last_move(L_a, L_b, (now_move - 1));
                else
                        ft_move(L_a, L_b, (now_move - 1));
                L_a = ft_valid_input_order_asc(L_a);
        }
        L_a->ret = -5;
}

static void    ft_move(List *L_a, List *L_b, int digit_move)
{
        int     cnt[2];
        Node    *p;

        cnt[0] = 0;
        if (L_a->size > 0)
        {
                cnt[1] = L_a->size;
                p = L_a->begin;
                while (cnt[0]++ < cnt[1])
                {
                        if ((p->index >> digit_move) % 2 == 1)
                                ft_rotato_stack(L_a, "ra");
                        else
                                ft_push_stack(L_a, L_b, "pb");
                        p = L_a->begin;
                }
                while (L_a->size > 0)
                        ft_push_stack(L_a, L_b, "pb");
        }
        else
                ft_move_aux(L_a, L_b, digit_move);
}

static void    ft_move_aux(List *L_a, List *L_b, int digit_move)
{
        int     cnt[2];
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_b->size;
        p = L_b->begin;
        while (cnt[0]++ < cnt[1])
        {
                if ((p->index >> digit_move) % 2)
                        ft_push_stack(L_b, L_a, "pa");
                else
                        ft_rotato_stack(L_b, "rb");
                p = L_b->begin;
        }
                while (L_b->size > 0)
                        ft_push_stack(L_b, L_a, "pa");
}

static void    ft_last_move(List *L_a, List *L_b, int digit_move)
{
        int     cnt[2];
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_a->size;
        p = L_a->begin;
        while (cnt[0]++ < cnt[1])
        {
                if ((p->index >> digit_move))
                        ft_rotato_stack(L_a, "ra");                
                else
                        ft_push_stack(L_a, L_b, "pb");
                p = L_a->begin;
        }
        while (L_b->size > 0)
                ft_push_stack(L_b, L_a, "pa");
}