/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 08:23:18 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 15:13:07 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 0)
		return (0);
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

// int main(void)
// {
//     const char* src = "0123456789";
//     const char* src2 = "0123456789";
//     char dst[] = "abcdefghijklmnopdfkfl";
//     char dst2[] = "abcdefghijklmnopdfkfl";
//     size_t res;
//     size_t res2;

//     res = ft_strlcpy(dst, src, 100);
//     res2 = ft_strlcpy(dst2, src2, 100);

//     printf("%zu,\n%s\n", res, dst);
//     printf("%zu,\n%s\n", res2, dst2);
//     return (0);
// }

#include <stdio.h>
#include <string.h>
#include <stddef.h>

#ifdef __linux__
# include <bsd/string.h>   /* compiler avec -lbsd */
#endif

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// Remplace par ft_strlcpy pour tester ton code
#define TEST_FUNC strlcpy

// Buffer de 10 octets rempli avec le caractere c (sans '\0')
#define RESET(c) memset(buf, c, 10)
// Compare les 10 octets du buffer avec l'etat attendu (detecte les ecritures en trop)
#define MEM(expected) (memcmp(buf, expected, 10) == 0)

int main(void)
{
    char buf[10];
    size_t ret;

    // Test 1 : copie basique, place suffisante
    RESET('X');
    ret = TEST_FUNC(buf, "chat", 10);
    printf("Test 1 (basique) -> Ret == 4 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 4, MEM("chat\0XXXXX"), buf);

    // Test 2 : ajustement exact (size = slen + 1)
    RESET('X');
    ret = TEST_FUNC(buf, "chat", 5);
    printf("Test 2 (exact fit) -> Ret == 4 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 4, MEM("chat\0XXXXX"), buf);

    // Test 3 : troncature (size = 3 -> 2 chars + '\0')
    RESET('X');
    ret = TEST_FUNC(buf, "chat", 3);
    printf("Test 3 (troncature size=3) -> Ret == 4 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 4, MEM("ch\0XXXXXXX"), buf);

    // Test 4 : size = 1 (ecrit seulement le '\0')
    RESET('X');
    ret = TEST_FUNC(buf, "chat", 1);
    printf("Test 4 (size=1) -> Ret == 4 : %d | Mem OK : %d | Result : \"%.10s\"\n",
        ret == 4, MEM("\0XXXXXXXXX"), buf);

    // Test 5 : size = 0 (ne doit RIEN ecrire, pas meme le '\0')
    RESET('X');
    ret = TEST_FUNC(buf, "chat", 0);
    printf("Test 5 (size=0) -> Ret == 4 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 4, MEM("XXXXXXXXXX"), buf);

    // Test 6 : src vide
    RESET('X');
    ret = TEST_FUNC(buf, "", 10);
    printf("Test 6 (src vide) -> Ret == 0 : %d | Mem OK : %d | Result : \"%.10s\"\n",
        ret == 0, MEM("\0XXXXXXXXX"), buf);

    // Test 7 : src vide et size = 0
    RESET('X');
    ret = TEST_FUNC(buf, "", 0);
    printf("Test 7 (src vide, size=0) -> Ret == 0 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 0, MEM("XXXXXXXXXX"), buf);

    // Test 8 : src plus longue que le buffer (ret = strlen(src) = 16)
    RESET('X');
    ret = TEST_FUNC(buf, "bonjour le monde", 10);
    printf("Test 8 (src > buffer) -> Ret == 16 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 16, MEM("bonjour l\0"), buf);

    // Test 9 : size = slen + 1 (juste assez de place)
    RESET('X');
    ret = TEST_FUNC(buf, "bonjour", 8);
    printf("Test 9 (size=slen+1) -> Ret == 7 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 7, MEM("bonjour\0XX"), buf);

    // Test 10 : size = slen (un caractere tronque)
    RESET('X');
    ret = TEST_FUNC(buf, "bonjour", 7);
    printf("Test 10 (size=slen) -> Ret == 7 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 7, MEM("bonjou\0XXX"), buf);

    // Test 11 : '\0' au milieu de src (copie s'arrete au '\0')
    RESET('X');
    ret = TEST_FUNC(buf, "ab\0cd", 10);
    printf("Test 11 (\\0 dans src) -> Ret == 2 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 2, MEM("ab\0XXXXXXX"), buf);

    // Test 12 : ecrase l'ancien contenu (ce n'est PAS une concatenation)
    RESET('z');
    ret = TEST_FUNC(buf, "ab", 10);
    printf("Test 12 (ecrase dst) -> Ret == 2 : %d | Mem OK : %d | Result : %.10s\n",
        ret == 2, MEM("ab\0zzzzzzz"), buf);

    return (0);
}