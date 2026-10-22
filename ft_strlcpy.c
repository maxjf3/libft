/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:23:18 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:53:39 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 0)
		return (0);
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

// int main(void)
// {
//     const char* src = "0123456789";
//     const char* src2 = "0123456789";
//     char dst[] = "abcdefghijklmnopdfkfl";
//     char dst2[] = "abcdefghijklmnopdfkfl";
//     size_t res;
//     size_t res2;

//     res = ft_strlcpy(dst, src, 100);
//     res2 = ft_strlcpy(dst2, src2, 100);

//     printf("%zu,\n%s\n", res, dst);
//     printf("%zu,\n%s\n", res2, dst2);
//     return (0);
// }