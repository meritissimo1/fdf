/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:37:47 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/17 19:16:05 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	gradient(t_fdf_params *fdf, int z)
{
	float	percent;
	float	r;
	float	g;
	float	b;

	percent = ((z - fdf->map.z_min) * 100 / (fdf->map.z_max - fdf->map.z_min));
	r = get_r(fdf->color_one) + percent
		* (get_r(fdf->color_two) - get_r(fdf->color_one));
	g = get_g(fdf->color_one) + percent
		* (get_g(fdf->color_two) - get_g(fdf->color_one));
	b = get_b(fdf->color_one) + percent
		* (get_b(fdf->color_two) - get_b(fdf->color_one));
	return (create_trgb(255, (int)r, (int)g, (int)b));
}

int	get_color(t_fdf_params *fdf, int z)
{
	if (fdf->color_mode == SOLID)
	{
		if (z > (fdf->map.z_min + fdf->map.z_max) / 2)
			return (fdf->color_two);
		return (fdf->color_one);
	}
	else
		return (gradient(fdf, z));
}
