/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:31:32 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 15:11:53 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while ((s1_ptr[i] || s2_ptr[i]) && i < n)
	{
		if (s1_ptr[i] - s2_ptr[i] != 0)
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	const char* s1 = "Bonjour";
// 	const char* s2 = "Bonjourr";

// 	printf("%d\n", ft_memcmp(s1, s2, 8));
// 	printf("%d\n", memcmp(s1, s2, 8));
// 	return (0);
// }

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

// Remplace par ft_memcmp pour tester ton code
#define TEST_FUNC memcmp

int main(void)
{
    int ret;
    const char *s = "bonjour";
    unsigned char a[] = {1, 2, 3};
    unsigned char b[] = {1, 2, 4};
    unsigned char c[] = {0x00, 0x80};
    unsigned char d[] = {0x80, 0x00};

    // Test 1 : zones identiques
    ret = TEST_FUNC("hello", "hello", 5);
    printf("Test 1 (identiques) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    // Test 2 : s1 < s2 ('c' - 'd' = -1)
    ret = TEST_FUNC("abc", "abd", 3);
    printf("Test 2 (s1 < s2) -> Ret == -1 : %d | ret = %d\n", ret == -1, ret);

    // Test 3 : s1 > s2 ('d' - 'c' = 1)
    ret = TEST_FUNC("abd", "abc", 3);
    printf("Test 3 (s1 > s2) -> Ret == 1 : %d | ret = %d\n", ret == 1, ret);

    // Test 4 : n = 0 (retourne 0 meme si les zones different)
    ret = TEST_FUNC("abc", "xyz", 0);
    printf("Test 4 (n=0) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    // Test 5 : n s'arrete avant la difference
    ret = TEST_FUNC("abcdef", "abcxyz", 3);
    printf("Test 5 (n avant la diff) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    // Test 6 : n inclut la difference ('d' - 'x' = 100 - 120 = -20)
    ret = TEST_FUNC("abcdef", "abcxyz", 4);
    printf("Test 6 (n sur la diff) -> Ret == -20 : %d | ret = %d\n", ret == -20, ret);

    // Test 7 : ne s'arrete PAS au '\0' ('d' - 'x' = -20 apres le \0)
    ret = TEST_FUNC("abc\0def", "abc\0xyz", 7);
    printf("Test 7 (apres le \\0) -> Ret == -20 : %d | ret = %d\n", ret == -20, ret);

    // Test 8 : le '\0' est compare comme un octet normal ('\0' - 'd' = -100)
    ret = TEST_FUNC("abc", "abcd", 4);
    printf("Test 8 ('\\0' vs 'd') -> Ret == -100 : %d | ret = %d\n", ret == -100, ret);

    // Test 9 : unsigned char (255 - 97 = 158)
    ret = TEST_FUNC("\xff", "a", 1);
    printf("Test 9 (unsigned char) -> Ret == 158 : %d | ret = %d\n", ret == 158, ret);

    // Test 10 : octets 0x00 vs 0x80 (0 - 128 = -128)
    ret = TEST_FUNC(c, d, 1);
    printf("Test 10 (0x00 vs 0x80) -> Ret == -128 : %d | ret = %d\n", ret == -128, ret);

    // Test 11 : tableaux binaires (3 - 4 = -1)
    ret = TEST_FUNC(a, b, 3);
    printf("Test 11 (binaire) -> Ret == -1 : %d | ret = %d\n", ret == -1, ret);

    // Test 12 : n = 1, premier octet egal
    ret = TEST_FUNC("abc", "axc", 1);
    printf("Test 12 (n=1, egal) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    // Test 13 : deux chaines vides (compare le '\0')
    ret = TEST_FUNC("", "", 1);
    printf("Test 13 (vides, n=1) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    // Test 14 : meme pointeur des deux cotes
    ret = TEST_FUNC(s, s, 7);
    printf("Test 14 (meme pointeur) -> Ret == 0 : %d | ret = %d\n", ret == 0, ret);

    return (0);
}
