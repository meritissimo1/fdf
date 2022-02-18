/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:53:28 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/18 01:50:17 by marcrodr         ###   ########.fr       */
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
		i++;
	}
	free(fdf->map.points);
}

static void	exit_code1(t_fdf_params *fdf, int code)
{
	ft_printf("Error reading file\n");
	free(fdf);
	exit(code);
}

static void	exit_code2(t_fdf_params *fdf, int code)
{
	ft_printf("Error reading file\n");
	free(fdf->angles);
	free(fdf->map.path);
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(code);
}

void	exit_program(t_fdf_params *fdf, int code)
{
	if (code == 0)
		ft_printf("Exiting program.\n");
	else if (code == -1)
		ft_printf("Error. Exiting program.\n");
	else if (code == 1)
		exit_code1(fdf, code);
	else if (code == 2)
		exit_code2(fdf, code);
	free(fdf->angles);
	free(fdf->map.path);
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
