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

static List *ft_valid_input_one(int argc, List *L);
static s_input ft_valid_input_two(int argc, char **argv, s_input ret);
static int      ft_valid_character(char *argv);

List *ft_valid_input(int argc, char **argv, List *L)
{
    ft_putendl_fd("Dentro do valid input", 1);
    L = ft_valid_input_one(argc, L);
    if (L->ret < 0)
        return (L);

    int     i;
    int     input_int;
    long    input_lg;

    i = 1;
    while (argv[i])
    {
        if (ft_valid_character(argv[i]) < 0)
        {
            L->ret = -2;
            return (L);
        }
        else
        {
            ft_putendl_fd("Validando se int", 1);
            input_lg = ft_atol(argv[i]);
            if ((input_lg > INT_MAX) || (input_lg < INT_MIN))
            {
                L->ret = -3;
                return (L);
            }
            else
            {
                ft_putendl_fd("Inserindo na lista", 1);
                input_int = (int)input_lg;
                List_add_last(L, input_int);
//                List_print(L);
//                List_inverted_print(L);
            }
        }
        i++;
    }
    ft_putendl_fd("chamada para a função para ordenar", 1);
    L = ft_valid_input_isorder(L);

/*
    ret = ft_valid_input_two(argc, argv, ret);
    if (ret.ret < 0)
    {
        return (ret);
    }
    ret.ret = 0;
*/
    return (L);
}

List	*ft_valid_input_isorder(List *L)
{
	ft_putendl_fd("Dentro da função que verifica a ordenação da lista", 1);
	Node	*p;
	Node	*q;

	if (List_is_empty(L) || List_size(L) == 1)
		return (L);
	p = L->begin;
	q = p->next;
	L->ret= -4;
	while (p != NULL && q != NULL)
	{
		if (p->val > q->val)
		{
			L->ret = 0;
			return (L);
		}
		p = p->next;
		q = q->next;
	}
	return (L);
}

List *ft_valid_input_one(int argc, List *L)
{
    ft_putendl_fd("Dentro do valid one", 1);
    int i;

    i = ft_valid_input_amount(argc);
    if (i == -1)
    {
        L->ret = -1;
        return (L);
    }
    L->ret = 0; // testar se é possível retirar isto.
    return (L);
}

static int      ft_valid_character(char *argv)
{
    int     i;
    char    *input;

    ft_putstr_fd("validando o character\n", 1);
    i = 0;
    input = "0123456789+-";
    while (argv[i])
    {
        if (!ft_strchr(input, argv[i]) && (!ft_isspace(argv[i])))
            return (-2);
        i++;
    }
    return (0);  
}

/*
List ft_valid_input_two(int argc, char **argv, s_input ret)
{
    int i;
    List aux;

    i = ft_valid_input_character(argv);
    if (i == -2)
    {
        ft_error();
        ret.ret = -2;
        return (ret);
    }
    ret = ft_valid_input_isint(argc, argv);
    if (ret.size < 0)
    {
        ft_error();
        ret.ret = -3;
        return (ret);
    }
    aux = ft_valid_input_isorder(ret);
    if (aux.order < 0)
    {
        ret.ret = -4;
        return (ret);
    }
    if (ft_valid_input_isduplic(aux) < 0)
    {
        ft_error();
        ret.ret = -5;
        return (ret);
    }
    return (ret);
}
*/
