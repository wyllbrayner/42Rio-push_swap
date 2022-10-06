/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:35:35 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/04 21:11:33 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_long;
	char		buffer[11];
	int			dig;
	int			i;

	n_long = n;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n_long < 0)
		n_long = -n_long;
	i = 10;
	while (n_long > 0)
	{
		dig = n_long % 10;
		buffer[i] = '0' + dig ;
		n_long /= 10;
		i--;
	}
	i++;
	if (n < 0)
		buffer[--i] = '-';
	write(fd, buffer + i, 11 - i);
}
