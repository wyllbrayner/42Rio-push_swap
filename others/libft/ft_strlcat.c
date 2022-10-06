/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:46:46 by hsouza-s          #+#    #+#             */
/*   Updated: 2022/10/03 19:18:37 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dst_len;
	size_t	src_len;

	if (n == 0)
		return (ft_strlen(src));
	dst_len = 0;
	while (*dst++)
	{
		dst_len++;
	}
	dst--;
	if (n < dst_len || n == 0)
		return (n + ft_strlen(src));
	src_len = ft_strlcpy(dst, src, n - dst_len);
	return (src_len + dst_len);
}
