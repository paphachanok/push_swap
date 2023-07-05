/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_into_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:53:32 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 23:24:44 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_upper(t_circularList *a, t_CLnode *node)
{
	if ((node->index <= a->size / 2 || (node->index == a->size / 2 + 1
				&& a->size % 2 == 1)) && node != a->top)
		return (1);
	return (0);
}

static int	check_lower(t_circularList *a, t_CLnode *node)
{
	if (node->index > a->size / 2
		&& node != a->top)
		return (1);
	return (0);
}

void	move_into_b(t_circularList *a, t_circularList *b)
{
	t_CLnode	*node_a;
	t_CLnode	*target_node;

	node_a = a->the_cheapest_node;
	target_node = node_a->target_node;
	while (check_upper(a, node_a) && check_upper(b, target_node))
		rr(a, b);
	while (check_lower(a, node_a) && check_lower(b, target_node))
		rrr(a, b);
	while (check_upper(a, node_a))
		ra(a);
	while (check_lower(a, node_a))
		rra(a);
	while (check_upper(b, target_node))
		rb(b);
	while (check_lower(b, target_node))
		rrb(b);
	pb(a, b);
}
