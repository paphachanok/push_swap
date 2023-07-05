/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_stack_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:40:44 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/04 15:36:31 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_circularList *a)
{
	int			i;
	t_CLnode	*tmp;

	i = 1;
	tmp = a->top;
	while (tmp != NULL)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	pa(t_circularList *a, t_circularList *b)
{
	t_CLnode	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	if (b->size - 1 == 0)
		b->find_last_node = b->find_last_node->next;
	tmp->next = a->top;
	a->top->prev = tmp;
	a->top = tmp;
	a->size++;
	b->size--;
	set_index(a);
	set_index(b);
	write(1, "pa\n", 3);
}

// void	pa(t_circularList *a, t_circularList *b)
// {
// 	t_CLnode	*tmp;

// 	if (b->size == 0)
// 		return ;
// 	tmp = b->top;
// 	tmp->prev = NULL;
// 	if (b->size - 1 == 0)
// 	{
// 		tmp->next = a->top;
// 		a->top->prev = tmp;
// 		b->top = NULL;
// 		b->find_last_node = NULL;
// 		a->top = tmp;
// 	}
// 	else
// 	{
// 		b->top = tmp->next;
// 		tmp->next = a->top;
// 		a->top->prev = tmp;
// 		a->top = tmp;
// 		b->top->prev = NULL;
// 	}
// 	a->size++;
// 	b->size--;
// 	set_index(a);
// 	set_index(b);
// 	write(1, "pa\n", 3);
// }

void	pb(t_circularList *a, t_circularList *b)
{
	t_CLnode	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	a->top->prev = NULL;
	if (b->top == NULL)
	{
		b->top = tmp;
		b->top->next = NULL;
		b->find_last_node = tmp;
	}
	else
	{
		tmp->next = b->top;
		b->top->prev = tmp;
		b->top = tmp;
	}
	a->size--;
	b->size++;
	set_index(a);
	set_index(b);
	write(1, "pb\n", 3);
}
