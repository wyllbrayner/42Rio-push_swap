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
# include <stdio.h>

typedef struct _input_int
{
    long    size;
    long    arr[1024];
    int     order;
    int     ret;
} s_input;

typedef struct _doubly_node
{
    int                     val;
    struct _doubly_node     *prev;
    struct _doubly_node     *next;
} Node;

typedef struct _doubly_linked_list
{
    Node        *begin;
    Node        *end;
    size_t      size;
    int         ret;
    int         order;
} List;

int     ft_push_swap(int argc, char **argv);
List    *ft_valid_input(int argc, char **argv, List *L);

int     ft_valid_input_amount(int argc);
int     ft_valid_input_character(char **argv);
List    ft_valid_input_isint(int argc, char **argv);
List    *ft_valid_input_isorder(List *L);
int     ft_valid_input_isduplic(s_input val);
void	ft_swap_stack(List *L);
void	ft_rotato_stack(List *L);
void	ft_reverse_rotato_stack(List *L);
void	ft_push_stack(List *L_source, List *L_dest);

long    ft_atol(char *str);
int     ft_isspace(int c);
void    ft_error(void);

Node    *Node_create(int val);
List    *List_create();
void    List_destroy(List **L_ref);
bool    List_is_empty(const List *L);
void    List_add_first(List *L, int val);
void    List_print(const List *L);
void    List_inverted_print(const List *L);
void    List_add_last(List *L, int val);
size_t  List_size(const List *L);
void    List_remove(List *L, int val);
void    List_remove_first(List *L);
void    List_remove_last(List *L);
int     List_get_first_val(const List *L);
int     List_get_last_val(const List *L);

#endif
