/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	int		signal;
	long	nbr;

	i = 0;
	signal = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = (10 * nbr) + (str[i] - '0');
		i++;
	}
	return (signal * nbr);
}

int	ft_isspace(int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	if ((chr >= 9 && chr <= 13) || (chr == 32))
		return (TRUE);
	return (FALSE);
}

t_list	*ft_valid_input_order_asc(t_list *l)
{
	t_node	*p;
	t_node	*q;

	l->ret = -5;
	if ((ft_list_is_empty(l)) || (ft_list_size(l) == 1))
		return (l);
	p = l->begin;
	q = p->next;
	while (p != NULL && q != NULL)
	{
		if (p->val > q->val)
		{
			l->ret = 0;
			return (l);
		}
		p = p->next;
		q = q->next;
	}
	return (l);
}

t_list	*ft_valid_input_order_desc(t_list *l)
{
	t_node	*p;
	t_node	*q;

	l->ret = -5;
	if ((ft_list_is_empty(l)) || (ft_list_size(l) == 1))
		return (l);
	p = l->begin;
	q = p->next;
	while (p != NULL && q != NULL)
	{
		if (p->val < q->val)
		{
			l->ret = 0;
			return (l);
		}
		p = p->next;
		q = q->next;
	}
	return (l);
}

void	ft_list_to_array(t_list *l, int **sort)
{
	t_node	*ntmp;
	int		*itmp;
	size_t	i;

	itmp = (int *)malloc(ft_list_size(l) * sizeof(int));
	if (!itmp)
		return ;
	ntmp = l->begin;
	i = 0;
	while (ntmp != NULL)
	{
		itmp[i] = ntmp->val;
		ntmp = ntmp->next;
		i++;
	}
	*sort = itmp;
}
