/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:55:00 by phmoulin          #+#    #+#             */
/*   Updated: 2017/03/24 15:43:30 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2 || argc > 2)
		help();
	env.mlx = mlx_init();
	create_win(&env);
	init_struct(&env);
	init_param(&env);
	fractal(&env, argv[1]);
	gen_fractal(&env);
	mlx_mouse_hook(env.win, &mouse_func, &env);
	mlx_key_hook(env.win, &my_key_func, &env);
	mlx_key_hook(env.win2, &my_key_func2, &env);
	mlx_hook(env.win, 6, 1L << 6, &mouse_code, &env);
	mlx_loop(env.mlx);
	return (0);
}
