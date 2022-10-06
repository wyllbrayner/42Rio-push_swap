/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:15:21 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 20:03:25 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*big_ptr;
	size_t	size_little;

	if (*little == '\0')
		return ((char *) big);
	big_ptr = (char *) big;
	size_little = ft_strlen(little);
	while (len != 0 && *little != '\0' && *big_ptr != '\0')
	{
		big_ptr = ft_strchr(big_ptr, *little);
		if (big_ptr && (big_ptr - big + size_little <= len))
		{
			i = 0;
			while ((little[i] == big_ptr[i]) && little[i])
				i++;
			if (i == size_little)
				return (big_ptr);
			big_ptr += 1;
		}
		else
			break ;
	}
	return (NULL);
}
