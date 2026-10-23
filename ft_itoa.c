/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:30:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 00:59:16 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_getsize(long n)
{
	long	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	n_long;

	n_long = (long)n; 
	if (n_long < 0)
	{
		n_long = -n_long;
		res = ft_calloc(ft_getsize(n_long) + 1, (sizeof(char)));
		res[0] = '-';
		n_long = -n_long;
	}
	else
		res = ft_calloc(ft_getsize(n_long) + 1, (sizeof(char)));
	if (!res)
		return (NULL);
	if (n_long < 0)
	{
		n_long = -n_long;
		i = ft_getsize(n_long);
		while (i > 0)
		{
			res[i] = (n_long % 10) + '0';
			n_long /= 10;
			i--;
		}
	}
	else
	{
		i = ft_getsize(n_long) - 1;
		while (i >= 0)
		{
			res[i] = (n_long % 10) + '0';
			n_long /= 10;
			i--;
		}
	}
	return (res);
}
