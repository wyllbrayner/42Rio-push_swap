/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:02:35 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:47:24 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_chr;
	int		i;

	c_chr = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_chr)
			return ((char *)(s + i));
		i++;
	}
	if (!c_chr)
		return ((char *)(s + i));
	return (NULL);
}
