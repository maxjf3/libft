/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 20:50:12 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/21 20:50:57 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char* str = "Bonjour";
//     printf("%s\n", ft_strchr(str, 'o'));
//     return (0);
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//
//     const char * source = "The C Language";
//     char * destination;
//     char * pointer;
//     int length = strlen( source );
//  
//     /* We clone the inital string */
//     destination = (char *) malloc( sizeof( char) * (length+1) );
//     strcpy( destination, source );

//     /* We replace all 'a' characters */
//     while ((pointer = ft_strchr( destination, 'a' )) ) {
//         *pointer = 'A';
//     }

//     /* Display result : The C LAnguAge */
//     printf( "Result : %s\n", destination );

//     /* Release dynamicly allocated memory */
//     free( destination );

//     return 0;
// }