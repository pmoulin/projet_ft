/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:41:08 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 22:36:14 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static char		*del_space(t_env *env, char **map, int size_l, int i)
{
	int		v;
	char	*tmp;

	env->x = 0;
	v = 0;
	while (map[0][i++])
		v += (map[0][i] != ' ') ? 1 : 0;
	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (v + env->map.line))))
		ft_error(2);
	v = 1;
	while (map[0][i])
	{
		if (map[0][i] == ' ')
			i++;
		else if (map[0][i] != ' ')
			tmp[env->x++] = map[0][i++];
		if (i == size_l * v)
		{
			tmp[env->x++] = '\n';
			v++;
		}
	}
	ft_strdel(map);
	return (tmp);
}

static void		remp_tab(t_env *env, char *map, int size_l)
{
	int		i;
	int		l;
	int		x;

	if (!(env->map.map = (char **)malloc(sizeof(char *) * (env->map.line + 1))))
		ft_error(2);
	i = 0;
	l = 0;
	while (l < env->map.line)
	{
		x = 0;
		if (!(env->map.map[l] = (char *)malloc(sizeof(char) * (size_l + 1))))
			ft_error(2);
		while (map[i] != '\n' && map[i])
		{
			env->map.map[l][x] = map[i];
			i++;
			x++;
		}
		i++;
		env->map.map[l][x] = '\0';
		l++;
	}
	env->map.map[l] = NULL;
}

static void		extract(t_env *env, int fd, char **map, int *size_l)
{
	int		i;
	char	*line;
	char	*tmp;

	tmp = NULL;
	i = 0;
	env->x = 0;
	while ((i = ft_get_next_line(fd, &line)) == 1)
	{
		tmp = ft_strjoin(*map, line);
		if (*map)
			ft_strdel(map);
		else if (!*map)
		{
			*size_l = (int)ft_strlen(line);
			if ((tmp = ft_strdup(line)) == NULL)
				ft_error(2);
		}
		if ((*map = ft_strdup(tmp)) == NULL)
			ft_error(2);
		ft_strdel(&tmp);
		ft_strdel(&line);
		env->map.line += 1;
	}
	(i < 0) ? ft_error(3) : 0;
}

void			read_files(t_env *env, int fd)
{
	int		size_l;
	char	*map;

	size_l = 0;
	map = NULL;
	extract(env, fd, &map, &size_l);
	close(fd);
	map = del_space(env, &map, size_l, 0);
	remp_tab(env, map, size_l);
	ft_strdel(&map);
}
