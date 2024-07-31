/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:23:54 by woliveir          #+#    #+#             */
/*   Updated: 2022/05/09 15:09:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_ptr(char **ptr);

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptret;

	len = ft_strlen(str);
	ptret = ft_calloc(1, (len + 1));
	if (!ptret)
		return (NULL);
	if (ft_memcpy(ptret, str, len) == NULL)
	{
		ft_free_ptr(&ptret);
		return (NULL);
	}
	return (ptret);
}

static void	ft_free_ptr(char **ptr)
{
	char	*tmp;

	tmp = *ptr;
	free(tmp);
	*ptr = NULL;
}
