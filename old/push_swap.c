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

static  void ft_select_function(List *L_a, List *L_b, int *sort);
void    ft_sort_two(List *L_a);
void    ft_sort_three_a(List *L_a);
void    ft_sort_three_a_aux(List *L_a);
void    ft_sort_three_b(List *L_b);
void    ft_sort_five(List *L_a, List *L_b);
void    ft_sort_more_than_five(List *L_a, List *L_b);
void    ft_sort_others(List *L_a, List *L_b, int *sort);
int     *ft_order_arr(int *sort, size_t len);
void    ft_sort_more_than_three(List *L_a, List *L_b, int *sort, int first);

int ft_push_swap(int argc, char **argv)
{
    List        *L_a;
    List        *L_b;
    int         *sort;

    L_a = ft_list_create();
    L_b = ft_list_create();
    if (!L_b || !L_a)
    {
        ft_list_destroy(&L_a);
        ft_list_destroy(&L_b);
        return (-1);
    }
    L_a = ft_valid_input(argc, argv, L_a);
    sort = NULL;
    ft_list_to_array(L_a, &sort);
/*
        int i = 0;
        printf("Chegou até aqui | pós list to array \n");
        while (i < ft_list_size(L_a))
        {
                printf("Entrou no loop | pós list to array\n");
                printf("valor de sort[%d]: %d\n", i, sort[i]);
                i++;
        }
*/
    ft_order_arr(sort, ft_list_size(L_a));
    L_a = ft_put_index(L_a, sort);
/*
        Node *p;
        p = L_a->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
	int i = 0;
	while (i < ft_list_size(L_a))
	{
		printf("entrou no loop | após order array. sort[%d]: %d\n", i, sort[i]);
		i++;
	}
        ft_putstr_fd("stack l_a: \n", 1);
	ft_list_print(L_a);
        ft_putstr_fd("stack l_b: \n", 1);
	ft_list_print(L_b);
        
        ft_reverse_rotato_stack(L_a, "rra");
        p = L_a->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
        ft_swap_stack(L_a, "sa");
        p = L_a->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
        ft_rotato_stack(L_a, "ra");
        p = L_a->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
        ft_push_stack(L_a, L_b, "pb");
        p = L_a->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
        p = L_b->begin;
        while (p != NULL)
        {
	        printf("entrou no loop | após put_index| val: %d | index: %d\n", p->val, p->index);
                p = p->next;
        }
*/
    if (L_a->ret == 0)
    {
 /*
        ft_putstr_fd("Valor de ret de l_a: ", 1);
        ft_putnbr_fd(L_a->ret, 1);
        ft_putstr_fd("\n", 1);
        ft_putstr_fd("+++imprimindo l_a+++\n", 1);
    	ft_list_print(L_a);
        ft_list_inverted_print(L_a);
        ft_putstr_fd("+++imprimindo l_b+++\n", 1);
    	ft_list_print(L_b);
        ft_list_inverted_print(L_b);
	int i = 0;
	while (i < ft_list_size(L_a))
	{
		printf("entrou no loop | após order array. sort[%d]: %d\n", i, sort[i]);
		i++;
	}
*/
        ft_select_function(L_a, L_b, sort);
    }
    ft_putstr_fd("Resultado da ordenação\n", 1);
    ft_putstr_fd("Valor de ret de l_a: ", 1);
    ft_putnbr_fd(L_a->ret, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("stack l_a: \n", 1);
	ft_list_print(L_a);
    ft_putstr_fd("stack l_b: \n", 1);
	ft_list_print(L_b);
/*
    i = 0;
    while (i < ft_list_size(L_a))
    {
        printf("entrou no loop | após order array. sort[%d]: %d\n", i, sort[i]);
        i++;
    }
*/
    printf("Chama a list_destroy para L_a\n");
    ft_list_destroy(&L_a);
    printf("Chama a list_destroy para L_b\n");
    ft_list_destroy(&L_b);
    printf("Chama a free_sort para sort\n");
    ft_free_sort(&sort);
/*
    ft_putstr_fd("L_a == NULL: ", 1);
    ft_putnbr_fd(L_a == NULL, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("L_b == NULL: ", 1);
    ft_putnbr_fd(L_b == NULL, 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("sort == NULL: ", 1);
    ft_putnbr_fd(sort == NULL, 1);
    ft_putstr_fd("\n", 1);
*/

	return (0);
}

static void ft_select_function(List *L_a, List *L_b, int *sort)
{
//    printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    while ((L_a->ret == 0) && ft_list_is_empty(L_b))
    {
//        printf("Dentro do loop\n");
        if (ft_list_size(L_a) == 2)
            ft_sort_two(L_a);
        else if (ft_list_size(L_a) == 3)
            ft_sort_three_a(L_a);
        else if (ft_list_size(L_a) <= 5)
            ft_sort_five(L_a, L_b);
/*
        else if (ft_list_size(L_a) <= 100)
            ft_sort_more_than_five(L_a, L_b);
        else if (ft_list_size(L_a) <= 600)
            ft_sort_more_than_five(L_a, L_b);
        else
        {
//            printf("ordena Padrão\n");
            break ;
        }
*/
        else
        {
                printf("Chama a função que ordena mais de 5\n");
//                ft_sort_more_than_three(L_a, L_b, sort, 1);
                ft_sort_others(L_a, L_b, sort);
        }
        L_a = ft_valid_input_order_asc(L_a);
//        printf("Dentro de select function L_a->ret: %d is_empty(L_b): %d\n", L_a->ret, ft_list_is_empty(L_b));
    }
}

void    ft_sort_two(List *L_a)
{
//        printf("Dentro da função que ordena 2\n");
    ft_swap_stack(L_a, "sa");
}

void    ft_sort_three_a(List *L_a)
{
//        printf("Dentro da função que ordena 3\n");

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
//    printf("Dentro da sort threen_b\n");
    Node    *p1;
    Node    *p2;
    Node    *p3;

    p1 = L_b->begin;
    p2 = p1->next;
    p3 = L_b->end;
//    printf("Antes do loop da sort threen_b\n");
//    printf("L_b->ret: %i | L_b->blind: %i\n", L_b->ret, L_b->blind);
//	while (L_b->ret == 0 && L_b->blind == 0)
	while (L_b->blind == 0)
	{
//        printf("Dentro do loop da sort threen_b\n");
//        printf("L_b->ret: %i | L_b->blind: %i\n", L_b->ret, L_b->blind);
//        usleep(2000);
        if ((ft_list_size(L_b) > 3) && ((p1->val > p2->val) && (p2->val > p3->val)))
        {
//            printf("dentro do if para cego\n");
//            usleep(200);
            L_b->blind = -1;
            break ;
        }
//        else
//        {
//            printf("dentro do else para cego\n");
//            usleep(200);
//            L_b->blind == 0;
//            printf("deixou de ser cego\n");
//        }
        if (((p1->val < p2->val) && (p1->val < p3->val)) && ((p2->val > p1->val) && (p2->val < p3->val)))
        {
//            printf("1 | 2 | 3\n");
            ft_rotato_stack(L_b, "rb");
            ft_swap_stack(L_b, "sb");
            break ;
        }
        else if (((p1->val < p2->val) && (p1->val < p3->val)) && ((p2->val > p1->val) && (p2->val > p3->val)))
        {
//            printf("1 | 3 | 2\n");
            ft_rotato_stack(L_b, "rb");
            break ;
        }
        else if (((p1->val > p2->val) && (p1->val < p3->val)) && ((p2->val < p1->val) && (p2->val < p3->val)))
        {
//            printf("2 | 1 | 3\n");
//  	        ft_putstr_fd("Print L_b antes de movimentar\n", 1);
//   		    ft_list_print(L_b);
            ft_reverse_rotato_stack(L_b, "rrb");
//  	        ft_putstr_fd("Print L_b após movimentar\n", 1);
//   		    ft_list_print(L_b);
//            usleep(200);
            break ;
        }
        else if (((p1->val < p2->val) && (p1->val > p3->val)) && ((p2->val > p1->val) && (p2->val > p3->val)))
        {
//            printf("2 | 3 | 1\n");
            ft_swap_stack(L_b, "sb");
            break ;
        }
        else if ((p1->val > p2->val) && (p1->val > p3->val))
        {
//            printf("3 | 1 | 2\n");
//      	    ft_putstr_fd("Print L_b antes de movimentar\n", 1);
//   	    	ft_list_print(L_b);
            ft_reverse_rotato_stack(L_b, "rrb");
            ft_swap_stack(L_b, "sb");
//      	    ft_putstr_fd("Print L_b após movimentar\n", 1);
//   	    	ft_list_print(L_b);
//            usleep(200);
            break ;
        }
//        usleep(200);
        p1 = L_b->begin;
        p2 = p1->next;
        p3 = L_b->end;
//        L_b = ft_valid_input_order_desc(L_b);
        }
}

void    ft_sort_five(List *L_a, List *L_b)
{
//    ft_putstr_fd("ft_sort_five\n", 1);
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
		if (p2->val < p1->val && p2->val < p3->val)
		{
//         	  printf("o menor é o p2\n");
			ft_swap_stack(L_a, "sa");
		}
		else if ((p3->val < p1->val) && (p3->val < p2->val))
		{
//         	  printf("o menor é o p3\n");
			ft_reverse_rotato_stack(L_a, "rra");
		}
//      	else
//         	  printf("o menor é o p1 | nada a fazer retirar esse else!!!\n");
//       ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);

		L_a = ft_valid_input_order_asc(L_a);
//        printf("L_a->ret: %i\n", L_a->ret);
        if (L_a->ret == 0)
        {
//            printf("L_a está desordenado\n");
            ft_push_stack(L_a, L_b, "pb");
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
            ft_push_stack(L_b, L_a, "pa");
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

void    ft_last_move(List *L_a, List *L_b, int digit_move, int *sort) 
{
        printf("dentro da last move | digit_move: %d\n", digit_move);
        int     cnt[2];
        int result;
        Node    *p;

        cnt[0] = 0;
        cnt[1] = L_a->size;
        p = L_a->begin;
        while (cnt[0]++ < cnt[1])
        {
              printf("dentro da last move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                result = ((p->index >> digit_move) % 2 == 0);
                printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                if (result)
                {
                        ft_push_stack(L_a, L_b, "pb");
                }
                else
                {
                        ft_rotato_stack(L_a, "ra");                
                }
                ft_putstr_fd("stack l_a: \n", 1);
                ft_list_print(L_a);
                ft_putstr_fd("stack l_b: \n", 1);
                ft_list_print(L_b);
/*
*/
                p = L_a->begin;
        }
        while (L_b->size > 0)
        {
                printf("dentro da last aux | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                ft_push_stack(L_b, L_a, "pa");
        }
/*
*/
        ft_putstr_fd("stack l_a: \n", 1);
	ft_list_print(L_a);
        ft_putstr_fd("stack l_b: \n", 1);
	ft_list_print(L_b);
/*
        printf("Recoloca os indices de L_a\n");
        L_a = ft_put_index(L_a, sort);
        printf("Recoloca os indices de L_b\n");
        L_b = ft_put_index(L_b, sort);
*/
        printf("dentro da last move | fora do loop | encerra a last move\n");
}

void    ft_move(List *L_a, List *L_b, int digit_move, int *sort)
{
        printf("dentro da move | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
        int cnt[2];
        int result;
        int result2;
        int itmp;
        Node    *p;

        cnt[0] = 0;
        p = L_a->begin;
        if (L_a->size > 0)
        {
                cnt[1] = L_a->size;
                while (cnt[0]++ < cnt[1])
                {
                        printf("dentro da move | dentro do 1º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_a->size);
                        itmp = p->index;
                        result = ((itmp >> digit_move) % 2 == 0);
                        result2 = ((itmp >> digit_move) % 2);
                        result = (((p->index >> digit_move) & 00000001) == 0);
                        result2 = ((p->index >> digit_move) & 00000001);
                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d | result2: %d\n", p->index, p->val, digit_move, result, result2);
                        if (result)
                        {
                                ft_push_stack(L_a, L_b, "pb");
                        }
                        else
                        {
                                ft_rotato_stack(L_a, "ra");
                        }
/*
*/
                        ft_putstr_fd("stack l_a: \n", 1);
                        ft_list_print(L_a);
                        ft_putstr_fd("stack l_b: \n", 1);
                        ft_list_print(L_b);
                        p = L_a->begin;
                }
                while (L_b->size > 0)
                {
                        printf("dentro da move | dentro do 2º loop | digit_move: %d | L_a->size: %zu\n", digit_move, L_b->size);
                        ft_push_stack(L_b, L_a, "pa");
                }
/*
*/
                ft_putstr_fd("stack l_a: \n", 1);
                ft_list_print(L_a);
                ft_putstr_fd("stack l_b: \n", 1);
                ft_list_print(L_b);
        }
        else
        {
                cnt[1] = L_b->size;
                p = L_b->begin;
                while (cnt[0]++ < cnt[1])
                {
                        printf("dentro da move_aux | digit_move: %d | L_b->size: %zu\n", digit_move, L_b->size);
                        result = ((p->index >> digit_move) % 2);
                        result = ((p->index >> digit_move) & 1);
                        printf("Valor de index: %d | val: %d | digit_move: %d | result: %d\n", p->index, p->val, digit_move, result);
                        if (result)
                        {
                                ft_push_stack(L_b, L_a, "pa");
                        }
                        else
                        {
                                ft_rotato_stack(L_b, "rb");
                        }
                        p = L_b->begin;
/*
*/
                        ft_putstr_fd("stack l_a: \n", 1);
                        ft_list_print(L_a);
                        ft_putstr_fd("stack l_b: \n", 1);
                        ft_list_print(L_b);
                }
                while (L_b->size > 0)
                        ft_push_stack(L_b, L_a, "pa");
/*
*/
                ft_putstr_fd("stack l_a: \n", 1);
                ft_list_print(L_a);
                ft_putstr_fd("stack l_b: \n", 1);
                ft_list_print(L_b);
        }
/*
        printf("Recoloca os indices de L_a\n");
        L_a = ft_put_index(L_a, sort);
        printf("Recoloca os indices de L_b\n");
        L_b = ft_put_index(L_b, sort);
*/
        printf("dentro da move | encerra a move\n");
}

void    ft_sort_others(List *L_a, List *L_b, int *sort)
{
        int move;
        int now_move;

        move = 0;
        while ((1 << move) < L_a->size)
                ++move;
        sleep(1);
        now_move = 0;
        while (now_move++ < move)
        {
                if ((now_move == move) && (now_move % 2))
                {
//                        printf("dentro do loop | move: %d e now_move: %d | chama a last_move\n", move, now_move - 1);
                        ft_last_move(L_a, L_b, (now_move - 1), sort);
                }
                else
                {
//                        printf("dentro do loop | move: %d e now_move: %d | chama a move\n", move, now_move - 1);
                        ft_move(L_a, L_b, (now_move - 1), sort);
                }
        }
//        printf("Encerramento do loop | move: %d e now_move: %d\n", move, now_move - 1);
}

void    ft_sort_more_than_five(List *L_a, List *L_b)
{
//    ft_putstr_fd("ft_sort_more_than_five\n", 1);
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
//		while (!(p3->val > p2->val) || !(p3->val > p1->val) || !(p2->val > p1->val))
//		{
			if (p2->val < p1->val && p2->val < p3->val)
			{
//          	  printf("o menor é o p2\n");
				ft_swap_stack(L_a, "sa");
			}
			else if ((p3->val < p1->val) && (p3->val < p2->val))
			{
//          	  printf("o menor é o p3\n");
				ft_reverse_rotato_stack(L_a, "rra");
			}
//        	else
//          	  printf("o menor é o p1 | nada a fazer retirar esse else!!!\n");
//			p1 = L_a->begin;
//			p2 = p1->next;
//			p3 = L_a->end;
//		}
//        ft_putstr_fd("Verifique se L_a está ordenado (ret < 0) ou desordenado (ret == 0)\n", 1);
        L_a = ft_valid_input_order_asc(L_a);
//        printf("L_a->ret: %i\n", L_a->ret);
        if (L_a->ret == 0)
        {
//            printf("L_a está desordenado\n");
            ft_push_stack(L_a, L_b, "pb");
            L_b->blind = 0; //
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
            else if ((L_b->blind) == 0)
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
        if ((L_a->ret != 0) && ((ft_list_size(L_b) != 0) && ((L_b->ret != 0) || (L_b->blind == -1))))
        {
            ft_push_stack(L_b, L_a, "pa");
            L_b->blind = 0;
        }
//        printf("Atualiza os ponteiros\n");
        while ((ft_list_size(L_a) < 3) && (ft_list_size(L_b) != 0))
        {
//            printf("Verificar se está entrando neste loop de empurando de L_b para L_a\n");
            ft_push_stack(L_b, L_a, "pa");
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

int     ft_can_swap_a(List *L_a)
{
//        printf("Dentro da can swap a\n");
        Node    *p1;
        Node    *p2;

        if (L_a->size < 2)
        {
//                printf("Dentro da can swap a: size < 2 (0).\n");
                return (0);
        }
        p1 = L_a->begin;
        p2 = p1->next;
        if (p1->group != p2->group)
        {        
//                printf("Dentro da can swap a: grupos diferentes (0).\n");
                return (0);
        }
        if (p1->val > p2->val)
        {
//                printf("Dentro da can swap a: p1->val > p2->val (1).\n");
                return (1);
        }
//        printf("Dentro da can swap a: nenhuma das anteriores (0).\n");
        return (0);
}

int     ft_can_swap_b(List *L_b)
{
//        printf("Dentro da can swap b\n");
        Node    *p1;
        Node    *p2;

        if (L_b->size < 2)
        {
//                printf("Dentro da can swap b: size < 2 (0).\n");
                return (0);
        }
        p1 = L_b->begin;
        p2 = p1->next;
        if (p1->group != p2->group)
        {        
//                printf("Dentro da can swap b: grupos diferentes (0).\n");
                return (0);
        }
        if (p1->val < p2->val)
        {
//                printf("Dentro da can swap b: p1->val < p2->val (1).\n");
                return (1);
        }
//        printf("Dentro da can swap b: nenhuma das anteriores (0).\n");
        return (0);
}

void    ft_can_swap(List *L_a, List *L_b)
{
//        printf("Dentro da can swap\n");
        int sa;
        int sb;

//        printf("Chama a can swap a\n");
        sa = ft_can_swap_a(L_a);
//        printf("Chama a can swap b\n");
        sb = ft_can_swap_b(L_b);
        if (sa && sb)
        {
//                printf("pode swap a e pode swap b: swap de ambos\n");
                ft_swap_stack_both(L_a, L_b); //ajustar a impressão
        }
        if (!sa && sb)
        {
//                printf("não pode swap a e pode swap b: swap apenas de b\n");
                ft_swap_stack(L_b, "sb");
        }
}

static t_pivot ft_define_pivot(int *sort, int size, int first)
{
//        printf("Dentro da função que define o pivot => size: %d, first: %d\n", size, first);
/*
	int i = 0;
	while (i < size)
	{
		printf("entrou no loop | sort[%d]: %d\n", i, sort[i]);
		i++;
	}
*/
        t_pivot pivot;

        if (size < 10)
                pivot.index = size / 2;
        else if (size < 50)
                pivot.index = size / 3;
        else if (size < 90)
                pivot.index = size / 5;
        else if (size < 110)
                pivot.index = size / 7;
        else if (size < 140)
                pivot.index = size / 9;
        else
                pivot.index = size / 11;
        if (pivot.index > size - 3)
                pivot.index = (size - 3);
        pivot.value = sort[pivot.index];
        pivot.qtd = pivot.index;
        pivot.first = first;

//        printf("Saindo da função que define o pivot => index: %d | value: %d | qtd: %d | group_pivot: %d | fist: %d\n", pivot.index, pivot.value, pivot.qtd, pivot.group_pivot, pivot.first);
        return (pivot); 
}

void    ft_split_stack_until_pivot(List *L_a, List *L_b, t_pivot pivot)
{
        int qtd;
//        printf("Dentro da função que divide a stacka até o pivot\n");

        qtd = pivot.qtd;
        while (qtd > 0)
        {
//                printf("Chama a funçao can swap\n");
                ft_can_swap(L_a, L_b);
                if (L_a->begin->val < pivot.value)
                {
                        L_a->begin->group = pivot.index;
                        ft_push_stack(L_a, L_b, "pb");
                        qtd--;
                }
                else
                        ft_rotato_stack(L_a, "ra");
        }
/*
        ft_putstr_fd("Após dividir a stack até o pivot\n", 1);
        ft_putstr_fd("+++imprimindo l_a+++\n", 1);
    	ft_list_print(L_a);
        ft_list_inverted_print(L_a);
        ft_putstr_fd("+++imprimindo l_b+++\n", 1);
    	ft_list_print(L_b);
        ft_list_inverted_print(L_b);
*/
}

int ft_find_sort_way(List *L_b, t_pivot pivot, int value)
{
//        printf("Dentro da função find sort way\n");
        Node *node;
        int     count;
        int     max;

        node = L_b->begin;
        count = 0;
        max = pivot.qtd;
        if (pivot.first)
                max = pivot.qtd / 2;
        while (count < max)
        {
                if (node->val == value);
                        return (0);
                count++;
                node = node->next;
        }
        return (1);
}
/*
int ft_change_direction(Node *begin_b, size_t group, int reverse)
{
        if ((reverse == 0) && (begin_b->group != group))
                return (1);
        else if ((reverse == 1) && (begin_b->group != group))
                return (0);
        return (reverse);
}
*/
void    ft_return_stack(List *L_a, List *L_b, t_pivot pivot, int *sort)
{
//        printf("Dentro da função que retorna a stack\n");
        int reverse;
/*
        ft_putstr_fd("+++imprimindo l_a+++\n", 1);
    	ft_list_print(L_a);
        ft_list_inverted_print(L_a);
        ft_putstr_fd("+++imprimindo l_b+++\n", 1);
    	ft_list_print(L_b);
        ft_list_inverted_print(L_b);
        printf("Valores do pivot => index: %d | value: %d | qtd: %d | group_pivot: %d | fist: %d\n", pivot.index, pivot.value, pivot.qtd, pivot.group_pivot, pivot.first);
*/
/*
	int i = 0;
	while (i < ft_list_size(L_a))
	{
		printf("entrou no loop | após order array. sort[%d]: %d\n", i, sort[i]);
		i++;
	}
*/      
        if (L_b->size == 0)
                return ;
        reverse = 0;
        pivot.index--;
        pivot.group_pivot = L_b->begin->group;
//        printf("Valores do pivot => index: %d | value: %d | qtd: %d | group_pivot: %d | fist: %d\n", pivot.index, pivot.value, pivot.qtd, pivot.group_pivot, pivot.first);
        while (L_b->size > 0 && pivot.index >= 0)
        {
//                printf("L_b-size: %zu | pivot.index: %d\n", L_b->size, pivot.index);
//                printf("Chama a função find_sort_way com: valor de sort: %d\n", sort[pivot.index]);
//                ft_putstr_fd("+++imprimindo l_b+++\n", 1);
//            	ft_list_print(L_b);
                reverse = ft_find_sort_way(L_b, pivot, sort[pivot.index]);
                if (L_b->begin->val == sort[pivot.index])
                {
                        ft_push_stack(L_b, L_a, "pa");
                        pivot.index--;
                        pivot.qtd--;
                }
                else
                {
                        if (reverse)
                                ft_reverse_rotato_stack(L_b, "rra");
                        else
                                ft_rotato_stack(L_b, "rb");
                }
//                printf("Valores do pivot => index: %d | value: %d | qtd: %d | group_pivot: %d | fist: %d\n", pivot.index, pivot.value, pivot.qtd, pivot.group_pivot, pivot.first);
//                printf("Chama a função change direction\n");
        
//  !!!!!!!!!              reverse = ft_change_direction(L_b->begin, pivot.group_pivot, reverse);
//                printf("Retorno da função change direction\n");
        }
//        printf("Encerrando a função que retorna a stack\n");
}

void    ft_sort_more_than_three(List *L_a, List *L_b, int *sort, int first)
{
//        printf("Dentro da função que ordena mais de 4\n");
        t_pivot pivot;

        pivot.index = 0;
        if (ft_list_size(L_a) > 3)
        {
//                printf("Chama a função que define o pivot\n");
                pivot = ft_define_pivot(sort, L_a->size, first);
//                printf("Chama a função que divide a stack até o pivot\n");
                ft_split_stack_until_pivot(L_a, L_b, pivot);
//                printf("Chama a função que ordena mais de 3 novamente\n");
                ft_sort_more_than_three(L_a, L_b, sort + pivot.index, 0);
        }
//        printf("Chama a função que ordena 3\n");
        ft_sort_three_a(L_a);
//        printf("Chama a função que retorna a stack\n");
        ft_return_stack(L_a, L_b, pivot, sort);
}

