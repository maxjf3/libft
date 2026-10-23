/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:50:50 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/23 14:38:13 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	res = malloc (sizeof(char *) * (s1_len + s2_len));
	if (!res)
		return (NULL);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}
