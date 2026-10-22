/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:18:37 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:33:57 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	size_t			i;

	s_ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == c)
			return (s_ptr + i);
		i++;
	}
	return (s_ptr + i);
}

// int main(void)
// {
//     const char* str = "Bonjour";
//     ft_memchr(str, 'j', strlen(str));
//     return (0);
// }