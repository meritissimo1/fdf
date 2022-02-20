/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:37 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/20 08:09:16 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("WE ENCOURAGE ALL MAPS SHOULD BE INSIDE 'maps' FOLDER\n");
		ft_printf("Usage: ./fdf [file]\n");
		exit_program(fdf, 1);
	}
	else
		fdf->map.path = ft_strdup(argv[1]);
	if (!fdf->map.path)
		exit(3);
	return (fdf);
}
