/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:24:10 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 17:10:42 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

// int main() {

//     int array [] = { 540, 805, 20, 63, 21 };
//     int array2 [] = { 540, 805, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int length;

//     /* Display the initial values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n\n");
//     for( length=0; length<5; length++) {
//         printf( "%d ", array2[ length ] );
//     }
//     printf( "\n" );

//     /* Reset the memory bloc */
//     ft_bzero( array, size );
//     bzero(array2, size);

//     /* Display the new values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "\n\n" );
//     for( length=0; length<5; length++) {
//         printf( "%d ", array2[ length ] );
//     }
//     printf( "\n" );

//     return 0;
// }