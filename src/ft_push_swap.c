/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/09/02 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_push_swap.h"

int ft_push_swap(int argc, char **argv)
{
    List    *push_swap;

    push_swap = List_create();
    if (!push_swap)
        return (-1);
//    ft_putendl_fd("Dentro da push_swap", 1);
    push_swap = ft_valid_input(argc, argv, push_swap);
    ft_putstr_fd("imprimindo o array retornado pela validação\n", 1);
    ft_putstr_fd("O retorno da validação foi: ", 1);
    ft_putnbr_fd(push_swap->ret, 1);
    ft_putstr_fd("\nO size do array é: ", 1);
    ft_putnbr_fd(push_swap->size, 1);
    ft_putstr_fd("\n", 1);
    List_print(push_swap);
    List_inverted_print(push_swap);
	if (push_swap->ret != 0)
    {   
        ft_putendl_fd("encerra programa", 1);
        return (-1);
    }
    else
    {
        ft_putendl_fd("Seguir com o programa", 1);
        return (0);
    }
    List_destroy(&push_swap);
	ft_putstr_fd("push_swap == NULL: ", 1);
	ft_putnbr_fd(push_swap == NULL, 1);

    printf("push_swap == NULL: %d\n", push_swap == NULL);
	return (0);
}
