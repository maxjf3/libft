/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:48:56 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 03:35:56 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmemb_m;
	size_t	final_size;

	final_size = nmemb * size;
	nmemb_m = malloc(final_size);
	if (!nmemb_m)
		return (NULL);
	ft_bzero(nmemb_m, final_size);
	return (nmemb_m);
}
