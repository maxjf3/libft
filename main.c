/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/26 14:34:22 by mjardin          ###   ########.fr       */
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

static int total = 0;
static int passed = 0;

static void result(char *name, int ok)
{
    total++;
    if (ok)
    {
        passed++;
        printf("\033[32m[PASS]\033[0m %s\n", name);
    }
    else
        printf("\033[31m[FAIL]\033[0m %s\n", name);
}

static void test_empty_list(void)
{
    t_list *lst = NULL;
    t_list *node = ft_lstnew("42");

    if (!node)
    {
        result("Ajout dans une liste vide", 0);
        return;
    }
    ft_lstadd_back(&lst, node);
    result("Liste vide: premier element ajoute", lst == node);
    result("Liste vide: next vaut NULL", lst->next == NULL);
    result("Liste vide: contenu correct",
        strcmp((char *)lst->content, "42") == 0);
    free(node);
}

static void test_one_element(void)
{
    t_list *lst = ft_lstnew("A");
    t_list *node = ft_lstnew("B");

    if (!lst || !node)
    {
        free(lst);
        free(node);
        result("Ajout apres un element", 0);
        return;
    }
    ft_lstadd_back(&lst, node);
    result("Un element: le nouveau est en deuxieme position",
        lst->next == node);
    result("Un element: dernier next vaut NULL",
        node->next == NULL);
    result("Un element: ancien contenu conserve",
        strcmp((char *)lst->content, "A") == 0);
    free(node);
    free(lst);
}

static void test_multiple_elements(void)
{
    t_list *lst = ft_lstnew("A");
    t_list *b = ft_lstnew("B");
    t_list *c = ft_lstnew("C");

    if (!lst || !b || !c)
    {
        free(lst);
        free(b);
        free(c);
        result("Ajout dans une liste multiple", 0);
        return;
    }
    ft_lstadd_back(&lst, b);
    ft_lstadd_back(&lst, c);
    result("Multiple: ordre A -> B -> C",
        lst->next == b && b->next == c);
    result("Multiple: dernier next vaut NULL",
        c->next == NULL);
    free(c);
    free(b);
    free(lst);
}

int main(void)
{
    printf("\n=== TESTS FT_LSTADD_BACK ===\n\n");
    test_empty_list();
    test_one_element();
    test_multiple_elements();
    printf("\n===========================\n");
    printf("RESULTAT: %d/%d tests reussis\n", passed, total);
    if (passed == total)
        printf("\033[32mTOUT EST OK !\033[0m\n");
    else
        printf("\033[31mIL Y A DES ERREURS !\033[0m\n");
    return (passed != total);
}
