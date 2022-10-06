/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:27:58 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/09/17 22:24:22 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_dig(long int n)
{
	size_t	dig;

	dig = 0;
	if (n <= 0)
		dig = 1;
	while (n != 0)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

char	*ft_itoa(int value)
{
	int				dig;
	long int		n;
	char			*a;
	int				stop;

	n = (long int) value;
	dig = (int) ft_dig(n);
	a = (char *) malloc(dig + 1);
	if (!a)
		return (NULL);
	a[dig--] = '\0';
	stop = 0;
	if (n < 0)
	{
		a[0] = '-';
		n = -n;
		stop = 1;
	}
	while (dig >= stop)
	{
		a[dig--] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
