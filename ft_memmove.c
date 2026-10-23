/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:33:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/23 20:41:22 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_ptr;
	size_t			i;

	if (!dest && !src)
		return (dest);
	src_ptr = (unsigned char *)src;
	i = 0;
	if ((unsigned char *)dest > src_ptr)
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = src_ptr[i];
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = src_ptr[i];
			i++;
		}
	}
	return ((unsigned char *)dest);
}
