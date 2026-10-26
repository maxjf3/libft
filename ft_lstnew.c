/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:47:35 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/26 01:03:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!content)
	{
		new = malloc(sizeof(t_list));
		return (new);
	}
	new = ft_calloc(sizeof(t_list), ft_strlen(content));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
