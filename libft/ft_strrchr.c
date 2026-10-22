/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:01:55 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 13:32:11 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int main(void)
// {
//     const char* str = "Bonjour";
//     printf("%s\n", ft_strrchr(str, 'o'));
//     return (0);
// }