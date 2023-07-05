/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:52:28 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 12:23:03 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stack(t_circularList *a, t_circularList *b)
{
	a->top = NULL;
	a->find_last_node = NULL;
	a->size = 0;
	a->the_smallest_node = a->top;
	b->top = NULL;
	b->find_last_node = NULL;
	b->size = 0;
	b->the_smallest_node = b->top;
}

void	free_stack(t_circularList *a)
{
	t_CLnode	*del_node;

	del_node = a->top;
	while (a->top != NULL)
	{
		a->top = a->top->next;
		free(del_node);
		del_node = a->top;
	}
}

int	stack_sorted(t_circularList *a)
{
	t_CLnode	*tmp;

	tmp = a->top;
	if (a->size == 1)
		exit(0);
	while (tmp != a->find_last_node)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
