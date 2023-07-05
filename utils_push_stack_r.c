/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_stack_r.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:30:35 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 22:09:50 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_circularList *a)
{
	t_CLnode	*tmp;

	if (a->size == 0 || a->size == 1)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	tmp->prev = a->find_last_node;
	a->find_last_node->next = tmp;
	a->find_last_node = tmp;
	set_index(a);
	write(1, "ra\n", 3);
}

void	rb(t_circularList *b)
{
	t_CLnode	*tmp;

	if (b->size == 0 || b->size == 1)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
	tmp->prev = b->find_last_node;
	b->find_last_node->next = tmp;
	b->find_last_node = tmp;
	set_index(b);
	write(1, "rb\n", 3);
}

void	rr(t_circularList *a, t_circularList *b)
{
	t_CLnode	*tmp;

	if (a->size == 0 || a->size == 1)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	tmp->prev = a->find_last_node;
	a->find_last_node->next = tmp;
	a->find_last_node = tmp;
	set_index(a);
	if (b->size == 0 || b->size == 1)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
	tmp->prev = b->find_last_node;
	b->find_last_node->next = tmp;
	b->find_last_node = tmp;
	set_index(b);
	write(1, "rr\n", 3);
}
