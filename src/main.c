/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:28:19 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/12 20:15:04 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst =  color;
}

void	default_axis(t_data *data)
{
	data->axis.x0 = -2.0;
	data->axis.x1 = 1.0;
	data->axis.y0 = -1.0;
	data->axis.y1 = 1.0;
}

void	check_arg(int argc, char **argv, t_data *data)
{
	if (argc != 2)
	{
		printf("Available parameters : 'm' for Mandelbrot, 'j' for Julia\n");
		exit(0); 
	}
	if (ft_strlen(argv[1]) != 1)
	{
		printf("Available parameters : 'm' for Mandelbrot, 'j' for Julia\n");
		exit(1); 
	}
	if (argv[1][0] == 'm')
		data->fractal = mandelbrot;
//	else if (argv[1][0] == 'j')
//		data->fractal = julia;
	else
	{
		printf("Available parameters : 'm' for Mandelbrot, 'j' for Julia\n");
		exit(1); 
	}
}

void	draw_fractal(t_data *data, t_axis *ax)
{
	double	px;
	double	py;
	double	x;
	double	y;
	int		n;

	px = 0;
	py = 0;
	while (px < data->win_x)
	{
		while (py < data->win_y)
		{
			x = px * (ax->x1 - ax->x0) / data->win_x + ax->x0; 
			y = (data->win_y - py) * (ax->y1 - ax->y0) / data->win_y + ax->y0;
			n = data->fractal(x, y, MAX_ITER);
			if (n == MAX_ITER)
				my_mlx_pixel_put(data, px, py, 0x00000000);
			else
				my_mlx_pixel_put(data, px, py, 0x000000F0 + n * 10);
			py++;
		}
		px++;
		py = 0;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_arg(argc, argv, &data);
	data.mlx = mlx_init();
	mlx_get_screen_size(data.mlx, &data.win_x, &data.win_y);
	data.win_x *= SCALE;
	data.win_y *= SCALE;
	data.mlx_win = mlx_new_window(data.mlx, data.win_x, data.win_y, "fract-ol");
	data.img = mlx_new_image(data.mlx, data.win_x, data.win_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
									&data.line_length, &data.endian);
	default_axis(&data);
	draw_fractal(&data, &data.axis);
	mlx_hook(data.mlx_win, 2, 1L<<0, key, &data);
	mlx_hook(data.mlx_win, 4, 1L<<2, wheel, &data);
	mlx_loop(data.mlx);
}
