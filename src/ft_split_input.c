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

int	ft_count_word(char const *argv, char c)
{
//	printf("Dentro da count_word\n");
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
//	printf("Encerrando a count_word com qtd_word: %d\n", qtd_word);
	return (qtd_word);
}

int	ft_len_input(char **argv)
{
//	printf("Dentro da valid_len_input\n");
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
//		printf("Dentro do loop da valid_len_input: i: %d | j: %d | argv[i]: %s\n", i, j, argv[i]);
		if (ft_strchr(argv[i], ' '))
		{
			j += ft_count_word(argv[i], ' ');
		}
		else
			j++;
		i++;
	}
//	printf("Fora do loop da valid_len_input: i: %d | j: %d\n", i, j);
	return (j);
}

char	**ft_split_input(t_list *l_a, int argc, char **argv)
{
//	printf("Dentro da split_input\n");
	int		len;
	int		i;
	int		j;
	int		k;
	char	**argv2;
	char	**tmp;

//	printf("Dentro da split_input | chama a valid_len_input\n");
	len = (ft_len_input(argv));
//	printf("Dentro da split_input | retorna da valid_len_input com len: %d\n", len);
	i = 1;
	j = 0;
	argv2 = (char **)malloc(sizeof(char *) * (len + 1));
	if (!argv2)
	{
//		printf("Na split_input | l_a->ret = -500, pois não conseguiu malloc.\n");
		l_a->ret = -500;
		return (NULL);
	}
//	printf("Na split_input | após a validação do malloc de char * de len + 1: %d\n", len + 1);
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' '))
		{
//			printf("Na split_input | dentro do loop argv[%d]: %s | dentro do if\n", i, argv[i]);
			tmp = ft_split(argv[i], ' ');
			k = 0;
			while (tmp[k])
			{
//				printf("Na split_input | dentro do loop argv[%d]: %s | dentro do if e após a ft_split: tmp[%d]: %s\n", i, argv[i], k, tmp[k]);
				k++;
			}
			if (!tmp)
			{
				l_a->ret = -500;
				return (NULL);
			}
			k = 0;
			while (tmp[k])
			{
				argv2[j] = ft_strdup(tmp[k]);
//				printf("Na split_input | dentro do loop argv[%d]: %s | dentro do if e colocando o valor da ft_split: argv2[%d]: %s = tmp[%d]: %s\n", i, argv[i], j, argv2[j], k, tmp[k]);
				j++;
				k++;
			}
			ft_free_2point(tmp);
		}
		else
		{
			argv2[j] = ft_strdup(argv[i]);
//			printf("Na split_input | dentro do loop argv[%d]: %s | dentro do else e colocando o valor da ft_split: argv2[%d]: %s = argv[%d]: %s\n", i, argv[i], j, argv2[j], i, argv[i]);
			j++;
		}
		i++;
	}
//	printf("Chegou aqui!\n");
	argv2[j] = NULL;

	while (j >= 0)
	{
//		printf("Conteúdo de argv2[%d]: %s\n", j, argv2[j]);
		j--;
	}
	j = 0;
	while (argv2[j])
	{
//		printf("Conteúdo de argv2[%d]: %s\n", j, argv2[j]);
		j++;
	}
//	printf("Conteúdo de argv2[%d]: %s\n", j, argv2[j]);
//	printf("Passou daqui!!\n");
	return (argv2);
}


