/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost_into_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:25:18 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 22:03:39 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_circularList *a, t_circularList *b)
{
	t_CLnode	*tmp;
	t_CLnode	*tmp2;
	int			prev_price;

	tmp = a->top;
	prev_price = INT32_MAX;
	while (tmp)
	{
		if (tmp->index <= a->size / 2)
			tmp->price = tmp->index;
		else if (a->size % 2 == 1 && tmp->index == a->size / 2 + 1)
			tmp->price = tmp->index;
		else
			tmp->price = a->size - tmp->index + 2;
		tmp2 = tmp->target_node;
		if (tmp2->index <= b->size / 2)
			tmp->price += tmp2->index - 1;
		else if (b->size % 2 == 1 && tmp2->index == b->size / 2 + 1)
			tmp->price += tmp2->index - 1;
		else
			tmp->price += b->size - tmp2->index + 1;
		if (tmp->price < prev_price)
		{
			a->the_cheapest_node = tmp;
			prev_price = tmp->price;
		}
		tmp = tmp->next;
	}
}

void	set_biggest_b(t_CLnode *node_a, t_circularList *b)
{
	t_CLnode	*tmp;
	t_CLnode	*tmp2;
	int			biggest;

	tmp = b->top;
	tmp2 = b->top;
	biggest = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > biggest)
		{
			biggest = tmp->value;
			tmp2 = tmp;
		}
		tmp = tmp->next;
	}
	node_a->target_node = tmp2;
}

void	set_target_node_a(t_circularList *a, t_circularList *b)
{
	t_CLnode	*node_a;
	t_CLnode	*current_b;
	int			prev_big_num;

	node_a = a->top;
	while (node_a != NULL)
	{
		current_b = b->top;
		prev_big_num = INT32_MIN;
		while (current_b)
		{
			if ((node_a->value > current_b->value)
				&& (current_b->value >= prev_big_num))
			{
				prev_big_num = current_b->value;
				node_a->target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (prev_big_num == INT32_MIN)
			set_biggest_b(node_a, b);
		node_a = node_a->next;
	}
}
