/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woliveir                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:59 by woliveir          #+#    #+#             */
/*   Updated: 2022/07/09 12:52:55 by woliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

# include <stdio.h> //printf

# define FALSE		0
# define TRUE		1

typedef struct doubly_node
{
    int                     val;
    int                     index;
	int                     group;
	struct doubly_node      *prev;
    struct doubly_node      *next;
} Node;

typedef struct doubly_linked_list
{
    Node        *begin;
    Node        *end;
    size_t      size;
    int         ret;
} List;

typedef struct s_pivot
{
    int index;
    int value;
    int qtd;
    int group;
    int first;
}   t_pivot;

int     ft_push_swap(int argc, char **argv);

/*+++===ft_sort_algorithm_easy===+++*/
void    ft_sort_two(List *L_a);
void    ft_sort_three_a(List *L_a);
void    ft_sort_five(List *L_a, List *L_b);

/*+++===ft_sort_algorithm_mediun===+++*/
void    ft_sort_one_hundred(List *L_a, List *L_b, int *sort, int first);
void    ft_can_swap(List *L_a, List *L_b);

/*+++===ft_sort_algorithm_hard===+++*/
void    ft_sort_five_hundred(List *L_a, List *L_b);


/*+++===ft_actions===+++*/
void	ft_swap_stack(List *L, char *str);
void	ft_swap_stack_both(List *L_a, List *L_b, char *str);
void	ft_rotato_stack(List *L, char *str);
void	ft_rotato_stack_both(List *L_a, List *L_b, char *str);
void	ft_reverse_rotato_stack(List *L, char *str);
void	ft_reverse_rotato_stack_both(List *L_a, List *L_b, char *str);
void	ft_push_stack(List *L_source, List *L_dest, char *str);

/*+++===ft_structs_1===+++*/
Node    *ft_node_create(int val);
List    *ft_list_create(void);
void    ft_list_destroy(List **L_ref);
void    ft_list_print(const List *L);
void    ft_list_inverted_print(const List *L);

/*+++===ft_structs_2===+++*/
size_t  ft_list_size(const List *L);
bool    ft_list_is_empty(const List *L);
int     ft_list_get_first_val(const List *L);
int     ft_list_get_last_val(const List *L);

/*+++===ft_structs_2===+++*/
void    ft_list_add_first(List *L, int val);
void    ft_list_add_last(List *L, int val);
void    ft_list_remove_first(List *L);
void    ft_list_remove_last(List *L);

/*+++===ft_structs_3===+++*/
void    ft_list_add_first(List *L, int val);
void    ft_list_add_last(List *L, int val);
void    ft_list_remove_first(List *L);
void    ft_list_remove_last(List *L);

/*+++===ft_utils_1===+++*/
long    ft_atol(char *str);
int     ft_isspace(int c);
List    *ft_valid_input_order_asc(List *L);
List    *ft_valid_input_order_desc(List *L);
void    ft_list_to_array(List *L_a, int **sort);

/*+++===ft_utils_2===+++*/
int     *ft_order_arr(int *sort, size_t len);
List    *ft_put_index(List *L, int *sort);
void	ft_free_list(List **L_a, List **L_b);
void    ft_free_structs(List **L_a, List **L_b, int **sort);

/*+++===ft_valid_input===+++*/
List    *ft_valid_input(int argc, char **argv, List *L);
int     ft_valid_character(char *argv);
int     ft_valid_duplic(List *L, int val);

#endif
