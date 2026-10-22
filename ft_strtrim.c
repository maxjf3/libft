/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:47:24 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 08:40:39 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

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

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char*) * ft_strlen(s1));
	if (ft_strnstr(s1, set, ft_strlen(s1)) != NULL)
	{
		while (set[i])
		{
			res = ft_strchr(s1 + i, set[i]);
			i++;
		}
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char *s1 = "aaabbbCOUCOUbbbaaa";

	s1 = ft_strtrim("aaabbbCOUCOUbbbaaa", "aaabbb");
	printf("%s\n", s1);
	return (0);
}