/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:57:32 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:45:37 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int main() {

//     int array [] = { 54, 85, 20, 63, 21 };
//     int array2 [] = { 54, 85, 20, 63, 21 };
//     size_t size = sizeof( int ) * 5;
//     int length;

//     /* Display the initial values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "Array2 \n");
//     for( length=0; length<5; length++) {
//         printf( "%d ", array2[ length ] );
//     }
//     printf( "\n" );

//     /* Reset the memory bloc */
//     ft_memset( array, 10, size );
//     memset(array2, 10, size);

//     /* Display the new values */
//     for( length=0; length<5; length++) {
//         printf( "%d ", array[ length ] );
//     }
//     printf( "Array2 \n" );
//     for( length=0; length<5; length++) {
//         printf( "%d ", array2[ length ] );
//     }
//     printf( "\n" );
// 
//     return 0;
// }