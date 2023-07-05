/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoti <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:50:50 by ppoti             #+#    #+#             */
/*   Updated: 2023/07/05 17:32:09 by ppoti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_a_word(char const *s, char c)
{
	size_t	j;
	char	*word;
	size_t	len;

	j = 0;
	len = ft_len(s, c);
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split_av(char const *av1, char seperater)
{
	size_t	j;
	char	**result;

	j = 0;
	result = (char **)malloc(sizeof(char *) * (count_word(av1, seperater) + 1));
	if (!result)
		return (0);
	while (*av1)
	{
		while (*av1 == seperater && *av1)
			av1++;
		if (*av1)
			result[j++] = ft_a_word(av1, seperater);
		while (*av1 != seperater && *av1)
			av1++;
	}
	result[j] = NULL;
	return (result);
}
