/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:42:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/05 11:09:33 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

int	ft_is_already_sort(t_list *list)
{
	int	*number;
	int	*next_number;

	number = list->content;
	list = list->next;
	while (list)
	{
		next_number = (int *)list->content;
		if (*number < *next_number)
			return (FALSE);
		number = next_number;
		list = list->next;
	}
	ft_lstclear(&list, ft_free_null);
	return (TRUE);
}

void	ft_initialize_stack_a(t_stack *stack_a, t_list *reverse_input)
{
	int	*number;

	while (reverse_input)
	{
		number = reverse_input->content;
		ft_stack_push(stack_a, ft_new_stack_node(*number));
		reverse_input = reverse_input->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_list	*reverse_input;
	int		*sort;

	ft_new_stack(&stack_a);
	reverse_input = NULL;
	sort = NULL;
	ft_parse(argc, argv, &reverse_input, &sort);
	if (ft_is_already_sort(reverse_input))
		return (SUCCESS);
	ft_initialize_stack_a(&stack_a, reverse_input);
	ft_lstclear(&reverse_input, ft_free_null);
//	int i = 0;
//	while (i < 3 )
//	{
//		printf("valor de i: %d | sort: %d\n", i, sort[i]);
//		i++;
//	}
//	t_node *node;
//	node = stack_a.top;
//	i = 0;
//	while (i < 3)
//	{
//		printf("Valor de node: %d | i: %d\n", node->element, i);
//		node = node->next;
//		i++;
//	}
//
//1|2|3 não entra (array ordenado)
//1|3|2
//2|1|3
//2|3|1
//3|1|2
//3|2!1
//
//0|1|2|3|15 sort
//
//qtd = 0
//l_a size = 5 - 3|2|1|15|0
//L_b size = 0
//L_a size = 5 - 2|1|15|0|3 ra
//L_b size = 0
//L_a size = 5 - 1|15|0|3|2 ra
//L_b size = 0
//L_a size = 4 - 15|0|3|2 pb
//L_b size = 1 - 1(G2)
//L_a size = 4 - 0|3|2|15 ra
//L_b size = 1 - 1(G2)
//L_a size = 3 - 3|2|15 pb
//L_b size = 2 - 1(G2)|0(G2)
//ordena 3
//L_a size = 3 - 2|3|15 sa
//L_b size = 2 - 1(G2)|0(G2)
//
//
//size = 5
//pivot.index = size / 2 = 3 (cai no if, então index = 2) 
//pivot.value = sort[index] = 2
//pivot.qtd   = index = 2
//pivot.group - !
//pivot.first = first = 1 
//
	ft_sort(&stack_a, sort);
	free(sort);
	return (SUCCESS);
}
