/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:06:34 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 17:12:15 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif