/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:48:56 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 18:33:09 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmemb_m;

	nmemb_m = malloc(nmemb * size);
	if (!nmemb_m)
		return (NULL);
	ft_bzero(nmemb_m, size);
	return (nmemb_m);
}
