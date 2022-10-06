/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:42:20 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/09/14 22:00:06 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_chr;
	unsigned char	*s2_chr;

	s1_chr = (unsigned char *) s1;
	s2_chr = (unsigned char *) s2;
	while (n--)
	{
		if (*s1_chr != *s2_chr)
			return (*s1_chr - *s2_chr);
		s1_chr++;
		s2_chr++;
	}
	return (0);
}
