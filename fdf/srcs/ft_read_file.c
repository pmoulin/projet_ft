/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:00:52 by phmoulin          #+#    #+#             */
/*   Updated: 2017/04/13 19:56:59 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_malloc_parse(t_global *global, int *i, int nb)
{
	if (!(global->pos[*i] = (t_point **)malloc(sizeof(t_point *) * (nb + 1))))
		ft_error(2);
	*i += 1;
	return (0);
}

static void	ft_tab(char *line, int nb, int fd, t_global *global)
{
	int		x;
	int		i;
	int		comp;

	i = 0;
	while ((comp = ft_get_next_line(fd, &line)) >= 1)
	{
		nb = 0;
		x = 0;
		while (line[x + 1] != '\0')
		{
			if (line[x] != ' ' && line[x] != '\0')
			{
				nb += 1;
				while (line[x] != ' ' && line[x + 1] != '\0')
					x += 1;
			}
			x += 1;
		}
		ft_malloc_parse(global, &i, nb + 1);
		ft_strdel(&line);
	}
	(line != NULL) ? ft_strdel(&line) : 0;
	close(fd);
	global->pos[i] = NULL;
}

int			ft_init_tab(t_global *global, char *path)
{
	int		fd;
	char	*line;
	int		nb;

	nb = 0;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(3);
	ft_alloc_y(global, line, path);
	ft_tab(line, nb, fd, global);
	close(fd);
	return (1);
}

void		ft_split(char *line, t_global *global, int y, int i)
{
	int		x;

	x = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (!(global->pos[y][x] = (t_point *)malloc(sizeof(t_point))))
				ft_error(2);
			global->pos[y][x]->z = ft_atoi(&line[i]) * 2;
			global->pos[y][x]->y = y * 10 + 300;
			global->pos[y][x]->x = x * 10 + 300;
			global->pos[y][x]->zo = global->pos[y][x]->z;
			global->pos[y][x]->p = 1;
			x++;
			global->pos[y][x] = NULL;
			while (line[i] && line[i] != ' ')
				i++;
		}
		i++;
	}
	if (y >= 1)
		if (global->pos[y - 1][0]->size != x)
			ft_error(3);
	global->pos[y][0]->size = x;
}

int			ft_read_file(char *path, t_global *global)
{
	int		fd;
	char	*line;
	int		y;
	int		nb;

	y = 0;
	ft_check_file(path);
	ft_init_tab(global, path);
	if ((fd = open(path, O_RDONLY)) < 0)
		ft_error(3);
	while ((nb = ft_get_next_line(fd, &line)) == 1)
	{
		if (nb == 1 && line[0] == '\0')
			ft_error(3);
		ft_split(line, global, y, 0);
		y++;
		ft_strdel(&line);
	}
	if (nb == -1)
		ft_error(3);
	close(fd);
	return (1);
}
