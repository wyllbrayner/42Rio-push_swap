/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:29:56 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:45:52 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*sc1;
	const char	*sc2;

	if (!s1 && !s2)
		return (NULL);
	sc1 = s1;
	sc2 = s2;
	if ((sc1 > sc2) && (sc2 + n > sc1))
	{
		sc1 += n;
		sc2 += n;
		while (n--)
			*--sc1 = *--sc2;
	}
	else
	{
		while (n--)
			*sc1++ = *sc2++;
	}
	return (s1);
}
