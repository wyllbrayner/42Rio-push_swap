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

int      ft_valid_input_amount(int argc)
{
//    ft_putstr_fd("validando o input amount\n", 1);
    if (argc == 1)
        return (-1);
    return (0);  
}

int      ft_valid_input_character(char **argv)
{
    int     i;
    int     j;
    char    *input;

    ft_putstr_fd("validando o input character\n", 1);
    i = 0;
    input = "0123456789+-";
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_strchr(input, argv[i][j]) && (!ft_isspace(argv[i][j])))
                return (-2);
            j++;
        }
        i++;
    }
    return (0);  
}


/*
List  ft_valid_input_isorder(List L)
{
    long    i;
    long    j;
    long    aux;

    ft_putstr_fd("validando o input order\n", 1);
    i = 0;
    L.order = -4;
    while (i < L.size)
    {
        j = i + 1;
        while (j < L.size)
        {
            if (L.arr[i] > L.arr[j])
            {
                if (L.order == -4)
                    L.order = 0;
                aux = L.arr[i];
                L.arr[i] = L.arr[j];
                L.arr[j] = aux; 
            }
            j++;
        }
        i++;
    }
    return (val);
}
*/

/*
List  ft_valid_input_isint(int argc, char **argv)
{
    ft_putstr_fd("validando o input isint\n", 1);
    int     i;
    List ret;

    i = 1;
    while (argv[i])
    {
        ret.arr[i - 1] = ft_atol(argv[i]);
        if((ret.arr[i - 1] > INT_MAX) || (ret.arr[i - 1] < INT_MIN))
        {
            ret.size = -3;
            return (ret);
        }
        i++;
    }
    ret.size = (i - 1);
    return (ret);
}

int ft_valid_input_isduplic(List val)
{
    long    i;

    ft_putstr_fd("validando o input duplici\n", 1);
    i = 0;
    while (i < (val.size - 1))
    {
        if (val.arr[i] == val.arr[i + 1])
            return (-5);
        i++;
    }
    return (0);
}
*/