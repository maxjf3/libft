/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:30:15 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/22 16:27:34 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_getNbSize(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n < 0)
	{
		res = malloc((sizeof(char) * ft_getNbSize(n *- 1)) + 1);
		res[0] = '-';
	}
	else
		res = malloc(sizeof(char) * ft_getNbSize(n));
	if (!res)
		return (NULL);
	i = ft_getNbSize(n);
	while (i > 0)
	{
		res[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

#include <stdio.h>

// int main(void)
// {
// 	printf("%s\n", ft_itoa(1234));
// 	return (0);
// }

#include <string.h>

// Fonction utilitaire pour vérifier les résultats
void test_itoa(int test_num, int input, const char *expected)
{
    char *result = ft_itoa(input);

    if (result == NULL)
    {
        printf("❌ Test %02d ÉCHOUÉ : Résultat NULL pour l'entrée %d (Attendu : \"%s\")\n", test_num, input, expected);
        return;
    }
    if (strcmp(result, expected) == 0)
    {
        printf("✅ Test %02d RÉUSSI : ft_itoa(%d) = \"%s\"\n", test_num, input, result);
    }
    else
    {
        printf("❌ Test %02d ÉCHOUÉ : ft_itoa(%d) = \"%s\" (Attendu : \"%s\")\n", test_num, input, result, expected);
    }
    free(result); // Libération obligatoire de la mémoire allouée
}

int main(void)
{
    printf("--- DÉBUT DES TESTS FT_ITOA ---\n\n");

    // --- CAS DE BASE ---
    test_itoa(1, 0, "0");
    test_itoa(2, 7, "7");
    test_itoa(3, -5, "-5");

    // --- NOMBRES À PLUSIEURS CHIFFRES ---
    test_itoa(4, 42, "42");
    test_itoa(5, -42, "-42");
    test_itoa(6, 100, "100");
    test_itoa(7, -100, "-100");
    test_itoa(8, 123456, "123456");
    test_itoa(9, -123456, "-123456");

    // --- VALEURS AUX LIMITES (INT_MAX & INT_MIN) ---
    test_itoa(10, 2147483647, "2147483647");   // INT_MAX
    test_itoa(11, -2147483648, "-2147483648"); // INT_MIN (Le piège classique)

    // --- AUTRES CAS PARTICULIERS ---
    test_itoa(12, 100000000, "100000000");
    test_itoa(13, -100000000, "-100000000");
    test_itoa(14, 2000000000, "2000000000");

    printf("\n--- FIN DES TESTS ---\n");
    return (0);
}