/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:25:45 by phmoulin          #+#    #+#             */
/*   Updated: 2017/05/13 22:46:21 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		check_file(char *str)
{
	int		fd;
	char	s[1];

	fd = 0;
	fd = open(str, O_RDONLY);
	if (read(fd, s, 1) <= 0)
		ft_error(1);
	else
	{
		close(fd);
	}
}

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		ft_error(1);
	check_file(argv[1]);
	env.mlx = mlx_init();
	create_win_img(&env);
	init_struct(&env, 1);
	init_struct(&env, 2);
	weapon(&env, 0);
	parseur(&env, argv[1]);
	check_map(&env);
	gen_menu_down(&env);
	gen_map(&env);
	weapon_select(&env);
	mlx_do_key_autorepeaton(env.mlx);
	mlx_hook(env.win, 17, (1L << 17), exit_red, &env);
	mlx_hook(env.win, 2, 0, my_key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
