/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:07 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:09 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** void *ptr : pointer to release
** t_zone *zone : (void *)ptr - H_BLOC_L;
**
** check if ptr = large alloction
** if true :
** release the pointeur and return (0);
** else :
** return (-1);
*/

static int			check_large(void *ptr, t_zone *zone)
{
	while (g_env_m.z_large)
	{
		if (g_env_m.z_large == zone)
		{
			zone = (zone->next != NULL) ? zone->next : zone;
			if (zone == g_env_m.z_large->next)
				zone->prev = g_env_m.z_large->prev;
			zone = (g_env_m.z_large->prev != NULL)
				? g_env_m.z_large->prev : g_env_m.z_large;
			if (zone == g_env_m.z_large->prev)
				zone->next = g_env_m.z_large->next;
			zone = g_env_m.z_large;
			if (!g_env_m.z_large->next && !g_env_m.z_large->prev)
				g_env_m.z_large = NULL;
			else
				g_env_m.z_large = (g_env_m.z_large->prev != NULL)
				? g_env_m.z_large->prev : g_env_m.z_large->next;
			return (munmap((void*)ptr - H_BLOC_L, zone->size + H_BLOC_L));
		}
		if (!g_env_m.z_large->next)
			break ;
		g_env_m.z_large = g_env_m.z_large->next;
	}
	g_env_m.z_large = go_first_maillon(NULL, g_env_m.z_large);
	return (-1);
}

/*
** t_bloc *bloc : mallon in list;
** check if zone pre-alloued is empty
** if empty : release memory
** else : do nothing
*/

static void			zone_is_clean(t_bloc *bloc)
{
	t_zone		*tmp_z;
	t_zone		*tmp2_z;

	tmp2_z = (void *)bloc - ZONE_HEADER;
	tmp_z = (t_zone *)tmp2_z;
	if (tmp2_z->prev || tmp2_z->next)
	{
		tmp2_z = (tmp2_z->next != NULL) ? tmp2_z->next : tmp2_z;
		if (tmp2_z == tmp_z->next)
		{
			tmp2_z->prev = tmp_z->prev;
			tmp2_z = tmp_z;
		}
		tmp2_z = (tmp2_z->prev != NULL) ? tmp2_z->prev : tmp2_z;
		if (tmp2_z == tmp_z->prev)
			tmp2_z->next = tmp_z->next;
		if (g_env_m.z_tiny)
			g_env_m.z_tiny = move_ptr_global(tmp_z, g_env_m.z_tiny);
		else if (g_env_m.z_small)
			g_env_m.z_small = move_ptr_global(tmp_z, g_env_m.z_small);
		munmap((void *)tmp_z, tmp_z->size + ZONE_HEADER);
	}
}

/*
** t_bloc *bloc = maillon(memory) released by user
** t_bloc *tmp = NULL,  is for norme
** join two bloc (prev or/and next) if status = 0;
*/

static void			defragment(t_bloc *bloc, t_bloc *tmp)
{
	int			i;

	i = 0;
	tmp = bloc;
	if (tmp->prev)
	{
		tmp = tmp->prev;
		if (tmp->status == 0)
		{
			bloc = join_bloc(bloc, tmp);
			i = 1;
		}
	}
	tmp = bloc;
	if (tmp->next)
	{
		tmp = tmp->next;
		if ((tmp + H_BLOC_SM) && tmp->status == 0)
		{
			bloc = join_bloc(tmp, bloc);
			i = 1;
		}
	}
	if (i == 0)
		bloc->status = 0;
}

/*
** bloc1 = le bloc a integrer dans bloc 2
** bloc2 = le bloc a garder
** sinde les bloc  si bloc + 1 est considerer comme libre
*/

t_bloc				*join_bloc(t_bloc *bloc1, t_bloc *bloc2)
{
	size_t		size;

	size = bloc1->size + bloc2->size + H_BLOC_SM;
	bloc2->next = bloc1->next;
	bloc2->size = size;
	bloc2->status = 0;
	bloc1->status = 0;
	if (bloc1->next)
	{
		bloc1 = bloc1->next;
		bloc1->prev = bloc2;
	}
	while (bloc1)
	{
		if (!bloc1->next)
			break ;
		bloc1 = bloc1->next;
	}
	return (bloc2);
}

/*
** detecte type of ptr
*/

void				free(void *ptr)
{
	t_bloc		*bloc;

	if (!ptr)
		return ;
	if (g_env_m.z_large && check_large(ptr, (ptr - H_BLOC_L)) == 0)
		return ;
	bloc = (t_bloc *)ptr - H_BLOC_SM;
	if (bloc && bloc->status == 1)
	{
		defragment(bloc, NULL);
		if (!bloc->prev && !bloc->next && bloc->status == 0)
		{
			zone_is_clean(bloc);
		}
	}
}
