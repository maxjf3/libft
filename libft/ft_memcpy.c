/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:38:56 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:37:32 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	size_t			i;

	dest_ptr = dest;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = ((unsigned char *) src)[i];
		i++;
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

//     ft_memcpy(test + 1, test, 5);
//     memcpy(test2 + 1, test2, 5);

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