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

static  void ft_select_function(List *L_a, List *L_b);
void    ft_sort_two(List *L_a);
void    ft_sort_three_a(List *L_a);
void    ft_sort_three_a_aux(List *L_a);
void    ft_sort_three_b(List *L_b);
void    ft_sort_three_b_aux(List *L_b);
void    ft_sort_five(List *L_a, List *L_b);
void    ft_sort_more_than_five(List *L_a, List *L_b);

int ft_push_swap(int argc, char **argv)
{
    List    *L_a;
    List    *L_b;

    L_a = ft_list_create();
    L_b = ft_list_create();
    if (!L_b || !L_a)
    {
        ft_list_destroy(&L_a);
        ft_list_destroy(&L_b);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    if (L_a->ret == 0)
    {
//        ft_putstr_fd("Valor de ret de l_a: ", 1);
//        ft_putnbr_fd(L_a->ret, 1);
//        ft_putstr_fd("\n", 1);
    	ft_list_print(L_a);
        ft_select_function(L_a, L_b);
    }
    ft_putstr_fd("Resultado da ordenação\n", 1);
    ft_putstr_fd("Valor de ret de l_a: ", 1);
    ft_putnbr_fd(L_a->ret, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("stack l_a: \n", 1);
	ft_list_print(L_a);
    ft_putstr_fd("stack l_b: \n", 1);
	ft_list_print(L_b);
    ft_list_destroy(&L_a);
    ft_list_destroy(&L_b);
    ft_putstr_fd("L_a == NULL: ", 1);
    ft_putnbr_fd(L_a == NULL, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("L_b == NULL: ", 1);
    ft_putnbr_fd(L_b == NULL, 1);
    ft_putstr_fd("\n", 1);
	return (0);
}

static void ft_select_function(List *L_a, List *L_b)
{
//    printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    while ((L_a->ret == 0) && ft_list_is_empty(L_b))
    {
//        printf("Dentro do loop\n");
        if (ft_list_size(L_a) == 2)
            ft_sort_two(L_a);
        else if (ft_list_size(L_a) == 3)
            ft_sort_three_a(L_a);
        else if (ft_list_size(L_a) == 5)
            ft_sort_five(L_a, L_b);
        else if (ft_list_size(L_a) <= 100)
            ft_sort_more_than_five(L_a, L_b);
        else
        {
            printf("ordena Padrão\n");
            break ;
        }
        L_a = ft_valid_input_order_asc(L_a);
//        printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    }
}

void    ft_sort_five(List *L_a, List *L_b)
{
    ft_putstr_fd("ft_sort_five\n", 1);
	Node	*p1;
	Node	*p2;
	Node	*p3;

	p1 = L_a->begin;
	p2 = p1->next;
	p3 = L_a->end;
//    printf("tamanho de b: %zu | L_a->ret: %i\n", ft_list_size(L_b), L_a->ret);
	while ((ft_list_size(L_b) != 0) || (L_a->ret == 0))
	{
//        ft_putstr_fd("Inicia o loop\n", 1);
//        ft_putstr_fd("verifique qual o menor valor dos 3 e gira a stack se necessário.\n", 1);
		if (p2->val < p1->val && p2->val < p3->val )
		{
//            printf("o menor é o p2\n");
			ft_swap_stack(L_a, "sa");
		}
		else if ((p3->val < p1->val) && (p3->val < p2->val))
		{
//            printf("o menor é o p3\n");
			ft_reverse_rotato_stack(L_a, "rra");
		}
//        else
//            printf("o menor é o p1 | nada a fazer retirar esse else!!!\n");

//       ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
//        printf("L_a->ret: %i\n", L_a->ret);
        if (L_a->ret == 0)
        {
//            printf("L_a está desordenado\n");
            ft_push_stack(L_a, L_b, "pa");
        }
//    	ft_putstr_fd("Print L_a\n", 1);
//		ft_list_print(L_a);
//    	ft_putstr_fd("Print L_b\n", 1);
//		ft_list_print(L_b);

//        ft_putstr_fd("Verifique se L_a possui tamanho 3 e se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
//        printf("tamanho de a: %zu | L_a->ret: %i\n", ft_list_size(L_a), L_a->ret);
        if ((ft_list_size(L_a) == 3) && (L_a->ret == 0))
        {
//        	ft_putstr_fd("Print L_a\n", 1);
//    		ft_list_print(L_a);
//        	ft_putstr_fd("Print L_b\n", 1);
//    		ft_list_print(L_b);
//    		ft_putstr_fd("chama a função para ordenar 3 itens de L_a\n", 1);
            ft_sort_three_a(L_a);
        }
//        ft_putstr_fd("Verifique se L_b possui tamanho 2 e se L_b está ordenado desc (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_b = ft_valid_input_order_desc(L_b);
//        printf("tamanho de b: %zu | L_b->ret: %i\n", ft_list_size(L_b), L_b->ret);
        if ((ft_list_size(L_b) == 2) && (L_b->ret == 0))
        {
//    		ft_putstr_fd("chama a função para ordenar 2 itens de L_b\n", 1);
            ft_swap_stack(L_b, "sb");
//            ft_sort_two(L_b); //necessário alterar a função de swap para já passar quem está chamando
//          ft_putstr_fd("Print L_a\n", 1);
//		    ft_list_print(L_a);
//        	ft_putstr_fd("Print L_b\n", 1);
//	    	ft_list_print(L_b);
        }

//        ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0) && (L_b possui tamanho |= 0 e se L_b está ordenado desc (ret < 0) ou desordenado (ret == 0))\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
        L_b = ft_valid_input_order_desc(L_b);
//        printf("tamanho de b: %zu | L_b->ret: %i | L_a->ret: %i\n", ft_list_size(L_b), L_b->ret,L_a->ret);
        if ((L_a->ret != 0) && ((L_b->ret != 0) && (ft_list_size(L_b) != 0)))
            ft_push_stack(L_b, L_a, "pb");
//        printf("Atualiza os ponteiros\n");
        p1 = L_a->begin;
        p2 = p1->next;
        p3 = L_a->end;
//        printf("Atualiza o L_a ret para reiniciar o loop\n");
        L_a = ft_valid_input_order_asc(L_a);
//      printf("tamanho de b: %zu | L_a->ret: %i\n", ft_list_size(L_b), L_a->ret);
//      ft_putstr_fd("Print L_a\n", 1);
//      ft_list_print(L_a);
//      ft_putstr_fd("Print L_b\n", 1);
//      ft_list_print(L_b);
	}
//	ft_putstr_fd("========+++++encerra_o_sort_five+++++========\n", 1);
}

void    ft_sort_more_than_five(List *L_a, List *L_b)
{
    ft_putstr_fd("ft_sort_more_than_five\n", 1);
	Node	*p1;
	Node	*p2;
	Node	*p3;

	p1 = L_a->begin;
	p2 = p1->next;
	p3 = L_a->end;
//    printf("tamanho de b: %zu | L_a->ret: %i\n", ft_list_size(L_b), L_a->ret);
	while ((ft_list_size(L_b) != 0) || (L_a->ret == 0))
	{
//        ft_putstr_fd("Inicia o loop\n", 1);
//        ft_putstr_fd("verifique qual o menor valor dos 3 e gira a stack se necessário.\n", 1);
		if (p2->val < p1->val && p2->val < p3->val )
		{
//            printf("o menor é o p2\n");
			ft_swap_stack(L_a, "sa");
		}
		else if ((p3->val < p1->val) && (p3->val < p2->val))
		{
//            printf("o menor é o p3\n");
			ft_reverse_rotato_stack(L_a, "rra");
		}
//        else
//            printf("o menor é o p1 | nada a fazer retirar esse else!!!\n");

//        ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
//        printf("L_a->ret: %i\n", L_a->ret);
        if (L_a->ret == 0)
        {
//            printf("L_a está desordenado\n");
            ft_push_stack(L_a, L_b, "pa");
        }
//    	ft_putstr_fd("Print L_a\n", 1);
//		ft_list_print(L_a);
//    	ft_putstr_fd("Print L_b\n", 1);
//		ft_list_print(L_b);

//        ft_putstr_fd("Verifique se L_a possui tamanho 3 e se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
//        printf("tamanho de a: %zu | L_a->ret: %i\n", ft_list_size(L_a), L_a->ret);
        if ((ft_list_size(L_a) == 3) && (L_a->ret == 0))
        {
//        	ft_putstr_fd("Print L_a\n", 1);
//    		ft_list_print(L_a);
//        	ft_putstr_fd("Print L_b\n", 1);
//    		ft_list_print(L_b);
//    		ft_putstr_fd("chama a função para ordenar 3 itens de L_a\n", 1);
            ft_sort_three_a(L_a);
        }
//        ft_putstr_fd("Verifique se L_b possui tamanho > 1 e se L_b está ordenado desc (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_b = ft_valid_input_order_desc(L_b);
//        printf("tamanho de b: %zu | L_b->ret: %i\n", ft_list_size(L_b), L_b->ret);
        if ((ft_list_size(L_b) > 1) && (L_b->ret == 0))
        {
//    		ft_putstr_fd("chama a função para ordenar L_b\n", 1);
            if (ft_list_size(L_b) == 2)
                ft_swap_stack(L_b, "sb");
            else
                ft_sort_three_b(L_b);
//            ft_putstr_fd("Print L_a\n", 1);
//		    ft_list_print(L_a);
//        	ft_putstr_fd("Print L_b\n", 1);
//	    	ft_list_print(L_b);
        }

//        ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0) && (L_b possui tamanho |= 0 e se L_b está ordenado desc (ret < 0) ou desordenado (ret == 0))\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
        L_b = ft_valid_input_order_desc(L_b);
//        printf("tamanho de b: %zu | L_b->ret: %i | L_a->ret: %i\n", ft_list_size(L_b), L_b->ret,L_a->ret);
        if ((L_a->ret != 0) && ((ft_list_size(L_b) != 0) && 
        ((L_b->ret != 0) || (L_b->blind == -1))))
        {
            ft_push_stack(L_b, L_a, "pb");
            L_b->blind = 0;
        }
//        printf("Atualiza os ponteiros\n");
        while ((ft_list_size(L_a) < 3) && (ft_list_size(L_b) != 0))
        {
//            printf("Verificar se está entrando neste loop de empurando de L_b para L_a\n");
            ft_push_stack(L_b, L_a, "pb");
        }
        p1 = L_a->begin;
        p2 = p1->next;
        p3 = L_a->end;
//        printf("Atualiza o L_a ret para reiniciar o loop\n");
        L_a = ft_valid_input_order_asc(L_a);
//        printf("tamanho de b: %zu | L_a->ret: %i\n", ft_list_size(L_b), L_a->ret);
//    	ft_putstr_fd("Print L_a\n", 1);
//        ft_list_print(L_a);
//    	ft_putstr_fd("Print L_b\n", 1);
//		ft_list_print(L_b);
	}
//	ft_putstr_fd("========+++++encerra_o_sort_more_than_five+++++========\n", 1);
}

void    ft_sort_two(List *L_a)
{
    ft_swap_stack(L_a, "sa");
}

void    ft_sort_three_a(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
	while (L_a->ret == 0)
	{
        if ((p1->val > p2->val) && (p1->val > p3->val))
            ft_rotato_stack(L_a, "ra");
        else if (((p1->val > p2->val) && (p1->val < p3->val)) || ((p1->val < p2->val) && (p1->val > p3->val)))
            ft_sort_three_a_aux(L_a);
        else
            ft_reverse_rotato_stack(L_a, "rra");
        p1 = L_a->begin;
        p2 = p1->next;
        p3 = L_a->end;
        L_a = ft_valid_input_order_asc(L_a);
	}
}

void    ft_sort_three_a_aux(List *L_a)
{
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_a->begin;
    p2 = p1->next;
    p3 = L_a->end;
    if ((p2->val < p1->val) && (p2->val < p3->val))
        ft_swap_stack(L_a, "sa");
    else
        ft_reverse_rotato_stack(L_a, "rra");
}

void    ft_sort_three_b(List *L_b)
{
    printf("Dentro da sort threen_b\n");
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_b->begin;
    p2 = p1->next;
    p3 = L_b->end;
    printf("Antes do loop da sort threen_b\n");
    printf("L_b->ret: %i | L_b->blind: %i\n", L_b->ret, L_b->blind);
	while (L_b->ret == 0 && L_b->blind == 0)
	{
        printf("Dentro do loop da sort threen_b\n");
        printf("L_b->ret: %i | L_b->blind: %i\n", L_b->ret, L_b->blind);
        usleep(2000);
        if ((ft_list_size(L_b) > 3) && ((p1->val > p2->val) && (p2->val > p3->val)))
        {
            printf("dentro do if para cego\n");
            usleep(200);
            L_b->blind = -1;
            break ;
        }
        else
        {
            printf("dentro do else para cego\n");
            usleep(200);
            L_b->blind == 0;
            printf("deixou de ser cego\n");
        }
        if ((p1->val < p2->val) && (p1->val < p3->val))
        {
            printf("p1 é o menor\n");
            ft_rotato_stack(L_b, "rb");
        }
        else if (((p1->val > p2->val) && (p1->val < p3->val)) ||
                 ((p1->val < p2->val) && (p1->val > p3->val)))
        {
            printf("chama a função auxiliar de sort three\n");
            ft_sort_three_b_aux(L_b);
        }
        else if ((p1->val > p2->val) && (p1->val > p3->val))
        {
            printf("p1 é o maior\n");
      	    ft_putstr_fd("Print L_b antes de movimentar\n", 1);
   	    	ft_list_print(L_b);
            ft_reverse_rotato_stack(L_b, "rrb");
      	    ft_putstr_fd("Print L_b após movimentar\n", 1);
   	    	ft_list_print(L_b);
            usleep(200);
        }
        else
        {
            printf("nenhuma das anteriores break\n");
            break ;
        }
        usleep(200);
        p1 = L_b->begin;
        p2 = p1->next;
        p3 = L_b->end;
        L_b = ft_valid_input_order_desc(L_b);
	}
}

void    ft_sort_three_b_aux(List *L_b)
{
    printf("Dentro da sort threen_b_aux\n");
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_b->begin;
    p2 = p1->next;
    p3 = L_b->end;
    if ((p2->val > p1->val) && (p2->val > p3->val))
    {
        printf("2 | 3 | 1\n");
        ft_swap_stack(L_b, "sb");
    }
    else if ((p2->val < p1->val) && (p2->val < p3->val))
    {
        printf("2 | 1 | 3\n");
  	    ft_putstr_fd("Print L_b antes de movimentar\n", 1);
   		ft_list_print(L_b);
        ft_reverse_rotato_stack(L_b, "rrb");
  	    ft_putstr_fd("Print L_b após movimentar\n", 1);
   		ft_list_print(L_b);
        usleep(200);
    }
}
