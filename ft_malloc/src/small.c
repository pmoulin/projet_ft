/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:17:01 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:17:02 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** size_t size : size nedded by user
** create new bloc in zone small with size = parameter size
** return ptr on the new bloc for user.
*/

static void			*new_bloc_small(size_t size)
{
	t_bloc			*bloc;
	void			*ptr;
	size_t			old_size;

	ptr = NULL;
	old_size = g_env_m.z_small->bloc->size;
	bloc = g_env_m.z_small->bloc;
	g_env_m.z_small->bloc = ((void *)((void *)bloc + H_BLOC_SM) + size);
	g_env_m.z_small->bloc->status = 0;
	g_env_m.z_small->bloc->next = bloc->next;
	bloc->status = 1;
	bloc->next = g_env_m.z_small->bloc;
	bloc->size = size;
	g_env_m.z_small->bloc->prev = bloc;
	g_env_m.z_small->bloc->size = old_size - (size + H_BLOC_SM);
	ptr = bloc + H_BLOC_SM;
	return (ptr);
}

/*
** bloc type small is free, change status to 1 and good size.
** RETURN :
** ptr for users
*/

static void			*edit_bloc_small(void)
{
	g_env_m.z_small->bloc->status = 1;
	return (g_env_m.z_small->bloc + H_BLOC_SM);
}

/*
** size_t size_zone : size for new zone preallocated
** create first zone small and first bloc in zone.
** RETURN :
** 1 : succes.
** -1 : fail.
*/

static int			first_zone(size_t size_zone)
{
	if (!(g_env_m.z_small = mmap(0, size_zone + ZONE_HEADER,
	PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
		return (-1);
	g_env_m.z_small->next = NULL;
	g_env_m.z_small->prev = NULL;
	g_env_m.z_small->size = size_zone;
	g_env_m.z_small->bloc = (void *)g_env_m.z_small + ZONE_HEADER;
	g_env_m.z_small->bloc->next = NULL;
	g_env_m.z_small->bloc->prev = NULL;
	g_env_m.z_small->bloc->status = 0;
	g_env_m.z_small->bloc->size = size_zone;
	return (1);
}

/*
** size_t size_zone : size for new zone preallocated
** IF already exist zone :
** create new zone;
** ELSE :
** create first zone by size_zone passed in parameter.
** RETURN :
** 1 : succes.
** -1 : fail.
*/

int					new_zone_small(size_t size_zone)
{
	t_zone			*old_zone;

	old_zone = NULL;
	if (g_env_m.z_small && g_env_m.z_small + ZONE_HEADER)
	{
		while (g_env_m.z_small->next)
			g_env_m.z_small = g_env_m.z_small->next;
		old_zone = g_env_m.z_small;
		if (!(g_env_m.z_small->next = mmap(0, size_zone + ZONE_HEADER, PROT_READ
		| PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
			return (-1);
		g_env_m.z_small = g_env_m.z_small->next;
		g_env_m.z_small->size = size_zone;
		g_env_m.z_small->prev = old_zone;
		g_env_m.z_small->next = NULL;
		g_env_m.z_small->bloc = (void *)g_env_m.z_small + ZONE_HEADER;
		g_env_m.z_small->bloc->next = NULL;
		g_env_m.z_small->bloc->prev = NULL;
		g_env_m.z_small->bloc->status = 0;
		g_env_m.z_small->bloc->size = size_zone;
		return (1);
	}
	return (first_zone(size_zone));
}

/*
** size_t size : size nedded by user
** search place in all zone.
** RETURN : PTR for users.
*/

void				*search_place_small(size_t size)
{
	void		*ptr;

	ptr = NULL;
	while (g_env_m.z_small)
	{
		while (g_env_m.z_small->bloc && ptr == NULL)
		{
			if (g_env_m.z_small->bloc->size >= (size + H_BLOC_SM)
			&& g_env_m.z_small->bloc->status == 0)
				ptr = (g_env_m.z_small->bloc->size > size + H_BLOC_SM)
					? new_bloc_small(size) : edit_bloc_small();
			if (!g_env_m.z_small->bloc->next || ptr != NULL)
				break ;
			g_env_m.z_small->bloc = g_env_m.z_small->bloc->next;
		}
		if (ptr || !g_env_m.z_small->next)
			break ;
		g_env_m.z_small = g_env_m.z_small->next;
	}
	go_first_elem_small();
	return (ptr);
}
