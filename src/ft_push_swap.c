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
    List    *L_b;

    push_swap = List_create();
    if (!push_swap)
        return (-1);
    L_b = List_create();
    if (!L_b)
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
		List_destroy(&push_swap);
		ft_putstr_fd("push_swap == NULL: ", 1);
		ft_putnbr_fd(push_swap == NULL, 1);
		ft_putstr_fd("\n", 1);
        return (-1);
    }
    else
    {
        ft_putendl_fd("Seguir com o programa", 1);
		ft_swap_stack(push_swap);
		ft_rotato_stack(push_swap);
		ft_reverse_rotato_stack(push_swap);
        int i;
        i = 0;
        while (push_swap->size != 0)
        {
            printf("Push de a para b\n");
            ft_push_stack(push_swap, L_b);
            printf("Valor de i: %d\n", i);
            i++;
        }
        i = 0;
        while (L_b->size != 0)
        {
            printf("Push de b para a\n");
            ft_push_stack(L_b, push_swap);
            printf("Valor de i: %d\n", i);
            i++;
        }
    }
    List_destroy(&push_swap);
    printf("push_swap == NULL: %d\n", push_swap == NULL);
    List_destroy(&L_b);
    printf("L_b == NULL: %d\n", L_b == NULL);
	return (0);
}
