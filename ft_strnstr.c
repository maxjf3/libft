/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:08:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/27 15:18:25 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_ptr;

	i = 0;
	big_ptr = (char *)big;
	if (ft_strlen((char *)little) > ft_strlen(big_ptr))
		return (NULL);
	if (ft_strlen(big_ptr) == 0 || ft_strlen(little) <= 0)
		return (big_ptr + i);
	while (big_ptr[i] && i < len)
	{
		j = 0;
		while ((big_ptr[i + j] == little[j])
			&& (big_ptr[i + j]) && (i + j < len))
			j++;
		if (j == ft_strlen(little))
			return (big_ptr + i);
		i++;
	}
	return (NULL);
}
