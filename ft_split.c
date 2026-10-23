/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:37:23 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/23 23:01:24 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(char const *s, char c)
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

int	get_words_size(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		if (s[i] && s[i] != c)
		{
			res[j] = malloc((sizeof(char) * get_words_size(s + i, c)) + 1);
			if (!res[j])
				return (NULL);
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
