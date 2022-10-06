/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:49:59 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/09/17 11:38:51 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	end = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, *(s1 + start)))
		start++;
	while (ft_strchr(set, *(s1 + end)) && (end >= 0))
		end--;
	if (start > end)
		end = start - 1;
	trimmed = (char *) malloc (end - start + 2);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
