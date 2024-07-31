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

# define FALSE	0
# define TRUE	1

typedef struct doubly_node
{
	int					val;
	int					index;
	int					group;
	struct doubly_node	*prev;
	struct doubly_node	*next;
}	t_node;

typedef struct doubly_linked_list
{
	t_node	*begin;
	t_node	*end;
	size_t	size;
	int		ret;
}	t_dlist;

typedef struct s_pivot
{
	int	index;
	int	value;
	int	qtd;
	int	group;
	int	first;
}	t_pivot;

void	ft_sort_two(t_dlist *l_a);
void	ft_sort_three_a(t_dlist *l_a);
void	ft_sort_five(t_dlist *l_a, t_dlist *l_b);
void	ft_sort_one_hundred(t_dlist *l_a, t_dlist *l_b, int *sort, int first);
void	ft_can_swap(t_dlist *l_a, t_dlist *l_b);
void	ft_sort_five_hundred(t_dlist *l_a, t_dlist *l_b);
void	ft_swap_stack(t_dlist *l, char *str);
void	ft_swap_stack_both(t_dlist *l_a, t_dlist *l_b, char *str);
void	ft_rotato_stack(t_dlist *l, char *str);
void	ft_rotato_stack_both(t_dlist *l_a, t_dlist *l_b, char *str);
void	ft_reverse_rotato_stack(t_dlist *l, char *str);
void	ft_reverse_rotato_stack_both(t_dlist *l_a, t_dlist *l_b, char *str);
void	ft_push_stack(t_dlist *l_source, t_dlist *l_dest, char *str);
void	ft_dlist_destroy(t_dlist **l_ref);
void	ft_dlist_print(const t_dlist *l);
void	ft_dlist_inverted_print(const t_dlist *l);
void	ft_dlist_add_first(t_dlist *l, int val);
void	ft_dlist_add_last(t_dlist *l, int val);
void	ft_dlist_remove_first(t_dlist *l);
void	ft_dlist_remove_last(t_dlist *l);
void	ft_dlist_add_first(t_dlist *l, int val);
void	ft_dlist_add_last(t_dlist *l, int val);
void	ft_dlist_remove_first(t_dlist *l);
void	ft_dlist_remove_last(t_dlist *l);
void	ft_free_list(t_dlist **l_a, t_dlist **l_b);
void	ft_free_structs(t_dlist **l_a, t_dlist **l_b, int **sort, char **str);
void	ft_free_2point(char **str);
void	ft_dlist_to_array(t_dlist *l, int **sort);
t_pivot	ft_put_pivot(int *sort, int size, int first);
t_node	*ft_node_create(int val);
t_dlist	*ft_dlist_create(void);
t_dlist	*ft_valid_input_order_asc(t_dlist *l);
t_dlist	*ft_valid_input_order_desc(t_dlist *l);
t_dlist	*ft_put_index(t_dlist *L, int *sort);
t_dlist	*ft_valid_input(int argc, char **argv, t_dlist *l);
size_t	ft_dlist_size(const t_dlist *l);
bool	ft_dlist_is_empty(const t_dlist *l);
int		ft_push_swap(int argc, char **argv);
int		ft_dlist_get_first_val(const t_dlist *l);
int		ft_dlist_get_last_val(const t_dlist *l);
int		ft_isspace(int c);
int		ft_valid_character(char *argv);
int		ft_valid_duplic(t_dlist *l, int val);
int		*ft_order_arr(int *sort, size_t len);
long	ft_atol(char *str);
char	**ft_split_input(t_dlist *l_a, char **argv);

#endif
