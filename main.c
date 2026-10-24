/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 03:16:30 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include <stdio.h>
#include <string.h>
#include "libft.h"

static void	test_strncmp(char *s1, char *s2, size_t n, char *name)
{
	int	real;
	int	mine;

	real = strncmp(s1, s2, n);
	mine = ft_strncmp(s1, s2, n);
	if ((real == 0 && mine == 0)
		|| (real < 0 && mine < 0)
		|| (real > 0 && mine > 0))
		printf("[OK]   %s\n", name);
	else
		printf("[FAIL] %s | strncmp: %d | ft_strncmp: %d\n",
			name, real, mine);
}

int	main(void)
{
	printf("=== TESTS FT_STRNCMP ===\n\n");

	test_strncmp("hello", "hello", 5, "Chaines identiques");
	test_strncmp("hello", "world", 5, "Chaines differentes");
	test_strncmp("abc", "abd", 3, "Difference au dernier caractere");
	test_strncmp("abc", "abcd", 4, "Premiere chaine plus courte");
	test_strncmp("abcd", "abc", 4, "Deuxieme chaine plus courte");
	test_strncmp("hello", "world", 0, "n egal a zero");
	test_strncmp("abc", "abd", 2, "Difference apres n");
	test_strncmp("", "", 5, "Deux chaines vides");
	test_strncmp("", "abc", 3, "Premiere chaine vide");
	test_strncmp("abc", "", 3, "Deuxieme chaine vide");
	test_strncmp("42", "42", 2, "Chiffres identiques");
	test_strncmp("abc", "ABC", 3, "Difference majuscules/minuscules");
	test_strncmp("abc", "abc", 7, "abc");

	return (0);
}
