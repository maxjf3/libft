/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:38:56 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 18:34:12 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	size_t			i;

	dest_ptr = dest;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
