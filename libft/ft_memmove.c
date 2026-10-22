/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:33:22 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:44:08 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	i = 0;
	if (dest_ptr > src_ptr)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_ptr[i] = src_ptr[i];
		}
	}
	else
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
//     int test[5] = {1, 2, 3, 4, 5};
//     int test2[5] = {1, 2, 3, 4, 5};

//     printf("Avant:\nMoi:  ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", test[i]);
//     }
//     printf("\nVrai: ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", test2[i]);
//     }
//     printf("\n");

//     ft_memmove(test, test + 2, 5);
//     memmove(test2, test2 + 2, 5);

//     printf("Apres:\nMoi:  ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", test[i]);
//     }
//     printf("\nVrai: ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", test2[i]);
//     }
//     printf("\n");
//     return (0);
// }