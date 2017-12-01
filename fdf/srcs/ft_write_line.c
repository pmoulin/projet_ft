/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:11:00 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/22 17:03:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check_fin(t_point a, t_point b)
{
	if (a.x < 0 || a.x > 1000 || a.y < 0 || a.y > 1000)
		return (-1);
	if ((int)a.x == (int)b.x && (int)a.y + 1 == (int)b.y)
		return (-1);
	else if ((int)a.x == (int)b.x && (int)b.y + 1 == (int)a.y)
		return (-1);
	else if ((int)a.x + 1 == (int)b.x && (int)a.y == (int)b.y)
		return (-1);
	else if ((int)a.x == (int)b.x + 1 && (int)b.y + 1 == (int)a.y)
		return (-1);
	else if ((int)a.x + 1 == (int)b.x && (int)b.y == (int)a.y + 1)
		return (-1);
	else if ((int)a.x == (int)b.x + 1 && (int)b.y == (int)a.y + 1)
		return (-1);
	else if ((int)a.x + 1 == (int)b.x && (int)b.y + 1 == (int)a.y)
		return (-1);
	return (0);
}

static void	ft_if_one(double *e1, t_point *d, t_point *a, t_point *s)
{
	*e1 -= d->y;
	a->x += s->x;
}

static void	ft_cal_origin(t_point *d, t_point *s, t_point *b, t_point *a)
{
	d->x = ABS(b->x - a->x);
	d->y = ABS(b->y - a->y);
	s->x = (a->x < b->x ? 1 : -1);
	s->y = (a->y < b->y ? 1 : -1);
}

void		ft_draw_line(t_global *global, t_point a, t_point b, int color)
{
	t_point		d;
	t_point		s;
	double		e1;
	double		e2;

	ft_cal_origin(&d, &s, &b, &a);
	e1 = (d.x > d.y ? d.x : -d.y) / 2;
	while ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
	{
		if (ft_check_fin(a, b) == -1)
			return ;
		ft_put_img(global, (int)a.x, (int)a.y, color);
		e2 = e1;
		if (e2 > -d.x)
			ft_if_one(&e1, &d, &a, &s);
		if (e2 < d.y)
		{
			e1 += d.x;
			a.y += s.y;
		}
		ft_put_img(global, (int)a.x, (int)a.y, color);
	}
}
