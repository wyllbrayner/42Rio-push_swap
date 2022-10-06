/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:02:39 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:48:12 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*dup;

	n = ft_strlen(s) + 1;
	dup = (char *) malloc (n);
	if (!dup)
		return (NULL);
	n = 0;
	while (*s)
	{
		dup[n] = *s++;
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
