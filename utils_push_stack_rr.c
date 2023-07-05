/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_stack_rr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 08:41:22 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 22:20:02 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_circularList *a)
{
	t_CLnode	*tmp;

	if (a->size == 0 || a->size == 1)
		return ;
	tmp = a->find_last_node;
	a->find_last_node = tmp->prev;
	a->find_last_node->next = NULL;
	tmp->next = a->top;
	a->top->prev = tmp;
	a->top = tmp;
	set_index(a);
	write(1, "rra\n", 4);
}

void	rrb(t_circularList *b)
{
	t_CLnode	*tmp;

	if (b->size == 0 || b->size == 1)
		return ;
	tmp = b->find_last_node;
	tmp->next = b->top;
	b->top->prev = tmp;
	b->find_last_node = tmp->prev;
	b->find_last_node->next = NULL;
	b->top = tmp;
	set_index(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_circularList *a, t_circularList *b)
{
	t_CLnode	*tmp;

	if ((a->size == 0 || a->size == 1) || (b->size == 0 || b->size == 1))
		return ;
	tmp = a->find_last_node;
	a->find_last_node = tmp->prev;
	a->find_last_node->next = NULL;
	tmp->next = a->top;
	a->top->prev = tmp;
	a->top = tmp;
	set_index(a);
	tmp = b->find_last_node;
	tmp->next = b->top;
	b->top->prev = tmp;
	b->find_last_node = tmp->prev;
	b->find_last_node->next = NULL;
	b->top = tmp;
	set_index(b);
	write(1, "rrr\n", 4);
}
