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

long    ft_atol(char *str)
{
    int     i;
    int     signal;
    long    nbr;

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
		return (1);
	return (0);
}

List	*ft_valid_input_order_asc(List *L)
{
	Node	*p;
	Node	*q;

	L->ret = -5;
	if ((ft_list_is_empty(L)) || (ft_list_size(L) == 1))
		return (L);
	p = L->begin;
	q = p->next;
	while (p != NULL && q != NULL)
	{
		if (p->val > q->val)
		{
			L->ret = 0;
			return (L);
		}
		p = p->next;
		q = q->next;
	}
	return (L);
}

List	*ft_valid_input_order_desc(List *L)
{
	Node	*p;
	Node	*q;

	L->ret = -5;
	if ((ft_list_is_empty(L)) || (ft_list_size(L) == 1))
		return (L);
	p = L->begin;
	q = p->next;
	while (p != NULL && q != NULL)
	{
		if (p->val < q->val)
		{
			L->ret = 0;
			return (L);
		}
		p = p->next;
		q = q->next;
	}
	return (L);
}

void	ft_list_to_array(List *L_a, int *sort)
{
	printf("Entrou na função\n");
	Node 	*tmp;
	int		*itmp;

	itmp = (int *)malloc(ft_list_size(L_a));
	if (!itmp)
		return ;
//	else
//		printf("O malloc não falhou\n");
//	int		itmp[ft_list_size(L_a)];
//	printf("atualizou o int\n");
	size_t	i;
	
//	printf("Vai imprimir a lista recebida\n");
//	ft_list_print(L_a);
	tmp = L_a->begin;;
	i = 0;
	while (tmp != NULL)
	{
//		printf("entrou no loop\n");
//		printf("valor de tmp->val: %d | i: %zu\n", tmp->val, i);
		itmp[i] = tmp->val;
//		printf("valor de tmp->val: %d | i: %zu\n", tmp->val, i);
		tmp = tmp->next;
		i++;
	}
	sort = itmp;
	i = 0;
	while (i < ft_list_size(L_a))
	{
		printf("itmp[%zu]: %d | sort[%zu]: %d\n", i, itmp[i], i, sort[i]);
		i++;
	}
//	sort = itmp;
}

