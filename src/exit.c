/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:53:28 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 09:54:51 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	free_map(t_fdf_params *fdf)
{
	int	i;

	i = 0;
	while (i <= fdf->map.x_max)
	{
		free(fdf->map.points[i]);
		free(fdf->map.colors[i]);
		i++;
	}
	free(fdf->map.points);
	free(fdf->map.colors);
}

void	exit_program(t_fdf_params *fdf, int code)
{
	if (code == 0)
		ft_printf("Exiting program.\n");
	else if (code == -1)
		ft_printf("Error. Exiting program.\n");
	else if (code == 1)
		ft_printf("Error reading file: %s\n"
			"Make sure it exists in the maps folder.\n", fdf->map.path);
	else if (code == 2)
		ft_printf("Error reading file\n"
			"This file is not an fdf file.\n");
	free(fdf->angles);
	free(fdf->map.map_name);
	free_map(fdf);
	mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	mlx_loop_end(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(code);
}
