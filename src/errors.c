/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:37 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 09:55:46 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf [filename]\n");
		exit_program(fdf, 0);
		return (0);
	}
	else
		fdf->map.map_name = ft_strdup(argv[1]);
	if (!fdf->map.map_name)
		error(3, 0, "Error while allocating memory for file name.");
	return (fdf);
}
