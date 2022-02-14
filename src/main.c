/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:49:50 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 09:57:52 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	close_window(t_fdf_params *fdf)
{
	exit_program(fdf, 0);
	return (0);
}

static void	new_window(t_fdf_params *fdf, char *name)
{
	fdf->win = mlx_new_window(fdf->mlx, WIN_SIZE_X, WIN_SIZE_Y, name);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}

static void	init(t_fdf_params *fdf)
{
	fdf->mlx = mlx_init();
	new_window(fdf, "fdf - marcrodr");
	fdf->angles = malloc(sizeof(t_angles));
	if (!fdf->angles)
		error(3, 0, "Error while allocating memory for angles.");
	fdf->angles->alpha = 1.05;
	fdf->angles->beta = 0.65;
	fdf->angles->gama = 0.8;
	fdf->zoom = 50;
	fdf->translation_x = 300;
	fdf->translation_y = 100;
	fdf->z_multiplier = 1;
	fdf->map.x_max = -1;
	fdf->map.y_max = 0;
	fdf->map.z_max = 0;
	fdf->map.z_min = 0;
	fdf->map.x = 0;
	fdf->instructions = 0;
	fdf->color_mode = 1;
	fdf->color_one = create_trgb(255, 0, 255, 255);
	fdf->color_two = create_trgb(255, 255, 255, 0);
	ft_printf("\n\nPRESS H TO SHOW INSTRUCTIONS AND STATUS\n\n");
	load_map(fdf);
}

int	main(int argc, char **argv)
{
	t_fdf_params	*fdf;

	fdf = malloc(sizeof(t_fdf_params));
	if (!fdf)
		error(3, 0, "Error while creating fdf");
	check_initial_errors(fdf, argc, argv);
	init(fdf);
	print_fdf(fdf);
	mlx_key_hook(fdf->win, &key_hook, fdf);
	mlx_loop(fdf->mlx);
}
