/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 10:17:12 by phmoulin          #+#    #+#             */
/*   Updated: 2019/05/09 10:17:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

/*
** t_bloc *bloc : mallon list 'bloc'
** t_zone *zone : maillon liste 'zone'
** go to the last maillon in the list 'bloc' or 'zone'
*/

void		*go_last_maillon(t_bloc *bloc, t_zone *zone)
{
	void	*ptr;

	ptr = NULL;
	if (bloc && bloc->next)
	{
		while (bloc->next)
			bloc = bloc->next;
		return (bloc);
	}
	else if (zone && zone->next)
	{
		while (zone->next)
			zone = zone->next;
		return (zone);
	}
	ptr = (bloc != NULL) ? (void *)bloc : (void *)zone;
	return (ptr);
}

/*
** t_bloc *bloc : mallon list 'bloc'
** t_zone *zone : maillon liste 'zone'
** go to the first maillon in the list 'bloc' or 'zone'
*/

void		*go_first_maillon(t_bloc *bloc, t_zone *zone)
{
	void	*ptr;

	ptr = NULL;
	if (bloc && bloc->prev)
	{
		while (bloc->prev)
			bloc = bloc->prev;
		return (bloc);
	}
	else if (zone && zone->prev)
	{
		while (zone->prev)
			zone = zone->prev;
		return (zone);
	}
	ptr = (bloc != NULL) ? (void *)bloc : (void *)zone;
	return (ptr);
}

/*
** go the first elem in list 'bloc' for all elem 'zone small'
*/

void		go_first_elem_small(void)
{
	while (g_env_m.z_small)
	{
		g_env_m.z_small->bloc = go_first_maillon(g_env_m.z_small->bloc, NULL);
		if (!g_env_m.z_small->prev)
			return ;
		g_env_m.z_small = g_env_m.z_small->prev;
	}
}

/*
** go the first elem in list 'bloc' for all elem 'zone tiny'
*/

void		go_first_elem_tiny(void)
{
	while (g_env_m.z_tiny)
	{
		g_env_m.z_tiny->bloc = go_first_maillon(g_env_m.z_tiny->bloc, NULL);
		if (!g_env_m.z_tiny->prev)
			return ;
		g_env_m.z_tiny = g_env_m.z_tiny->prev;
	}
}

t_zone		*move_ptr_global(t_zone *zone, t_zone *zone_g)
{
	while (zone_g && zone_g != zone)
	{
		if (!zone_g->next)
			break ;
		zone_g = zone_g->next;
	}
	if (zone_g == zone)
	{
		if (zone_g->next || zone_g->prev)
			return (zone_g = (zone_g->prev != NULL)
				? zone_g->prev : zone_g->next);
		else
			return (NULL);
	}
	else
		return (go_first_maillon(NULL, zone_g));
}
