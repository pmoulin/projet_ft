/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:16:13 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:16:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** size_t size : size request by user
** create new large zone
** return ptr(void *) on new zone OR if error return NULL
*/

void			*large(size_t s_z)
{
	t_zone		*large;

	if (!g_env_m.z_large)
	{
		if (!(g_env_m.z_large = mmap(0, s_z + H_BLOC_L, PROT_READ
			| PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
			return (NULL);
		g_env_m.z_large->size = s_z;
		g_env_m.z_large->prev = NULL;
		g_env_m.z_large->next = NULL;
		return ((void *)g_env_m.z_large + H_BLOC_L);
	}
	g_env_m.z_large = go_last_maillon(NULL, g_env_m.z_large);
	if (!(g_env_m.z_large->next = mmap(0, s_z + H_BLOC_L, PROT_READ
		| PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)))
		return (NULL);
	large = g_env_m.z_large;
	g_env_m.z_large = g_env_m.z_large->next;
	g_env_m.z_large->size = s_z;
	g_env_m.z_large->prev = large;
	g_env_m.z_large->next = NULL;
	large = g_env_m.z_large;
	g_env_m.z_large = go_first_maillon(NULL, g_env_m.z_large);
	return ((void*)large + H_BLOC_L);
}

/*
** size_t size : size request by user
** create new small zone or place search  if zone already exist
** return ptr(void *) on the zone
*/

void			*small(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (!g_env_m.z_small)
		if (new_zone_small(51 * getpagesize() * 5) == -1)
			return (NULL);
	if (!(ptr = search_place_small(size)))
	{
		if (new_zone_small(51 * getpagesize() * 5) == -1)
			return (NULL);
		ptr = search_place_small(size);
	}
	go_first_elem_small();
	return (ptr);
}

/*
** size_t size : size request by user
** create new tiny zone or place search if zone already exist
** return ptr(void *) on the zone
*/

void			*tiny(size_t size)
{
	void		*ptr;

	ptr = NULL;
	if (!g_env_m.z_tiny)
		if (new_zone_tiny(51 * getpagesize()) == -1)
			return (NULL);
	if (!(ptr = search_place_tiny(size)))
	{
		if (new_zone_tiny(51 * getpagesize()) == -1)
			return (NULL);
		ptr = search_place_tiny(size);
	}
	go_first_elem_tiny();
	return (ptr);
}

/*
** size_t size : size request by user
** detect type of zone
** return ptr(void *)
*/

void			*malloc(size_t size)
{
	void		*ptr;

	if (size <= (size_t)(getpagesize() / 2))
		ptr = tiny(size);
	else if (size > (size_t)((getpagesize() * 5) / 2))
		return (large(size));
	else
		return (small(size));
	return (ptr);
}
