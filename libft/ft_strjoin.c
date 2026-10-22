/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:50:50 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 21:29:13 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	res = malloc (sizeof(char *) * (s1_len + s2_len));
	if (!res)
		return (NULL);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}

int	main(void)
{
	printf("%s\n", ft_strjoin("bonjour", "aurevoir"));
	return (0);
}
