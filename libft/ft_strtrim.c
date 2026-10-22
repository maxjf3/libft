/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:47:24 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 18:35:34 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		res_index;
	int		i;
	int		s1_index;

	i = 0;
	s1_index = 0;
	res_index = 0;
	res = malloc(sizeof(char) * ft_strlen(s1));
	if (!res)
		return (NULL);
	while (s1[s1_index])
	{
		if (set[i] == s1[s1_index])
			i++;
		else
		{
			res[res_index] = s1[s1_index];
			s1_index++;
			res_index++;
			i++;
		}
	}
	return (res);
}
