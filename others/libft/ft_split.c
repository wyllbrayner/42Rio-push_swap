/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:52:59 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 20:35:23 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len(char const *s, char c)
{
	int		n;
	int		i;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (*s != c && *s)
		{
			s++;
			i++;
		}
		if (i > 0)
			n++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		i;
	char	*str;
	char	**set;

	if (!s)
		return (NULL);
	n = len(s, c);
	set = (char **) malloc((n + 1) * sizeof(char *));
	if (!set)
		return (NULL);
	set[n] = NULL;
	i = 0;
	str = (char *) s;
	while (*s && i < n)
	{		
		while (*str == c)
			str++;
		s = str;
		while (*str != c && *str)
			str++;
		set[i++] = ft_substr(s, 0, str - s);
	}
	return (set);
}
