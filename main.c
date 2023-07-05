/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:05:31 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 23:56:43 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static void	check_digit(char **tmp_av)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (tmp_av[++j])
	{
		i = 0;
		// if (ft_strlen(tmp_av[j]) > 11)
		// 	error_free_2d(tmp_av);
		if (tmp_av[j][i] == '-' || tmp_av[j][i] == '+')
			i++;
		if (!ft_isdigit(tmp_av[j][i]))
			error_free_2d(tmp_av);
		while (tmp_av[j][i])
		{
			if (!ft_isdigit(tmp_av[j][i++]))
				error_free_2d(tmp_av);
		}
	}
}

static void	print_av(char **tmp)
{
	int	i = 0;
	int	j = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j] != '\0')
		{
			printf("%c", tmp[i][j]);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_circularList	a;
	t_circularList	b;
	char			**tmp_av;

	//! sprint1 : push into stack A
	prepare_stack(&a, &b);
	if (ac < 2)
		return (0);
	check_empty_string(ac, av);
	check_white_space(ac, av);
	tmp_av = join_av(ac, av);
	check_digit(tmp_av);
	stack_init(&a, tmp_av);
	if (!stack_sorted(&a))
	{
		if (a.size == 2)
			sa(&a);
		else if (a.size == 3)
			tiny_sort_3(&a);
		else if (a.size == 5)
			tiny_sort_5(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_2d_array(tmp_av);
	return (0);
}
