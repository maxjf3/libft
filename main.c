/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 17:11:07 by mjardin           #+#    #+#             */
/*   Updated: 2026/10/26 01:17:11 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	g_passed = 0;
static int	g_failed = 0;

static void	check(int condition, const char *name)
{
	if (condition)
	{
		printf("\033[32m[OK]\033[0m %s\n", name);
		g_passed++;
	}
	else
	{
		printf("\033[31m[KO]\033[0m %s\n", name);
		g_failed++;
	}
}

static int	has_cycle(t_list *head)
{
	t_list	*slow;
	t_list	*fast;

	slow = head;
	fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}

static void	test_empty_list(void)
{
	t_list	*head = NULL;
	t_list	a = {"Hello", NULL};

	ft_lstadd_back(&head, &a);
	check(head == &a,
		"01 - Liste vide : nouvelle tete correcte");
	check(a.next == NULL,
		"02 - Liste vide : next reste NULL");
}

static void	test_one_node(void)
{
	t_list	a = {"A", NULL};
	t_list	b = {"B", NULL};
	t_list	*head = &a;

	ft_lstadd_back(&head, &b);
	check(head == &a,
		"03 - La tete reste inchangee");
	check(a.next == &b,
		"04 - Nouveau maillon ajoute apres A");
	check(b.next == NULL,
		"05 - Nouveau maillon termine la liste");
}

static void	test_three_nodes(void)
{
	t_list	c = {"C", NULL};
	t_list	b = {"B", &c};
	t_list	a = {"A", &b};
	t_list	d = {"D", NULL};
	t_list	*head = &a;

	ft_lstadd_back(&head, &d);
	check(head == &a,
		"06 - Liste de 3 : tete preservee");
	check(a.next == &b && b.next == &c
		&& c.next == &d && d.next == NULL,
		"07 - Ordre A -> B -> C -> D");
	check(!has_cycle(head),
		"08 - Aucun cycle cree");
}

static void	test_multiple_insertions(void)
{
	t_list	a = {"A", NULL};
	t_list	b = {"B", NULL};
	t_list	c = {"C", NULL};
	t_list	*head = NULL;

	ft_lstadd_back(&head, &a);
	ft_lstadd_back(&head, &b);
	ft_lstadd_back(&head, &c);

	check(head == &a,
		"09 - Trois insertions : tete correcte");
	check(a.next == &b && b.next == &c
		&& c.next == NULL,
		"10 - Ordre des insertions respecte");
}

static void	test_null_content(void)
{
	t_list	a = {NULL, NULL};
	t_list	b = {NULL, NULL};
	t_list	*head = &a;

	ft_lstadd_back(&head, &b);
	check(head == &a && a.next == &b,
		"11 - Maillons avec content NULL");
	check(a.content == NULL && b.content == NULL,
		"12 - Contenus NULL preserves");
}

static void	test_pointer_identity(void)
{
	int		x = 42;
	int		y = 1337;
	t_list	a = {&x, NULL};
	t_list	b = {&y, NULL};
	t_list	*head = &a;

	ft_lstadd_back(&head, &b);
	check(head == &a && a.next == &b,
		"13 - Adresses des maillons preservees");
	check(a.content == &x && b.content == &y,
		"14 - Pointeurs content preserves");
	check(x == 42 && y == 1337,
		"15 - Valeurs originales intactes");
}

static void	test_existing_next(void)
{
	t_list	a = {"A", NULL};
	t_list	extra = {"EXTRA", NULL};
	t_list	b = {"B", &extra};
	t_list	*head = &a;

	ft_lstadd_back(&head, &b);
	check(a.next == &b,
		"16 - Nouveau maillon correctement ajoute");
	check(b.next == &extra,
		"17 - Le next du nouveau maillon est preserve");
	check(extra.next == NULL && !has_cycle(head),
		"18 - Chaine ajoutee sans cycle");
}

static void	test_long_list(void)
{
	t_list	*nodes;
	t_list	extra = {"EXTRA", NULL};
	t_list	*head;
	int		i;
	int		ok;

	nodes = malloc(sizeof(t_list) * 100000);
	if (!nodes)
	{
		printf("[SKIP] Allocation impossible\n");
		return ;
	}
	i = 0;
	while (i < 100000)
	{
		nodes[i].content = NULL;
		nodes[i].next = NULL;
		if (i > 0)
			nodes[i - 1].next = &nodes[i];
		i++;
	}
	head = &nodes[0];
	ft_lstadd_back(&head, &extra);
	ok = (head == &nodes[0]
			&& nodes[99999].next == &extra
			&& extra.next == NULL);
	check(ok, "19 - Insertion sur 100000 maillons");
	free(nodes);
}

static void	test_real_content(void)
{
	char	text[] = "libft";
	t_list	a = {text, NULL};
	t_list	b = {"42", NULL};
	t_list	*head = &a;

	ft_lstadd_back(&head, &b);
	check(head == &a && a.content == text
		&& strcmp((char *)a.content, "libft") == 0
		&& b.content == (void *)"42",
		"20 - Contenus reels non modifies");
}

int	main(void)
{
	printf("\n=== TESTS FT_LSTADD_BACK ===\n\n");

	test_empty_list();
	test_one_node();
	test_three_nodes();
	test_multiple_insertions();
	test_null_content();
	test_pointer_identity();
	test_existing_next();
	test_long_list();
	test_real_content();

	printf("\n=== RESULTATS ===\n");
	printf("Tests reussis : %d\n", g_passed);
	printf("Tests echoues : %d\n", g_failed);
	printf("Tests executes : %d/20\n\n",
		g_passed + g_failed);

	return (g_failed != 0);
}
