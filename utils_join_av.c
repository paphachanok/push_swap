/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_join_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:49:03 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 18:41:05 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (0);
	while (*s1 != '\0')
	{
		dest[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*join_to_av1(int ac, char **av)
{
	int		i;
	char	*join;
	char	*before;
	char	*del;

	i = 1;
	join = malloc(sizeof(char *) * 1);
	join[0] = '\0';
	while (i < ac)
	{
		before = ft_strjoin(" ", av[i]);
		del = join;
		join = ft_strjoin(join, before);
		free(before);
		free(del);
		i++;
	}
	return (join);
}

char	**join_av(int ac, char **av)
{
	char	*str;
	char	**tmp_av;

	str = NULL;
	if (ac == 2)
	{
		tmp_av = ft_split_av(av[1], ' ');
		if (tmp_av == NULL)
			error_malloc(NULL);
	}
	else
	{
		str = join_to_av1(ac, av);
		tmp_av = ft_split_av(str, ' ');
		if (tmp_av == NULL)
			error_malloc(str);
		free(str);
	}
	return (tmp_av);
}
