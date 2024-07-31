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

static void	ft_move(t_list *l_a, t_list *l_b, int digit_move);
static void	ft_move_aux(t_list *l_a, t_list *l_b, int digit_move);
static void	ft_last_move(t_list *l_a, t_list *l_b, int digit_move);

void	ft_sort_five_hundred(t_list *l_a, t_list *l_b)
{
	int	move;
	int	now_move;

	move = 0;
	while ((1 << move) < l_a->size)
		++move;
	now_move = 0;
	while (l_a->ret != -5 || ft_list_size(l_b) != 0)
	{
		now_move++;
		if ((now_move == move) && (now_move % 2))
			ft_last_move(l_a, l_b, (now_move - 1));
		else
			ft_move(l_a, l_b, (now_move - 1));
		l_a = ft_valid_input_order_asc(l_a);
	}
	l_a->ret = -5;
}

static void	ft_move(t_list *l_a, t_list *l_b, int digit_move)
{
	int		cnt[2];
	t_node	*p;

	cnt[0] = 0;
	if (l_a->size > 0)
	{
		cnt[1] = l_a->size;
		p = l_a->begin;
		while (cnt[0]++ < cnt[1])
		{
			if ((p->index >> digit_move) & 1)
				ft_rotato_stack(l_a, "ra");
			else
				ft_push_stack(l_a, l_b, "pb");
			p = l_a->begin;
		}
		while (l_a->size > 0)
			ft_push_stack(l_a, l_b, "pb");
	}
	else
		ft_move_aux(l_a, l_b, digit_move);
}

static void	ft_move_aux(t_list *l_a, t_list *l_b, int digit_move)
{
	int		cnt[2];
	t_node	*p;

	cnt[0] = 0;
	cnt[1] = l_b->size;
	p = l_b->begin;
	while (cnt[0]++ < cnt[1])
	{
		if ((p->index >> digit_move) & 1)
			ft_push_stack(l_b, l_a, "pa");
		else
			ft_rotato_stack(l_b, "rb");
		p = l_b->begin;
	}
	while (l_b->size > 0)
		ft_push_stack(l_b, l_a, "pa");
}

static void	ft_last_move(t_list *l_a, t_list *l_b, int digit_move)
{
	int		cnt[2];
	t_node	*p;

	cnt[0] = 0;
	cnt[1] = l_a->size;
	p = l_a->begin;
	while (cnt[0]++ < cnt[1])
	{
		if ((p->index >> digit_move))
			ft_rotato_stack(l_a, "ra");
		else
			ft_push_stack(l_a, l_b, "pb");
		p = l_a->begin;
	}
	while (l_b->size > 0)
		ft_push_stack(l_b, l_a, "pa");
}
