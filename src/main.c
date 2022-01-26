/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:49:50 by marcrodr          #+#    #+#             */
/*   Updated: 2022/01/26 16:15:04 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minilibx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int mouse_hook(int keycode, t_vars *vars)
{
	if (keycode == 1)
		printf("Hello from mouse_1!\n");
	else
		printf("Hello from mouse_hook!\n");
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int 	y;
	int 	z;
	t_vars	vars;


	y = 500;
	x = 300;
	z = 200;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);


/*	img.img = mlx_new_image(mlx, 1920, 1080);

	
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 500)
	{
		
		my_mlx_pixel_put(&img, x, y, create_trgb(0, 255, 255, 0)); 
		my_mlx_pixel_put(&img, 300, y, create_trgb(0, 0, 255, 0));
		my_mlx_pixel_put(&img, x, 700, create_trgb(0, 0, 0, 255));
	//	my_mlx_pixel_put(&img, 500, y, 0xFF0000);

		x++;
		y++;
	}
	
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);*/
	mlx_loop(vars.mlx);
}