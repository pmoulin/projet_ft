/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 10:29:08 by phmoulin          #+#    #+#             */
/*   Updated: 2017/04/13 20:17:28 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_check_file(char *path)
{
	int		fd;
	int		x;
	char	*line;
	int		nb;

	nb = 0;
	line = NULL;
	fd = open(path, O_RDONLY);
	while ((nb = ft_get_next_line(fd, &line)) > 0)
	{
		x = 0;
		while (line[x])
		{
			if ((line[x] < '0' || line[x] > '9') && line[x] != '-' &&
				line[x] != ' ')
				ft_error(3);
			else
				x++;
		}
		free(line);
	}
	close(fd);
}

void	ft_check_parseur(t_global *global, char *path)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	ft_check_file(path);
	while (global->pos[y + 1])
	{
		if (global->pos[y][0]->size != global->pos[y + 1][0]->size)
			ft_error(3);
		if (global->pos[y][x]->z > 10000 || global->pos[y][x]->z < -10000)
			ft_error(3);
		y++;
	}
}
