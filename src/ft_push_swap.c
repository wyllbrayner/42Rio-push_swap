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
    List    *L_a;
    List    *L_b;

    L_a = List_create();
    if (!L_a)
        return (-1);
    L_b = List_create();
    if (!L_b)
    {
		List_destroy(&L_a);
        printf("L_a == NULL: %d\n", L_a == NULL);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    ft_putstr_fd("imprimindo o array retornado pela validação\n", 1);
    ft_putstr_fd("O retorno da validação foi: ", 1);
    ft_putnbr_fd(L_a->ret, 1);
    ft_putstr_fd("\n", 1);
    List_print(L_a);
    List_inverted_print(L_a);
	if (L_a->ret != 0)
    {   
        ft_putendl_fd("encerra programa", 1);
		List_destroy(&L_a);
		ft_putstr_fd("L_a == NULL: ", 1);
		ft_putnbr_fd(L_a == NULL, 1);
		ft_putstr_fd("\n", 1);
		List_destroy(&L_b);
		ft_putstr_fd("L_b == NULL: ", 1);
		ft_putnbr_fd(L_b == NULL, 1);
		ft_putstr_fd("\n", 1);
        return (-1);
    }
    else
    {
        ft_putendl_fd("Seguir com o programa", 1);
		ft_swap_stack(L_a);
		ft_rotato_stack(L_a);
		ft_reverse_rotato_stack(L_a);
        int i;
        i = 0;
        while (L_a->size != 0)
        {
            printf("Push de a para b\n");
            ft_push_stack(L_a, L_b);
            printf("Valor de i: %d\n", i);
            i++;
        }
        i = 0;
        while (L_b->size != 0)
        {
            printf("Push de b para a\n");
            ft_push_stack(L_b, L_a);
            printf("Valor de i: %d\n", i);
            i++;
        }
    }
    List_destroy(&L_a);
    printf("L_a == NULL: %d\n", L_a == NULL);
    List_destroy(&L_b);
    printf("L_b == NULL: %d\n", L_b == NULL);
	return (0);
}
