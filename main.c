/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/24 16:59:29 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Ta fonction */
char *ft_itoa(int n);

/* Fonction de comparaison */
static int test_itoa(int n)
{
    char expected[12];
    char *result;

    snprintf(expected, sizeof(expected), "%d", n);
    result = ft_itoa(n);

    if (!result)
    {
        printf("FAIL | n = %d | ft_itoa retourne NULL\n", n);
        return (1);
    }

    if (strcmp(result, expected) != 0)
    {
        printf("FAIL | n = %d | attendu = \"%s\" | obtenu = \"%s\"\n",
            n, expected, result);
        free(result);
        return (1);
    }

    printf("OK   | n = %d | \"%s\"\n", n, result);
    free(result);
    return (0);
}

int main(void)
{
    int failures = 0;
    int tests[] = {
        0,
        1,
        -1,
        42,
        -42,
        9,
        10,
        99,
        100,
        -100,
        12345,
        -12345,
        INT_MAX,
        INT_MIN
    };
    size_t i;

    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
        failures += test_itoa(tests[i]);

    printf("\nRésultat : %zu tests, %d échec(s)\n",
        sizeof(tests) / sizeof(tests[0]), failures);

    return (failures != 0);
}

