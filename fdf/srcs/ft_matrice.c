/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:38:17 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/22 16:56:18 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_cal_matrx(t_global *global, int x, int y, t_point save)
{
	double		x1;
	double		y1;
	double		z1;

	x1 = global->pos[y][x]->x - save.x;
	y1 = global->pos[y][x]->y - save.y;
	z1 = global->pos[y][x]->z - save.z;
	global->point.radiant = 0.087266462599716;
	global->pos[y][x]->x = x1 * 1 + y1 * 0 + z1 * 0 + global->pos[y][x]->p * 0;
	global->pos[y][x]->y = x1 * 0 + y1 * cos(global->point.radiant) -
		z1 * sin(global->point.radiant) + global->pos[y][x]->p * 0;
	global->pos[y][x]->p = x1 * 0 + y1 * 0 + z1 * 0 + global->pos[y][x]->p * 1;
	global->pos[y][x]->z = x1 * 0 + y1 * sin(global->point.radiant) +
		z1 * cos(global->point.radiant) + global->pos[y][x]->p * 0;
}

static void		ft_cal_matry(t_global *global, int x, int y, t_point save)
{
	double		y1;
	double		x1;
	double		z1;

	z1 = global->pos[y][x]->z - save.z;
	y1 = global->pos[y][x]->y - save.y;
	x1 = global->pos[y][x]->x - save.x;
	global->point.radiant = 0.087266462599716;
	global->pos[y][x]->x = x1 * cos(global->point.radiant) + y1 * 0 +
		z1 * sin(global->point.radiant) + global->pos[y][x]->p * 0;
	global->pos[y][x]->y = x1 * 0 + y1 * 1 + z1 * 0 + global->pos[y][x]->p * 0;
	global->pos[y][x]->p = x1 * 0 + y1 * 0 + z1 * 0 + global->pos[y][x]->p * 1;
	global->pos[y][x]->z = x1 * -sin(global->point.radiant) + y1 * 0 +
		z1 * cos(global->point.radiant) + global->pos[y][x]->p * 0;
}

static void		ft_cal_matrz(t_global *global, int x, int y, t_point save)
{
	double		x1;
	double		y1;
	double		z1;

	z1 = global->pos[y][x]->z - save.z;
	y1 = global->pos[y][x]->y - save.y;
	x1 = global->pos[y][x]->x - save.x;
	global->point.radiant = 0.087266462599716;
	global->pos[y][x]->x = x1 * cos(global->point.radiant) -
		y1 * sin(global->point.radiant) + z1 * 0 + global->pos[y][x]->p * 0;
	global->pos[y][x]->y = x1 * sin(global->point.radiant) +
		y1 * cos(global->point.radiant) + z1 * 0 + global->pos[y][x]->p * 0;
	global->pos[y][x]->p = x1 * 0 + y1 * 0 + z1 * 0 + global->pos[y][x]->p * 1;
	global->pos[y][x]->z = x1 * 0 + y1 * 0 + z1 * 1 + global->pos[y][x]->p * 0;
}

void			ft_matrice(t_global *global, int choix, int x, int y)
{
	t_point save;

	save.x = global->pos[0][0]->x;
	save.y = global->pos[0][0]->y;
	save.z = global->pos[0][0]->z;
	if (choix == 7)
		ft_cal_matrx(global, x, y, save);
	else if (choix == 16)
		ft_cal_matry(global, x, y, save);
	else if (choix == 6)
		ft_cal_matrz(global, x, y, save);
	global->pos[y][x]->x += save.x;
	global->pos[y][x]->y += save.y;
	global->pos[y][x]->z += save.z;
}
