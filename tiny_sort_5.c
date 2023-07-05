/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:01:44 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 21:21:59 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_to_b(t_circularList *a, t_circularList *b)
{
	t_CLnode	*target_node;

	target_node = a->the_smallest_node;
	if (!(target_node == a->top))
	{
		if (!(target_node == a->top) && (a->size % 2 == 1
				&& target_node->index == a->size / 2 + 1))
			ra(a);
		while (!(target_node == a->top) && target_node->index <= a->size / 2)
			ra(a);
		while (!(target_node == a->top) && target_node->index > a->size / 2)
			rra(a);
	}
	pb(a, b);
}

void	tiny_sort_5(t_circularList *a, t_circularList *b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		find_smallest_node(a);
		// printf("=> %d has index of %d a size is %d\n", a->the_smallest_node->value, a->the_smallest_node->index);
		pass_to_b(a, b);
		// printf("----- END -------\n");
	}
	if (b->top->value < b->top->next->value)
		sb(b);
	tiny_sort_3(a);
	pa(a, b);
	pa(a, b);
}
