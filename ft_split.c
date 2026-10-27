/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:37:23 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/27 16:26:37 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int		words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			words++;
		}
		else
			i++;
	}
	return (words);
}

static int	get_words_size(char const *s, char c)
{
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static void	verif(int *j, char **res)
{
	while ((*j) >= 0)
	{
		free(res[(*j)]);
		(*j)--;
	}
	free (res);
}

static char	**ft_split_two(char const *s, char c, char **res)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j < count_words(s, c))
	{
		if (s[i] && s[i] != c)
		{
			res[j] = ft_calloc(sizeof(char), get_words_size(s + i, c) + 1);
			if (!res[j])
			{
				verif(&j, res);
				return (NULL);
			}
			ft_strlcpy(res[j], s + i, get_words_size(s + i, c) + 1);
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res || !s)
		return (NULL);
	res = ft_split_two(s, c, res);
	return (res);
}
