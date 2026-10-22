/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:47:24 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 15:20:06 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		res_index;
	int		i;
	int		s1_index;

	i = 0;
	s1_index = 0;
	res_index = 0;
	res = malloc(sizeof(char) * ft_strlen(s1));
	if (!res)
		return (NULL);
	while (s1[s1_index])
	{
		if (set[i] == s1[s1_index])
			i++;
		else
		{
			res[res_index] = s1[s1_index];
			s1_index++;
			res_index++;
			i++;
		}
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char *s1 = "aaabbbCOUCOUbbbaaa";

	s1 = ft_strtrim(s1, "aaabbb");
	printf("%s\n", s1);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
 
// char	*ft_strtrim(char const *s1, char const *set);
 
// // strtrim n'existe pas dans la libc : on teste directement ft_strtrim
// #define TEST_FUNC ft_strtrim
 
// // Verifie ret (non NULL, egal a expected) puis le libere
// static void check(int n, const char *desc, char *ret, const char *expected)
// {
//     printf("Test %d (%s) -> Ret != NULL : %d | strcmp == 0 : %d | Result : \"%s\"\n",
//         n, desc, ret != NULL, ret && strcmp(ret, expected) == 0,
//         ret ? ret : "(null)");
//     free(ret);
// }
 
// int main(void)
// {
//     char *ret;
//     char orig[] = "hello";
//     char big[203];
 
//     // Test 1 : espaces des deux cotes
//     check(1, "espaces des 2 cotes", TEST_FUNC("  hello  ", " "), "hello");
 
//     // Test 2 : rien a retirer
//     check(2, "rien a retirer", TEST_FUNC("hello", " "), "hello");
 
//     // Test 3 : seulement au debut
//     check(3, "debut seulement", TEST_FUNC("xxhello", "x"), "hello");
 
//     // Test 4 : seulement a la fin
//     check(4, "fin seulement", TEST_FUNC("helloxx", "x"), "hello");
 
//     // Test 5 : des deux cotes
//     check(5, "debut et fin", TEST_FUNC("xxhelloxx", "x"), "hello");
 
//     // Test 6 : plusieurs caracteres dans set (l'ordre n'importe pas)
//     check(6, "set = abc", TEST_FUNC("abcHELLOcba", "abc"), "HELLO");
 
//     // Test 7 : les caracteres du milieu sont conserves
//     check(7, "milieu conserve", TEST_FUNC("  he llo  ", " "), "he llo");
 
//     // Test 8 : tout est retire (chaine vide allouee, pas NULL)
//     check(8, "tout retire", TEST_FUNC("xxxx", "x"), "");
 
//     // Test 9 : s1 vide
//     check(9, "s1 vide", TEST_FUNC("", "x"), "");
 
//     // Test 10 : set vide (rien a retirer)
//     check(10, "set vide", TEST_FUNC("hello", ""), "hello");
 
//     // Test 11 : set char aussi present au milieu (seuls les bords sont retires)
//     check(11, "x au milieu", TEST_FUNC("xhxex", "x"), "hxe");
 
//     // Test 12 : tout est retire avec plusieurs chars dans set
//     check(12, "tout retire (set = ab)", TEST_FUNC("abab", "ab"), "");
 
//     // Test 13 : whitespaces varies
//     check(13, "whitespaces", TEST_FUNC("\t\n hello \n\t", " \t\n"), "hello");
 
//     // Test 14 : retire seulement ce qui est dans set ('h' et 'o' ne sont pas dans set)
//     check(14, "autres chars gardes", TEST_FUNC("  hello  ", " h"), "ello");
 
//     // Test 15 : longue chaine (100 espaces + 'a' + 100 espaces)
//     memset(big, ' ', 201);
//     big[100] = 'a';
//     big[201] = '\0';
//     check(15, "100 espaces + a + 100 espaces", TEST_FUNC(big, " "), "a");
 
//     // Test 16 : rien a retirer -> doit retourner une COPIE, pas s1 lui-meme
//     ret = TEST_FUNC(orig, "x");
//     printf("Test 16 (nouvelle zone) -> Ret != s1 : %d | strcmp == 0 : %d | s1 intact : %d\n",
//         ret != orig, ret && strcmp(ret, "hello") == 0, strcmp(orig, "hello") == 0);
//     free(ret);
 
//     // Test 17 : s1 = NULL (comportement defensif, optionnel selon ton sujet)
//     ret = TEST_FUNC(NULL, " ");
//     printf("Test 17 (s1 = NULL, optionnel) -> Ret == NULL : %d\n", ret == NULL);
//     free(ret);
 
//     return (0);
// }