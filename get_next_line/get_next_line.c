/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:57:33 by phmoulin          #+#    #+#             */
/*   Updated: 2017/02/11 10:17:35 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_first_return_line(char *s, char **line, int choix)
{
	int				i;

	i = 0;
	if (choix == 0)
	{
		while (s[i] != '\n' && s[i])
			i++;
		return (i);
	}
	else if (choix == 1)
	{
		while (line[0][i] && line[0][i] != '\n')
			i++;
		return (1);
	}
	return (0);
}

static char			*ft_wi(char **s, char **line)
{
	int				i;
	int				a;
	char			*tmp;

	a = 0;
	tmp = NULL;
	i = 0;
	i = ft_first_return_line(*s, line, 0);
	if (!(*line = (char *)malloc((i) * sizeof(char *))))
		return (NULL);
	a = ft_strlen(*s);
	*line = ft_strncpy(*line, *s, i);
	line[0][i] = '\0';
	a = (a - i);
	tmp = ft_strdup(*s);
	ft_strdel(s);
	*s = ft_strsub(tmp, i + 1, a);
	ft_strdel(&tmp);
	return (*line);
}

static void			ft_add_s(char **content, char **s)
{
	char			*tmp;

	tmp = NULL;
	tmp = ft_strjoin(*s, *content);
	free(*content);
	*content = NULL;
	free(*s);
	*s = NULL;
	*s = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
}

static int			ft_read(int fd, char **s, char **content)
{
	int				nb;

	nb = 1;
	while (nb != 0)
	{
		if (!(*content = (char *)malloc((BUFF_SIZE) * sizeof(char))))
			return (-1);
		if (*s == NULL)
			if (!(*s = (char *)malloc((BUFF_SIZE) * sizeof(char))))
				return (-1);
		nb = read(fd, *content, BUFF_SIZE);
		if (nb > 0)
			content[0][nb] = '\0';
		if (nb == -1)
			return (-1);
		if (nb != 0 && *s != NULL)
			ft_add_s(content, s);
		if (nb == 0 && *content == '\0')
			return (0);
		if ((ft_first_return_line(*s, s, 0)) == (int)ft_strlen(*s) && nb != 0)
			ft_strdel(content);
	}
	ft_strdel(content);
	return (nb);
}

int					get_next_line(const int fd, char **line)
{
	int				nb;
	char			*content;
	static char		*s = NULL;

	content = NULL;
	nb = 1;
	if (fd < 0)
		return (-1);
	if (nb != 0)
		nb = ft_read(fd, &s, &content);
	if (nb == -1)
		return (-1);
	if ((int)ft_strlen(s) >= 1)
	{
		*line = ft_wi(&s, line);
		return (1);
	}
	free(content);
	return (0);
}
