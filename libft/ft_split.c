/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:37:23 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 13:43:14 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char str, char c)
{
	if (c == str)
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			count++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*word_split(char *str, char *charset)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const*s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!res || !str || !charset)
		return (NULL);
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			res[j] = word_split(&str[i], charset);
			while (str[i] && !is_charset(str[i], charset))
				i++;
			j++;
		}
		else
			i++;
	}
	res[j] = 0;
	return (res);
}