/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:22:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 21:03:14 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc((sizeof(char *) * (len - start)));
	if (!ret)
		return (NULL);
	while (start < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	return (ret);
}

// int main(void)
// {
//     char *s = "Hello world!";
//     s = ft_substr(s, 6, strlen(s));
//     printf("%s\n", s);
//     free(s);
//     return (0);
// }