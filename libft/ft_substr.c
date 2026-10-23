/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:22:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 18:35:39 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
