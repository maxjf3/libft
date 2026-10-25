/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:02:01 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 14:18:34 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	if (size <= 0)
		return (ft_strlen(src));
	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = len_dest;
	if (size <= ft_strlen(dst))
		return (len_src + size);
	while (src[i] && i < size - len_dest - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_dest + len_src);
}
