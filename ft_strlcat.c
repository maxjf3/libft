/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:02:01 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:52:19 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = len_dest;
	if (size <= len_dest)
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

// int main(void)
// {
//     const char* src = "0123456789";
//     char dst[] = "abcdef";
//     size_t res;

//     res = ft_strlcat(dst, src, 10);
//     printf("%zu,\n%s", res, dst);
//     return (0);
// }
