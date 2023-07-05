/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:52:07 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 16:59:35 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

void	check_empty_string(int ac, char **av)
{
	int	i;
	int	count;
	int	error;

	i = 0;
	count = 0;
	error = 0;
	while (ac > ++i)
	{
		if (!av[i][0])
			error++;
		else
			count++;
	}
	if ((error > 0 && count > 0) || (ac >= 2 && error > 0))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (error > 0 && count == 0)
		exit (0);
	else
		return ;
}

void	check_white_space(int ac, char **av)
{
	int		i;
	int		j;
	int		space;

	i = 0;
	j = 0;
	space = 0;
	while (ac > ++i)
	{
		while (ft_isspace(av[i][j]) && av[i][j])
		{
			space++;
			j++;
			if (av[i][j] == '\0' && j == space)
			{
				write(2, "Error\n", 6);
				exit (0);
			}
		}
		i++;
	}
	return ;
}
