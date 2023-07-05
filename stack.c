/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:09:55 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 21:09:36 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_dup_error(t_circularList *a)
{
	t_CLnode	*tmp;
	t_CLnode	*tmp2;

	tmp = a->top;
	if (a->size == 1)
		return (0);
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	push_to_bottom(t_circularList *a, int nbr)
{
	t_CLnode	*new_node;

	if (a == NULL)
		return ;
	new_node = malloc(sizeof(t_CLnode));
	if (new_node == NULL)
		return ;
	new_node->value = nbr;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (a->top == NULL)
	{
		a->top = new_node;
		a->find_last_node = new_node;
	}
	else
	{
		a->find_last_node->next = new_node;
		new_node->prev = a->find_last_node;
		a->find_last_node = new_node;
	}
	a->size++;
	set_index(a);
}

static long	ft_atol(const char *str)
{
	long	negative;
	long	result;

	result = 0;
	negative = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + (*str - 48);
			str++;
		}
	}
	return (negative * result);
}

//! don't forget to deletes ---------------------------
void	stack_print_all(t_circularList *a)
{
	t_CLnode	*tmp;

	tmp = a->top;
	while (tmp != NULL)
	{
		printf("%d \n", tmp->value);
		tmp = tmp->next;
	}
}

// void	stack_print_target_node(t_circularList *a)
// {
// 	t_CLnode	*tmp;

// 	tmp = a->top;
// 	while (tmp != NULL)
// 	{
// 		// printf("%d has target as %d and has price of %d \n", tmp->value, tmp->target_node->value, tmp->price);
// 		printf("%d \n", tmp->target_node->value);
// 		tmp = tmp->next;
// 	}
// }

// void	stack_print_prev(t_circularList *a)
// {
// 	t_CLnode	*tmp;

// 	tmp = a->find_last_node;
// 	while (tmp != a->top)
// 	{
// 		printf("%d \n", tmp->value);
// 		tmp = tmp->prev;
// 	}
// 	printf("%d \n", a->top->value);
// }
//! don't forget to deletes ------------------------------

void	stack_init(t_circularList *a, char **tmp_av)
{
	long	nbr;

	while (*tmp_av)
	{
		nbr = ft_atol(*tmp_av);
		// printf("=> %ld\n", nbr);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_2d_nodes(a, tmp_av);
		push_to_bottom(a, (int)nbr);
		if (find_dup_error(a))
			error_nodes(a);
		if (a->top == NULL)
		{
			error_free_2d(tmp_av);
			free_stack(a);
			error_malloc(NULL);
		}
		++tmp_av;
	}
}
