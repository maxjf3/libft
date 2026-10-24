/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:47:24 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 13:05:36 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[start], set))
		start++;
	while (in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end + 1) - start));
}
