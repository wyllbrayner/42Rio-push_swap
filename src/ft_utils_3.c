/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

static void	ft_free_sort(int **sort);

void	ft_free_list(t_list **l_a, t_list **l_b)
{
//	printf("Chegou na free_list!!!\n");
	if (*l_a)
	{
//		printf("Entrou para liberar l_a!!!\n");
		ft_list_destroy(l_a);
	}
	if (*l_b)
	{
//		printf("Entrou para liberar l_b!!!\n");
		ft_list_destroy(l_b);
	}
}

void	ft_free_structs(t_list **l_a, t_list **l_b, int **sort, char **str)
{
//	printf("Chegou na free_structs!!!\n");
//	printf("Vai chamar a free_list!!!\n");
	ft_free_list(l_a, l_b);
//	printf("Retornou para free_structs, após free_list!!!\n");
	if (*sort) ///analisar pois vai dar perda de memória
	{
//		printf("Vai chamar a free_sort!!!\n");
		ft_free_sort(sort);
//		printf("Retornou para free_structs, após free_sort!!!\n");
	}
//	printf("Vai chamar a free_2point!!!\n");
	ft_free_2point(str);
//	printf("Retornou para free_structs, após free_2point!!!\n");
}

void	ft_free_2point(char **str)
{
//	printf("Chegou na free_2point!!!\n");
	long int	i;
	long int	j;
	char		**tmp;

	i = 0;
	tmp = str;
	while (tmp[i] != NULL)
		i++;
	j = 0;
//	printf("Vai iniciar o loop de liberação!!!\n");
	while (i >= 0)
	{
//		printf("free vai libarar i: %ld | val: %s\n", i, tmp[i]);
//		printf("Libera ponteiro dentro do loop!!!\n");
		free(tmp[i]);
//		printf("Após liberar ponteiro dentro do loop!!!\n");
		tmp[i] = NULL;
		i--;
	}
//	printf("Encerra o loop para liberar o ponteiro geral!!!\n");
	free(tmp);
	str = NULL;
//	printf("O conteudo do pontero geral passa a ser NULL!!!\n");

}

static void	ft_free_sort(int **sort)
{
//	printf("Chegou na free_sort!!!\n");
	int	*tmp;

	tmp = *sort;
//	printf("Vai liberar sort!!!\n");
	free(tmp);
//	printf("Após liberar sort!!!\n");
	*sort = NULL;
//	printf("O conteudo do pontero de sort passa a ser NULL!!!\n");
}