/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:34:39 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/08/20 20:48:59 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*join;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *) malloc(len);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
	{
		join[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		join[i] = *s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
