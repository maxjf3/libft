/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:08:54 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 13:32:29 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_ptr;

	i = 0;
	big_ptr = (char *)big;
	if (!little)
		return (big_ptr);
	while (big_ptr[i] && i < len)
	{
		j = 0;
		while ((big_ptr[i + j] == little[j]) && (big_ptr[i + j]))
		{
			if (little[j + 1] == '\0')
				return (big_ptr + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s\n", ft_strnstr("aaabbbCOUCOUbbbaaa", "aa", 18));
// }