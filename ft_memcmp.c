/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:31:32 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:34:29 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while ((s1_ptr[i] || s2_ptr[i]) && i < n)
	{
		if (s1_ptr[i] - s2_ptr[i] != 0)
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	const char* s1 = "Bonjour";
// 	const char* s2 = "Bonjourr";

// 	printf("%d\n", ft_memcmp(s1, s2, 8));
// 	printf("%d\n", memcmp(s1, s2, 8));
// 	return (0);
// }
