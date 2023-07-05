/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:35:44 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 20:36:00 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_array(char **tmp_av)
{
	int	i;

	i = 0;
	while (tmp_av[i])
		free(tmp_av[i++]);
	free(tmp_av);
}

void	error_malloc(char *array)
{
	free(array);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_free_2d(char **tmp_av)
{
	int	i;

	i = 0;
	while (tmp_av[i])
		free(tmp_av[i++]);
	free(tmp_av);
	write(2, "Error\n", 6);
	exit(1);
}


void	error_nodes(t_circularList *a)
{
	t_CLnode	*del_node;

	write(2, "Error\n", 6);
	del_node = a->top;
	while (a->top != NULL)
	{
		a->top = a->top->next;
		free(del_node);
		del_node = a->top;
	}
	exit (1);
}

void	error_2d_nodes(t_circularList *a, char **tmp_av)
{
	t_CLnode	*del_node;

	write(2, "Error\n", 6);
	free_2d_array(tmp_av);
	del_node = a->top;
	while (a->top != NULL)
	{
		a->top = a->top->next;
		free(del_node);
		del_node = a->top;
	}
	exit (1);
}

// void	its_error(void)
// {
// 	write(2, "Error\n", 6);
// 	exit(EXIT_FAILURE);
// }
// void	error_integers(char **array, t_stack *stack)
// {
// 	free_2d_array(array);
// 	free_stack(stack);
// 	ft_putstr_fd("Error\n", 2);
// 	exit(1);
// }

