/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:23:54 by woliveir          #+#    #+#             */
/*   Updated: 2022/05/09 15:09:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strret;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && (ft_strchr(set, s1[start])))
		start++;
	end = (ft_strlen(s1));
	while (end > start && (ft_strchr(set, s1[end - 1])))
		end--;
	strret = (char *)ft_calloc(sizeof(char), (end - start + 1));
	if (!strret)
		return (NULL);
	i = 0;
	while (start < end)
		strret[i++] = s1[start++];
	return (strret);
}
