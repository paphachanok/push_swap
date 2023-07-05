/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:02:21 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/04 00:02:23 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_circularList *a)
{
	t_CLnode	*tmp;
	int			biggest;

	tmp = a->top;
	biggest = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > biggest)
			biggest = tmp->value;
		tmp = tmp->next;
	}
	return (biggest);
}

void	tiny_sort_3(t_circularList *a)
{
	int	biggest;

	biggest = find_biggest(a);
	if (a->top->value == biggest)
		ra(a);
	else if (a->top->next->value == biggest)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}
