/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:30:26 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:46:15 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c_chr;
	unsigned char	*s_chr;

	c_chr = (unsigned char) c;
	s_chr = (unsigned char *) s;
	while (n--)
	{
		if (*s_chr == c_chr)
			return ((void *)s_chr);
		s_chr++;
	}
	return (NULL);
}
