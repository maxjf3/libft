/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/23 21:33:26 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	char **res;

	i = 0;
	res = ft_split("Bonjour comment ca va ?", ' ');
	while (i < 5)
	{
		printf("%s", res[i]);
		printf("\n");
		i++;
	}
	
	return (0);
}
