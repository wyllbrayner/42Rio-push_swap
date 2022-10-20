/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static int	ft_len_input(char **argv);
static int	ft_count_word(char const *argv, char c);
static char	**ft_split_arg(t_list *l_a, char **argv, char **argv2, char **tmp);

char	**ft_split_input(t_list *l_a, int argc, char **argv)
{
	char	**argv2;
	char	**tmp;

	argv2 = (char **)malloc(sizeof(char *) * (ft_len_input(argv) + 1));
	if (!argv2)
	{
		l_a->ret = -500;
		return (NULL);
	}
	argv2 = ft_split_arg(l_a, argv, argv2, tmp);
	return (argv2);
}

static int	ft_len_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			j += ft_count_word(argv[i], ' ');
		else
			j++;
		i++;
	}
	return (j);
}

static int	ft_count_word(char const *argv, char c)
{
	int	qtd_word;
	int	flag;

	qtd_word = 0;
	flag = 0;
	while (*argv)
	{
		if ((*argv != c) && (flag == 0))
		{
			qtd_word++;
			flag = 1;
		}
		else if ((*argv == c) && (flag == 1))
			flag = 0;
		argv++;
	}
	return (qtd_word);
}

static char	**ft_split_arg(t_list *l_a, char **argv, char **argv2, char **tmp)
{
	int	cnt[3];

	cnt[0] = 1;
	cnt[1] = 0;
	while (argv[cnt[0]] != NULL)
	{
		if (ft_strchr(argv[cnt[0]], ' '))
		{
			tmp = ft_split(argv[cnt[0]], ' ');
			if (!tmp)
			{
				l_a->ret = -500;
				return (NULL);
			}
			cnt[2] = 0;
			while (tmp[cnt[2]])
				argv2[cnt[1]++] = ft_strdup(tmp[cnt[2]++]);
			ft_free_2point(tmp);
		}
		else
			argv2[cnt[1]++] = ft_strdup(argv[cnt[0]]);
		cnt[0]++;
	}
	argv2[cnt[1]] = NULL;
	return (argv2);
}
