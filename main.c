/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjardin <mjardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/25 17:17:34 by mjardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int g_tests = 0;
static int g_ok = 0;
static int g_ko = 0;

static void    check(char *name, int success)
{
    g_tests++;
    if (success)
    {
        g_ok++;
        printf("\033[32m[OK]\033[0m %s\n", name);
    }
    else
    {
        g_ko++;
        printf("\033[31m[KO]\033[0m %s\n", name);
    }
}

/* TEST 1 : Liste vide */
static void test_empty_list(void)
{
    t_list *lst;
    t_list *new;

    printf("\n--- TEST LISTE VIDE ---\n");
    lst = NULL;
    new = ft_lstnew("A");
    if (!new)
    {
        check("Allocation du nouveau maillon", 0);
        return ;
    }
    ft_lstadd_front(&lst, new);
    check("Le debut pointe vers le nouveau maillon", lst == new);
    check("Le contenu est correct",
        lst && lst->content
        && strcmp((char *)lst->content, "A") == 0);
    check("Le suivant vaut NULL", lst && lst->next == NULL);
    free(new);
}

/* TEST 2 : Ajout devant un maillon */
static void test_one_node(void)
{
    t_list *lst;
    t_list *new;

    printf("\n--- TEST UN MAILLON ---\n");
    lst = ft_lstnew("B");
    new = ft_lstnew("A");
    if (!lst || !new)
    {
        check("Allocation des maillons", 0);
        free(lst);
        free(new);
        return ;
    }
    ft_lstadd_front(&lst, new);
    check("A devient le premier maillon",
        lst == new && lst->content
        && strcmp((char *)lst->content, "A") == 0);
    check("A pointe vers B",
        lst->next != NULL && lst->next->content
        && strcmp((char *)lst->next->content, "B") == 0);
    check("B termine la liste",
        lst->next != NULL && lst->next->next == NULL);
    free(new);
    free(lst);
}

/* TEST 3 : Ajout devant plusieurs maillons */
static void test_multiple_nodes(void)
{
    t_list *lst;
    t_list *new;

    printf("\n--- TEST PLUSIEURS MAILLONS ---\n");
    lst = ft_lstnew("C");
    if (!lst)
    {
        check("Allocation de C", 0);
        return ;
    }
    lst->next = ft_lstnew("D");
    new = ft_lstnew("B");
    if (!lst->next || !new)
    {
        check("Allocation des maillons", 0);
        free(lst->next);
        free(new);
        free(lst);
        return ;
    }
    ft_lstadd_front(&lst, new);
    check("B est le premier", lst == new);
    check("B pointe vers C",
        lst->next && lst->next->content
        && strcmp((char *)lst->next->content, "C") == 0);
    check("C pointe vers D",
        lst->next && lst->next->next
        && lst->next->next->content
        && strcmp((char *)lst->next->next->content, "D") == 0);
    check("D termine la liste",
        lst->next && lst->next->next
        && lst->next->next->next == NULL);
    free(new);
    free(lst->next->next);
    free(lst->next);
    free(lst);
}

/* TEST 4 : Contenu NULL */
static void test_null_content(void)
{
    t_list *lst;
    t_list *new;

    printf("\n--- TEST CONTENU NULL ---\n");
    lst = ft_lstnew("B");
    new = ft_lstnew(NULL);
    if (!lst || !new)
    {
        check("Allocation des maillons", 0);
        free(lst);
        free(new);
        return ;
    }
    ft_lstadd_front(&lst, new);
    check("Le nouveau maillon est en tete", lst == new);
    check("Son contenu est NULL", lst->content == NULL);
    check("L'ancien maillon est conserve",
        lst->next && lst->next->content
        && strcmp((char *)lst->next->content, "B") == 0);
    free(new);
    free(lst);
}

/* TEST 5 : Contenu entier */
static void test_integer(void)
{
    int a = 42;
    int b = 21;
    t_list *lst;
    t_list *new;

    printf("\n--- TEST ENTIERS ---\n");
    lst = ft_lstnew(&b);
    new = ft_lstnew(&a);
    if (!lst || !new)
    {
        check("Allocation des maillons", 0);
        free(lst);
        free(new);
        return ;
    }
    ft_lstadd_front(&lst, new);
    check("Le nouveau maillon est en tete", lst == new);
    check("La valeur 42 est conservee",
        *(int *)lst->content == 42);
    check("La valeur 21 est toujours accessible",
        lst->next && *(int *)lst->next->content == 21);
    free(new);
    free(lst);
}

/* TEST 6 : Plusieurs ajouts successifs */
static void test_successive_additions(void)
{
    t_list *lst;
    t_list *a;
    t_list *b;
    t_list *c;

    printf("\n--- TEST AJOUTS SUCCESSIFS ---\n");
    lst = NULL;
    a = ft_lstnew("A");
    b = ft_lstnew("B");
    c = ft_lstnew("C");
    if (!a || !b || !c)
    {
        check("Allocation des maillons", 0);
        free(a);
        free(b);
        free(c);
        return ;
    }
    ft_lstadd_front(&lst, a);
    ft_lstadd_front(&lst, b);
    ft_lstadd_front(&lst, c);
    check("C est en tete", lst == c);
    check("Ordre C -> B -> A",
        lst->next == b && b->next == a);
    check("A termine la liste", a->next == NULL);
    free(c);
    free(b);
    free(a);
}

int main(void)
{
    printf("======= TEST FT_LSTADD_FRONT =======\n");
    test_empty_list();
    test_one_node();
    test_multiple_nodes();
    test_null_content();
    test_integer();
    test_successive_additions();
    printf("\n======= RESULTATS =======\n");
    printf("Tests : %d\n", g_tests);
    printf("\033[32mOK : %d\033[0m\n", g_ok);
    printf("\033[31mKO : %d\033[0m\n", g_ko);
    return (g_ko != 0);
}
