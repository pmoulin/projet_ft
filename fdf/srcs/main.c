/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 10:40:18 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/20 20:17:52 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_func(int keycode, t_global *global)
{
	ft_bzero(global->img->bts_img, X_SIZE * Y_SIZE * 4);
	if (keycode == 53)
		exit(0);
	if (keycode == 7 || keycode == 16 || keycode == 6)
		ft_gen_map(global, keycode);
	else if (keycode == 69)
		ft_zoom(global, keycode);
	else if (keycode == 123 || keycode == 124 ||
			keycode == 125 || keycode == 126)
		ft_change_pos(global, keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	t_global	global;

	if (argc > 2 || argc < 2)
		ft_error(1);
	if (!(global.env = (t_env *)malloc(sizeof(t_env))))
		ft_error(2);
	ft_read_file(argv[1], &global);
	ft_check_parseur(&global, argv[1]);
	global.env->mlx = mlx_init();
	ft_gen_win(&global);
	ft_gen_img(&global, 0);
	mlx_key_hook(global.env->win, my_key_func, &global);
	mlx_loop(global.env->mlx);
	return (0);
}
