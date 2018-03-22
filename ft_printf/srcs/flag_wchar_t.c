/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_wchar_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:24:41 by phmoulin          #+#    #+#             */
/*   Updated: 2018/03/10 15:37:01 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_unsi_c(wchar_t c, t_env *e, int i)
{
	int		i1;
	char	*str;
	char	c1;

	c1 = '\0';
	str = NULL;
	i1 = 0;
	e->line = NULL;
	if (c == 0)
	{
		write(1, &c, 1);
		e->size_line += 1;
		return (i);
	}
	str = ft_getwchar(c);
	while (str[i1])
		ft_putchar(str[i1++]);
	e->size_line += i1;
	free(str);
	return (i);
}

static void	cpy_line_to_str(t_env *e, char **str, int len)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	e->pos = 0;
	while (len > 0 && str[x])
	{
		e->line[e->pos++] = str[x][y++];
		len--;
		if (!str[x][y])
		{
			x++;
			y = 0;
		}
	}
	e->pos = 0;
	free_tab(str, x);
	free(str);
	str = NULL;
}

static int	count_nb_elem(t_env *e, char **str, wchar_t *s, int *x)
{
	int		y;

	y = 0;
	str[*x] = NULL;
	*x = 0;
	while (s[*x])
	{
		str[*x] = ft_getwchar(s[*x]);
		y += (int)ft_strlen(str[*x]);
		*x += 1;
		str[*x] = NULL;
	}
	e->line = ft_strnew(y + 1);
	*x = 0;
	return (y);
}

static void	free_str(t_env *e, int x, int y, char **str)
{
	if (e->t2 != 0 && e->t2 > (int)ft_strlen(str[0]))
	{
		while (e->t2 > y)
			y += ft_strlen(str[x++]);
		if (y > e->t2)
		{
			x--;
			y = x;
			while (str[x])
			{
				free(str[x]);
				x++;
			}
			str[y] = NULL;
		}
	}
}

int			flag_uni_s(wchar_t *s, t_env *e, int i)
{
	int		x;
	char	**str;
	int		len;
	char	*str1;

	x = 0;
	if (s == NULL)
		return (s_nul(e, NULL, -1, i));
	len = ft_strlen((char *)s) + 1;
	while (s[x])
		x++;
	if (!(str = (char **)malloc(sizeof(char *) * (x + 1))))
		ft_error("MALLOC STR**", "flag_uni_s");
	len = count_nb_elem(e, str, s, &x);
	free_str(e, x, 0, str);
	cpy_line_to_str(e, str, len);
	if (e->tv[0] != 0 || e->tv[1] != 0)
	{
		str1 = ft_strdup(e->line);
		ft_strdel(&e->line);
		choice_precision_and_lenght_for_s(e, str1);
		free(str1);
	}
	return (i);
}
