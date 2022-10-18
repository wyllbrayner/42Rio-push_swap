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

void	ft_list_to_array(List *L_a, int **sort)
{
	Node 	*ntmp;
	int 	*itmp;
	size_t	i;

	itmp = (int *)malloc(ft_list_size(L_a) * sizeof(int));
	if (!itmp)
 		return ;
	ntmp = L_a->begin;
	i = 0;
	while (ntmp != NULL)
	{
		itmp[i] = ntmp->val;
		ntmp = ntmp->next;
		i++;
	}
	*sort = itmp;
}

int *ft_order_arr(int *sort, size_t len)
{
    size_t    i;
    size_t    j;
    size_t    aux;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (sort[i] > sort[j])
            {
                aux = sort[i];
                sort[i] = sort[j];
                sort[j] = aux; 
            }
            j++;
        }
        i++;
    }
    return (sort);
}

void ft_free_sort(int **sort)
{
	int *tmp;

	tmp = *sort;
	free(tmp);
	*sort = NULL;

}

List	*ft_put_index(List *L, int *sort)
{
	Node	*p;
	size_t	i;

	p = L->begin;
	while (p != NULL)
	{
		i = 0;
		while (i < L->size)
		{
			if (p->val == sort[i])
			{
				p->index = i;
				break ;
			} 
			i++;
		}
		p = p->next;
	}
	return (L);
}

int	ft_sqrt(int n)
{
	long long	lb;
	long long	ub;
	long long	mid;

	if (n <= 1LL)
		return (n);
	lb = 0LL;
	ub = (long long)n;
	while (ub - lb > 1LL)
	{
		mid = (lb + ub) / 2LL;
		if (mid * mid <= (long long)n)
			lb = mid;
		else
			ub = mid;
	}
	return ((int)lb);
}

/*
int ft_sqrt(int n)
{
	int sqrt;

	if (n == 0)
    	return (0);
	else if (n == 1)
        return (1);
	sqrt = 1;
	while ((sqrt * sqrt) < n)
	    sqrt++;
    return (--sqrt);
}
*/

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}