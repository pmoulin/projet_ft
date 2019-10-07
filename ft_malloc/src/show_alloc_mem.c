/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:54 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:57 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** display addr to bloc passed in parameter and return size of bloc
*/

static size_t	print_mem(t_bloc *bloc)
{
	print_addr(bloc);
	malloc_putstr(" - ");
	print_addr(bloc->next);
	malloc_putstr(" : ");
	print_size(bloc->size);
	malloc_putstr(" octets");
	return (bloc->size);
}

/*
** size_t size : size of bloc (tiny)
** display all addr + size of the bloc allocate
** return += size of zone and  other zone/bloc displaying
*/

static size_t	show_tiny(size_t size)
{
	g_env_m.z_tiny = go_first_maillon(NULL, g_env_m.z_tiny);
	while (g_env_m.z_tiny)
	{
		malloc_putstr("TINY : ");
		print_addr((void *)g_env_m.z_tiny);
		malloc_putchar('\n');
		g_env_m.z_tiny->bloc = go_first_maillon(g_env_m.z_tiny->bloc, NULL);
		while (g_env_m.z_tiny->bloc)
		{
			if (g_env_m.z_tiny->bloc->status == 1)
				size += print_mem(g_env_m.z_tiny->bloc);
			if (!g_env_m.z_tiny->bloc->next)
			{
				g_env_m.z_tiny->bloc = go_first_maillon(g_env_m.z_tiny->bloc,
					NULL);
				break ;
			}
			g_env_m.z_tiny->bloc = g_env_m.z_tiny->bloc->next;
		}
		if (!g_env_m.z_tiny->next)
			break ;
		g_env_m.z_tiny = g_env_m.z_tiny->next;
	}
	g_env_m.z_tiny = go_first_maillon(NULL, g_env_m.z_tiny);
	return (size);
}

/*
** size_t size : size of bloc (small)
** display all addr + size of the bloc allocate
** return += size of zone and  other zone/bloc displaying
*/

static size_t	show_small(size_t size)
{
	g_env_m.z_small = go_first_maillon(NULL, g_env_m.z_small);
	while (g_env_m.z_small)
	{
		malloc_putstr("SMALL : ");
		print_addr((void *)g_env_m.z_small);
		malloc_putchar('\n');
		g_env_m.z_small->bloc = go_first_maillon(g_env_m.z_small->bloc, NULL);
		while (g_env_m.z_small->bloc)
		{
			if (g_env_m.z_small->bloc->status == 1)
				size += print_mem(g_env_m.z_small->bloc);
			if (!g_env_m.z_small->bloc->next)
			{
				g_env_m.z_small->bloc = go_first_maillon(g_env_m.z_small->bloc,
					NULL);
				break ;
			}
			g_env_m.z_small->bloc = g_env_m.z_small->bloc->next;
		}
		if (!g_env_m.z_small->next)
			break ;
		g_env_m.z_small = g_env_m.z_small->next;
	}
	g_env_m.z_small = go_first_maillon(NULL, g_env_m.z_small);
	return (size);
}

/*
** size_t size : size of zone (large)
** print all addr + size of the zone allocate
** return += size of zone and  other zone/bloc displaying
*/

static size_t	show_large(size_t size)
{
	while (g_env_m.z_large)
	{
		malloc_putstr("LARGE : ");
		print_addr((void *)g_env_m.z_large);
		malloc_putchar('\n');
		print_addr((void *)g_env_m.z_large + ZONE_HEADER);
		malloc_putstr(" - ");
		print_addr((void *)(g_env_m.z_large + ZONE_HEADER)
			+ g_env_m.z_large->size);
		malloc_putstr(" : ");
		print_size(g_env_m.z_large->size);
		malloc_putstr(" octets");
		malloc_putchar('\n');
		size += g_env_m.z_large->size;
		if (!g_env_m.z_large->next)
			break ;
		g_env_m.z_large = g_env_m.z_large->next;
	}
	g_env_m.z_large = go_first_maillon(NULL, g_env_m.z_large);
	return (size);
}

void			show_alloc_mem(void)
{
	size_t size;

	size = 0;
	if (g_env_m.z_tiny)
		size += show_tiny(size);
	if (g_env_m.z_small)
		size += show_small(size);
	if (g_env_m.z_large)
		size += show_large(size);
	malloc_putstr("Total : ");
	print_size(size);
	malloc_putstr(" octets\n");
}
