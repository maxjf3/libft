/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:30:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/23 14:38:31 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getsize(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n < 0)
	{
		res = malloc((sizeof(char) * ft_getsize(n * -1)) + 1);
		res[0] = '-';
	}
	else
		res = malloc(sizeof(char) * ft_getsize(n));
	if (!res)
		return (NULL);
	i = ft_getsize(n);
	while (i > 0)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (res);
}
