/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_stack_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 17:07:50 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 22:05:32 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_circularList *a)
{
	t_CLnode	*tmp;

	tmp = a->top;
	if (a->size == 0 || a->size == 1)
		return ;
	if (a->size == 2)
	{
		tmp->next = NULL;
		a->top = a->find_last_node;
		tmp->prev = a->top;
		a->top->next = tmp;
		a->find_last_node = tmp;
	}
	else
	{
		a->top = tmp->next;
		tmp->next = a->top->next;
		tmp->prev = a->top;
		a->top->next = tmp;
		tmp->next->prev = tmp;
	}
	set_index(a);
	write(1, "sa\n", 3);
}

void	sb(t_circularList *b)
{
	t_CLnode	*tmp;

	tmp = b->top;
	if (b->size == 0 || b->size == 1)
		return ;
	if (b->size == 2)
	{
		tmp->next = NULL;
		b->top = b->find_last_node;
		tmp->prev = b->top;
		b->top->next = tmp;
		b->find_last_node = tmp;
	}
	else
	{
		b->top = tmp->next;
		tmp->next = b->top->next;
		tmp->prev = b->top;
		b->top->next = tmp;
		tmp->next->prev = tmp;
	}
	set_index(b);
	write(1, "sb\n", 3);
}

void	ss(t_circularList *a, t_circularList *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
