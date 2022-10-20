/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_free_sort(int **sort);

void	ft_free_list(t_list **l_a, t_list **l_b)
{
	if (*l_a)
		ft_list_destroy(l_a);
	if (*l_b)
		ft_list_destroy(l_b);
}

void	ft_free_structs(t_list **l_a, t_list **l_b, int **sort, char **str)
{
	ft_free_list(l_a, l_b);
	if (*sort)
		ft_free_sort(sort);
	ft_free_2point(str);
}

void	ft_free_2point(char **str)
{
	long int	i;
	long int	j;
	char		**tmp;

	i = 0;
	tmp = str;
	while (tmp[i] != NULL)
		i++;
	j = 0;
	while (i >= 0)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i--;
	}
	free(tmp);
	str = NULL;
}

static void	ft_free_sort(int **sort)
{
	int	*tmp;

	tmp = *sort;
	free(tmp);
	*sort = NULL;
}
