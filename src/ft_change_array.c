/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int	ft_count_word(char *argv, char c)
{
	int	qtd_word;
	int	flag;
	int	i;

	qtd_word = 0;
	flag = 0;
	i = 0;
	while (argv[i])
	{
		if ((argv[i] != c) && (flag == 0))
		{
			qtd_word++;
			flag = 1;
		}
		else if ((argv[i] == c) && (flag == 1))
			flag = 0;
		i++;
	}
	return (qtd_word);
}

int	ft_valid_len_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			j += ft_count_word(argv[i], ' ');
		else
			j++;
		i++;
	}
}

char	**ft_split_input(t_list *l_a, int argc, char **argv)
{
	int		len;
	int		i;
	int		j;
	char	**argv2;
	char	**tmp;

	len = ft_valid_len_input(char **argv);
	i = 0;
	j = 0;
	argv2 = (char **)malloc(sizeof(char *) * len + 1);
	if (!argv2)
	{
		l_a->ret = -500;
		return (NULL);
	}
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			tmp = ft_split(argv[i], ' ');
			if (!tmp)
			{
				l_a->ret = -500;
				return (NULL);
			}
			while (*tmp)
			{
				arg2[j] = ft_strdup(tmp);
				j++;
				tmp++;
			}
			ft_free_2point(&tmp);
		}
		else
		{
			arg2[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	return (argv2);
}


