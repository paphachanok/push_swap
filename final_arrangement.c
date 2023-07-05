/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_arrangement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:24:15 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 23:29:16 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest_node(t_circularList *a)
{
	t_CLnode	*tmp;
	t_CLnode	*tmp2;
	int			smallest;

	tmp = a->top;
	tmp2 = a->top;
	smallest = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < smallest)
		{
			smallest = tmp->value;
			tmp2 = tmp;
		}
		tmp = tmp->next;
	}
	a->the_smallest_node = tmp2;
}

void	final_arrangement(t_circularList *a)
{
	t_CLnode	*smallest_node;

	find_smallest_node(a);
	smallest_node = a->the_smallest_node;
	if (!(smallest_node == a->top))
	{
		if (!(smallest_node == a->top) && (a->size % 2 == 1 && smallest_node->index == a->size / 2 + 1))
			ra(a);
		while (!(smallest_node == a->top) && smallest_node->index <= a->size / 2)
			ra(a);
		while (!(smallest_node == a->top) && smallest_node->index > a->size / 2)
			rra(a);
	}
}
