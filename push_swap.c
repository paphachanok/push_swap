/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:20:27 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/03 23:43:07 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_circularList *a, t_circularList *b)
{
	//! sprint2 : push to stack B
	pb(a, b);
	pb(a, b);
	// printf("-----\n");
	// stack_print_all(&a);
	// printf("-----\n");
	// stack_print_all(&b);
	while (a->size > 3)
	{
		set_target_node_a(a, b);
		set_price(a, b);
		move_into_b(a, b);
	}
	//! sprint3 : last three elements
	tiny_sort_3(a);
	// printf("--- debug one ----\n");
	// stack_print_all(&a);
	// printf("--- debug one ----\n");
	// stack_print_all(&b);

	//! sprint4 : push back to stack A
	set_target_node_b(a, b);
	move_into_a(a, b);
	// printf("--- debug one 2 ----\n");
	// stack_print_all(&a);
	// printf("--- debug one 2 ----\n");
	// stack_print_all(&b);

	//! sprint5 : final arrangement
	final_arrangement(a);
	// printf("--- debug zone 3 ----\n");
	// stack_print_all(&a);
	// printf("--- debug zone 3 ----\n");
	// stack_print_all(&b);
}

