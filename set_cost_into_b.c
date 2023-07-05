/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_into_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:25:08 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 21:31:59 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_smallest_a(t_CLnode *node_b, t_circularList *a)
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
	node_b->target_node = tmp2;
}

void	set_target_node_b(t_circularList *a, t_circularList *b)
{
	t_CLnode	*node_b;
	t_CLnode	*current_a;
	int			prev_small_num;

	node_b = b->top;
	while (node_b != NULL)
	{
		current_a = a->top;
		prev_small_num = INT32_MAX;
		while (current_a)
		{
			if ((node_b->value < current_a->value)
				&& (current_a->value <= prev_small_num))
			{
				prev_small_num = current_a->value;
				node_b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (prev_small_num == INT32_MAX)
			set_smallest_a(node_b, a);
		node_b = node_b->next;
	}
}

void	move_into_a(t_circularList *a, t_circularList *b)
{
	t_CLnode	*node_b;
	t_CLnode	*target_node;

	node_b = b->top;
	while (node_b)
	{
		target_node = node_b->target_node;
		if (!(node_b->target_node == a->top))
		{
			if (!(node_b->target_node == a->top)
				&& (a->size % 2 == 1 && target_node->index == a->size / 2 + 1))
				ra(a);
			while (!(node_b->target_node == a->top)
				&& target_node->index <= a->size / 2)
				ra(a);
			while (!(node_b->target_node == a->top)
				&& target_node->index > a->size / 2)
				rra(a);
		}
		node_b = node_b->next;
		pa(a, b);
		set_target_node_b(a, b);
	}
}
