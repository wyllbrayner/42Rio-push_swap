/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:46:46 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:47:39 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_chr;
	int		s_len;

	c_chr = (char) c;
	s_len = ft_strlen(s);
	if (c_chr == '\0')
		return ((char *)(s + s_len));
	while (s_len--)
	{
		if (s[s_len] == c_chr)
			return ((char *)(s + s_len));
	}
	return (NULL);
}
