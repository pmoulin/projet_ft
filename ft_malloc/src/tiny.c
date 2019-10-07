/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:17:06 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:17:07 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** size_t size : size nedded by user
** create new bloc in zone tiny with size = parameter size
** return ptr on the new bloc for user.
*/

static void			*new_bloc_tiny(size_t size)
{
	t_bloc			*bloc;
	void			*ptr;
	size_t			old_size;

	ptr = NULL;
	old_size = g_env_m.z_tiny->bloc->size;
	bloc = g_env_m.z_tiny->bloc;
	g_env_m.z_tiny->bloc = ((void *)((void *)bloc + H_BLOC_SM) + size);
	g_env_m.z_tiny->bloc->status = 0;
	g_env_m.z_tiny->bloc->next = bloc->next;
	bloc->status = 1;
	bloc->next = g_env_m.z_tiny->bloc;
	bloc->size = size;
	g_env_m.z_tiny->bloc->prev = bloc;
	g_env_m.z_tiny->bloc->size = old_size - (size + H_BLOC_SM);
	ptr = bloc + H_BLOC_SM;
	return (ptr);
}

/*
** bloc type tiny is free, change status to 1 and good size.
** RETURN :
** ptr for users
*/

static void			*edit_bloc_tiny(void)
{
	g_env_m.z_tiny->bloc->status = 1;
	return (g_env_m.z_tiny->bloc + H_BLOC_SM);
}

/*
** size_t size_zone : size for new zone preallocated
** create first zone tiny and first bloc in zone.
** RETURN :
** 1 : succes.
** -1 : fail.
*/

static int			first_zone(size_t size_zone)
{
	if (!(g_env_m.z_tiny = mmap(0, size_zone + ZONE_HEADER,
	PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
		return (-1);
	g_env_m.z_tiny->next = NULL;
	g_env_m.z_tiny->prev = NULL;
	g_env_m.z_tiny->size = size_zone;
	g_env_m.z_tiny->bloc = (void *)(g_env_m.z_tiny + ZONE_HEADER);
	g_env_m.z_tiny->bloc->next = NULL;
	g_env_m.z_tiny->bloc->prev = NULL;
	g_env_m.z_tiny->bloc->status = 0;
	g_env_m.z_tiny->bloc->size = size_zone;
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

int					new_zone_tiny(size_t size_zone)
{
	t_zone			*old_zone;

	old_zone = NULL;
	if (g_env_m.z_tiny && g_env_m.z_tiny + ZONE_HEADER)
	{
		while (g_env_m.z_tiny->next)
			g_env_m.z_tiny = g_env_m.z_tiny->next;
		old_zone = g_env_m.z_tiny;
		if (!(g_env_m.z_tiny->next = mmap(0, size_zone + ZONE_HEADER, PROT_READ
		| PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
			return (-1);
		g_env_m.z_tiny = g_env_m.z_tiny->next;
		g_env_m.z_tiny->size = size_zone;
		g_env_m.z_tiny->prev = old_zone;
		g_env_m.z_tiny->next = NULL;
		g_env_m.z_tiny->bloc = (void *)g_env_m.z_tiny + ZONE_HEADER;
		g_env_m.z_tiny->bloc->next = NULL;
		g_env_m.z_tiny->bloc->prev = NULL;
		g_env_m.z_tiny->bloc->status = 0;
		g_env_m.z_tiny->bloc->size = size_zone;
		return (1);
	}
	return (first_zone(size_zone));
}

/*
** size_t size : size nedded by user
** search place in all zone.
** RETURN : PTR for users.
*/

void				*search_place_tiny(size_t size)
{
	void		*ptr;

	ptr = NULL;
	while (g_env_m.z_tiny)
	{
		while (g_env_m.z_tiny->bloc && ptr == NULL)
		{
			if (g_env_m.z_tiny->bloc->size >= (size + H_BLOC_SM)
			&& g_env_m.z_tiny->bloc->status == 0)
				ptr = (g_env_m.z_tiny->bloc->size > size + H_BLOC_SM)
					? new_bloc_tiny(size) : edit_bloc_tiny();
			if (!g_env_m.z_tiny->bloc->next || ptr != NULL)
				break ;
			g_env_m.z_tiny->bloc = g_env_m.z_tiny->bloc->next;
		}
		if (ptr || !g_env_m.z_tiny->next)
			break ;
		g_env_m.z_tiny = g_env_m.z_tiny->next;
	}
	go_first_elem_tiny();
	return (ptr);
}
