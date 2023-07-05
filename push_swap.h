/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 01:57:26 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 22:06:34 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_CLnode
{
	int				value;
	int				index;
	int				price;
	struct s_CLnode	*target_node;
	struct s_CLnode	*prev;
	struct s_CLnode	*next;
}	t_CLnode;

typedef struct s_circularList
{
	int			size;
	t_CLnode	*top;
	t_CLnode	*find_last_node;
	t_CLnode	*lowest_price_node;
	t_CLnode	*the_smallest_node;
	t_CLnode	*the_cheapest_node;
}	t_circularList;

void		prepare_stack(t_circularList *a, t_circularList *b);
void		free_stack(t_circularList *a);
int			stack_sorted(t_circularList *a);

void		check_empty_string(int ac, char **av);
void		check_white_space(int ac, char **av);

char		**join_av(int ac, char **av);
char		**ft_split_av(char const *av1, char seperater);
void		free_2d_array(char **tmp_av);
void		error_malloc(char *array);
void		error_free_2d(char **tmp_av);
void		error_nodes(t_circularList *a);
void		error_2d_nodes(t_circularList *a, char **tmp_av);
void		stack_init(t_circularList *a, char **tmp_av);


//!

void		stack_print_all(t_circularList *a);
void		stack_init(t_circularList *a, char **av);
void		push_swap(t_circularList *a, t_circularList *b);

void		set_index(t_circularList *a);
void		pa(t_circularList *a, t_circularList *b);
void		pb(t_circularList *a, t_circularList *b);
void		move_into_b(t_circularList *a, t_circularList *b);
void		set_price(t_circularList *a, t_circularList *b);
void		set_biggest_b(t_CLnode *node_a, t_circularList *b);
void		set_target_node_a(t_circularList *a, t_circularList *b);

void		stack_print_target_node(t_circularList *a); //! delete
void		stack_print_prev(t_circularList *a); //! delete
void		ra(t_circularList *a);
void		rb(t_circularList *b);
void		rr(t_circularList *a, t_circularList *b);
void		rra(t_circularList *a);
void		rrb(t_circularList *b);
void		rrr(t_circularList *a, t_circularList *b);
void		sa(t_circularList *a);
void		sb(t_circularList *b);
void		ss(t_circularList *a, t_circularList *b);

int			find_biggest(t_circularList *a);
void		tiny_sort_3(t_circularList *a);
void		pass_to_b(t_circularList *a, t_circularList *b);
void		tiny_sort_5(t_circularList *a, t_circularList *b);

void		set_smallest_a(t_CLnode *node_b, t_circularList *a);
void		set_target_node_b(t_circularList *a, t_circularList *b);
void		move_into_a(t_circularList *a, t_circularList *b);

void		find_smallest_node(t_circularList *a);
void		final_arrangement(t_circularList *a);

#endif
