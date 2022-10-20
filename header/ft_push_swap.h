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
}	t_list;

typedef struct s_pivot
{
	int	index;
	int	value;
	int	qtd;
	int	group;
	int	first;
}	t_pivot;

void	ft_sort_two(t_list *l_a);
void	ft_sort_three_a(t_list *l_a);
void	ft_sort_five(t_list *l_a, t_list *l_b);
void	ft_sort_one_hundred(t_list *l_a, t_list *l_b, int *sort, int first);
void	ft_can_swap(t_list *l_a, t_list *l_b);
void	ft_sort_five_hundred(t_list *l_a, t_list *l_b);
void	ft_swap_stack(t_list *l, char *str);
void	ft_swap_stack_both(t_list *l_a, t_list *l_b, char *str);
void	ft_rotato_stack(t_list *l, char *str);
void	ft_rotato_stack_both(t_list *l_a, t_list *l_b, char *str);
void	ft_reverse_rotato_stack(t_list *l, char *str);
void	ft_reverse_rotato_stack_both(t_list *l_a, t_list *l_b, char *str);
void	ft_push_stack(t_list *l_source, t_list *l_dest, char *str);
void	ft_list_destroy(t_list **l_ref);
void	ft_list_print(const t_list *l);
void	ft_list_inverted_print(const t_list *l);
void	ft_list_add_first(t_list *l, int val);
void	ft_list_add_last(t_list *l, int val);
void	ft_list_remove_first(t_list *l);
void	ft_list_remove_last(t_list *l);
void	ft_list_add_first(t_list *l, int val);
void	ft_list_add_last(t_list *l, int val);
void	ft_list_remove_first(t_list *l);
void	ft_list_remove_last(t_list *l);
void	ft_free_list(t_list **l_a, t_list **l_b);
void	ft_free_structs(t_list **l_a, t_list **l_b, int **sort, char **str);
void	ft_free_2point(char **str);
void	ft_list_to_array(t_list *l, int **sort);

t_pivot	ft_put_pivot(int *sort, int size, int first);

t_node	*ft_node_create(int val);

t_list	*ft_list_create(void);
t_list	*ft_valid_input_order_asc(t_list *l);
t_list	*ft_valid_input_order_desc(t_list *l);
t_list	*ft_put_index(t_list *L, int *sort);
t_list	*ft_valid_input(int argc, char **argv, t_list *l);

size_t	ft_list_size(const t_list *l);

bool	ft_list_is_empty(const t_list *l);

int		ft_push_swap(int argc, char **argv);
int		ft_list_get_first_val(const t_list *l);
int		ft_list_get_last_val(const t_list *l);
int		ft_isspace(int c);
int		ft_valid_character(char *argv);
int		ft_valid_duplic(t_list *l, int val);

int		*ft_order_arr(int *sort, size_t len);

long	ft_atol(char *str);

char	**ft_split_input(t_list *l_a, int argc, char **argv);
#endif
