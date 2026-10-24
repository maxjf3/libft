/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:48:56 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 13:56:58 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmemb_m;
	size_t	final_size;

	if (nmemb <= 0 || size <= 0)
	{
		nmemb_m = malloc(1);
		return (nmemb_m);
	}
	if (nmemb >= SIZE_MAX / size)
		return (NULL);
	final_size = nmemb * size;
	if (final_size > SIZE_MAX)
		return (NULL);
	nmemb_m = malloc(final_size);
	if (!nmemb_m)
		return (NULL);
	ft_bzero(nmemb_m, final_size);
	return (nmemb_m);
}
