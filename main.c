#include <mlx.h>




typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int 	y;
	int 	r;

	y = 500;
	x = 300;
	r = 200;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 500)
	{
		my_mlx_pixel_put(&img, x, 500, 0x00FF0000);
		my_mlx_pixel_put(&img, 300, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x, 700, 0x00FF0000);
		my_mlx_pixel_put(&img, 500, y, 0x00FF0000);

		x++;
		y++;
	}

		my_mlx_pixel_put(&img, 2, 3, 0x00FF0000);
		my_mlx_pixel_put(&img, 3, 2, 0x00FF0000);
		my_mlx_pixel_put(&img, 4, 2, 0x00FF0000);
		my_mlx_pixel_put(&img, 5, 3, 0x00FF0000);
		my_mlx_pixel_put(&img, 5, 4, 0x00FF0000);
		my_mlx_pixel_put(&img, 4, 5, 0x00FF0000);
		my_mlx_pixel_put(&img, 3, 5, 0x00FF0000);
		my_mlx_pixel_put(&img, 2, 4, 0x00FF0000);


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}