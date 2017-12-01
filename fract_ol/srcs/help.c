/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phmoulin <phmoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:25:33 by phmoulin          #+#    #+#             */
/*   Updated: 2017/04/28 10:38:58 by phmoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		help_win_next2(t_env *env, int x)
{
	mlx_string_put(env->mlx, env->win2, x, 350, 0x00FFFFFF,
		"Deplacement fractal sur la haut : fleche de bas.\n");
	mlx_string_put(env->mlx, env->win2, x, 370, 0x0000561B,
		"---- VARATION JULIA : ");
	mlx_string_put(env->mlx, env->win2, x, 390, 0x00FFFFFF,
		"Ensuite amuser vous avec la souris !\n");
	mlx_string_put(env->mlx, env->win2, x, 430, 0x0000561B,
		"---- REBOOT FRACTAL :");
	mlx_string_put(env->mlx, env->win2, x, 450, 0x00FFFFFF,
		"Pour (re-)generer la fractal : '~'.");
}

static void		help_win_next(t_env *env, int x)
{
	mlx_string_put(env->mlx, env->win2, x, 190, 0x00FFFFFF,
		"Dezoom centre de la fenetre = '-' (paver num).\n");
	mlx_string_put(env->mlx, env->win2, x, 210, 0x0000561B,
		"---- ITERATION :");
	mlx_string_put(env->mlx, env->win2, x, 230, 0x00FFFFFF,
		"Augmentation iteration : '2' (paver num).");
	mlx_string_put(env->mlx, env->win2, x, 250, 0x00FFFFFF,
		"Abaisser iteration : '1' paver num.\n");
	mlx_string_put(env->mlx, env->win2, x, 270, 0x0000561B,
		"---- DEPLACEMENT : .");
	mlx_string_put(env->mlx, env->win2, x, 290, 0x00FFFFFF,
		"Deplacement fractal sur la gauche : fleche de droite.");
	mlx_string_put(env->mlx, env->win2, x, 310, 0x00FFFFFF,
		"Deplacement fractal sur la droite : fleche de gauche.");
	mlx_string_put(env->mlx, env->win2, x, 330, 0x00FFFFFF,
		"Deplacement fractal sur la bas : fleche de haut.");
	help_win_next2(env, x);
}

void			help_win(t_env *env)
{
	int		x;

	x = 10;
	mlx_string_put(env->mlx, env->win2, 170, 10, 0x00A91101,
		"------------FRACTOL------------");
	mlx_string_put(env->mlx, env->win2, x, 30, 0x0000561B,
		"---- CHOIX FRACTAL :");
	mlx_string_put(env->mlx, env->win2, x, 50, 0x00FFFFFF,
		"Mandelbrot : 'M'.");
	mlx_string_put(env->mlx, env->win2, x, 70, 0x00FFFFFF,
		"Julia : 'J'.");
	mlx_string_put(env->mlx, env->win2, x, 90, 0x00FFFFFF,
		"Burn Ship : 'B'.\n");
	mlx_string_put(env->mlx, env->win2, x, 110, 0x00FFFFFF,
		"EXEMPLE  pour afficher Mandelbrot : ./FRACTOL M\n");
	mlx_string_put(env->mlx, env->win2, x, 130, 0x0000561B,
		"---- ZOOM :");
	mlx_string_put(env->mlx, env->win2, x, 150, 0x00FFFFFF,
		"Zoom curseur et dezoom curseur : molette de la souris.");
	mlx_string_put(env->mlx, env->win2, x, 170, 0x00FFFFFF,
		"Zoom centre de la fenetre = '+' (paver num).");
	help_win_next(env, x);
}

void			help(void)
{
	DB("------------FRACTOL------------");
	DB("---- CHOIX FRACTAL :");
	DB("Mandelbrot : 'M'.");
	DB("Julia : 'J'.");
	DB("Burn Ship : 'B'.\n");
	DB("EXEMPLE  pour afficher Mandelbrot : ./FRACTOL M\n");
	DB("---- ZOOM :");
	DB("Zoom curseur et dezoom curseur : molette de la souris.");
	DB("Zoom centre de la fenetre = '+' (paver num).");
	DB("dezoom centre de la fenetre = '-' (paver num).\n");
	DB("---- ITERATION :");
	DB("Augmentation iteration : '1' (paver num).");
	DB("Abaisser iteration : '2' (paver num).\n");
	DB("---- DEPLACEMENT : .");
	DB("deplacement fractal sur la gauche : fleche de droite.");
	DB("deplacement fractal sur la droite : fleche de gauche.");
	DB("deplacement fractal sur la bas : fleche de haut.");
	DB("deplacement fractal sur la haut : fleche de bas.\n");
	DB("---- VARATION JULIA : ");
	DB("appuyer sur 'T' une fois pour activer et encore pour desactiver.");
	DB("Ensuite amuser vous avec la souris !\n");
	DB("---- REBOOT FRACTAL :");
	DB("Pour (re)generer la fractal : '~'.");
	error(1);
}
