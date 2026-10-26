/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/26 17:29:19 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	return (0);
// }


#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int g_del_count = 0;

void test_del(void *content)
{
    g_del_count++;
    free(content);
}

t_list *new_node(char *str)
{
    char    *copy;
    t_list  *node;

    copy = strdup(str);
    if (!copy)
        return (NULL);
    node = ft_lstnew(copy);
    if (!node)
        free(copy);
    return (node);
}

void check(char *name, int condition)
{
    printf("  %s : %s\n", name, condition ? "OK" : "KO");
}

int main(void)
{
    t_list *lst;

    printf("\n========== TEST 1 : LISTE DE 3 ELEMENTS ==========\n");
    printf("Avant : [A] -> [B] -> [C] -> NULL\n");
    printf("Attendu :\n");
    printf("  - Les 3 contenus sont supprimes\n");
    printf("  - Les 3 maillons sont liberes\n");
    printf("  - del est appele exactement 3 fois\n");
    printf("  - lst devient NULL\n\n");

    g_del_count = 0;
    lst = new_node("A");
    lst->next = new_node("B");
    lst->next->next = new_node("C");

    ft_lstclear(&lst, test_del);

    printf("Resultats :\n");
    printf("  Appels de del : %d (attendu : 3)\n", g_del_count);
    printf("  lst : %p (attendu : NULL)\n", (void *)lst);
    check("Nombre d'appels de del", g_del_count == 3);
    check("Liste remise a NULL", lst == NULL);

    printf("\n========== TEST 2 : UN SEUL ELEMENT ==========\n");
    printf("Avant : [SEUL] -> NULL\n");
    printf("Attendu :\n");
    printf("  - Le contenu SEUL est supprime\n");
    printf("  - Le maillon est libere\n");
    printf("  - del est appele exactement 1 fois\n");
    printf("  - lst devient NULL\n\n");

    g_del_count = 0;
    lst = new_node("SEUL");

    ft_lstclear(&lst, test_del);

    printf("Resultats :\n");
    printf("  Appels de del : %d (attendu : 1)\n", g_del_count);
    printf("  lst : %p (attendu : NULL)\n", (void *)lst);
    check("Nombre d'appels de del", g_del_count == 1);
    check("Liste remise a NULL", lst == NULL);

    printf("\n========== TEST 3 : LISTE VIDE ==========\n");
    printf("Avant : lst -> NULL\n");
    printf("Attendu :\n");
    printf("  - Aucun element a supprimer\n");
    printf("  - del n'est jamais appele\n");
    printf("  - lst reste NULL\n");
    printf("  - Aucun crash\n\n");

    g_del_count = 0;
    lst = NULL;

    ft_lstclear(&lst, test_del);

    printf("Resultats :\n");
    printf("  Appels de del : %d (attendu : 0)\n", g_del_count);
    printf("  lst : %p (attendu : NULL)\n", (void *)lst);
    check("Aucun appel de del", g_del_count == 0);
    check("Liste toujours NULL", lst == NULL);

    printf("\n========== TEST 4 : POINTEUR NULL ==========\n");
    printf("Avant : lst n'existe pas (argument NULL)\n");
    printf("Attendu :\n");
    printf("  - La fonction ne doit pas dereferencer NULL\n");
    printf("  - del n'est jamais appele\n");
    printf("  - Aucun crash\n\n");

    g_del_count = 0;

    ft_lstclear(NULL, test_del);

    printf("Resultats :\n");
    printf("  Appels de del : %d (attendu : 0)\n", g_del_count);
    check("Aucun appel de del", g_del_count == 0);
    printf("  Aucun crash : OK\n");

    printf("\n========== TEST 5 : CONTENT NULL ==========\n");
    printf("Avant : [content = NULL] -> NULL\n");
    printf("Attendu :\n");
    printf("  - Le maillon existe meme si son contenu est NULL\n");
    printf("  - del est appele 1 fois avec NULL\n");
    printf("  - free(NULL) ne provoque pas de crash\n");
    printf("  - Le maillon est libere\n");
    printf("  - lst devient NULL\n\n");

    g_del_count = 0;
    lst = ft_lstnew(NULL);

    ft_lstclear(&lst, test_del);

    printf("Resultats :\n");
    printf("  Appels de del : %d (attendu : 1)\n", g_del_count);
    printf("  lst : %p (attendu : NULL)\n", (void *)lst);
    check("Nombre d'appels de del", g_del_count == 1);
    check("Liste remise a NULL", lst == NULL);

    printf("\n========== FIN DES TESTS ==========\n");
    printf("IMPORTANT : verifier aussi les fuites memoire avec ASan.\n");

    return (0);
}
