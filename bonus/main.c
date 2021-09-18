/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:28:19 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/18 22:11:18 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	default_axis(t_data *data)
{
	if (data->fractal == mandelbrot)
	{
		data->axis.x0 = -2.0;
		data->axis.x1 = 1.0;
		data->axis.y0 = -1.0;
		data->axis.y1 = 1.0;
	}
	else if (data->fractal == julia)
	{
		data->axis.x0 = -2.25;
		data->axis.x1 = 2.25;
		data->axis.y0 = -1.5;
		data->axis.y1 = 1.5;
	}
	else if (data->fractal == burning_ship)
	{
		data->axis.x0 = -2.2;
		data->axis.x1 = 1.65;
		data->axis.y0 = -1.65;
		data->axis.y1 = 0.55;
	}
}

void	draw_fractal(t_data *data)
{
	double	px;
	double	py;
	double	x;
	double	y;
	int		n;

	px = -1;
	py = -1;
	while (++px < data->win_x)
	{
		while (++py < data->win_y)
		{
			x = px * ((data->axis.x1 - data->axis.x0) / data->win_x)
				+ data->axis.x0;
			y = (data->win_y - py) * ((data->axis.y1 - data->axis.y0)
					/ data->win_y) + data->axis.y0;
			if (data->fractal == burning_ship)
				y = py * ((data->axis.y1 - data->axis.y0)
						/ data->win_y) + data->axis.y0;
			n = data->fractal(x, y, data);
			my_mlx_pixel_put(data, px, py, set_color(n, data));
		}
		py = -1;
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
	data.color_set_nu = -1;
	draw_fractal(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key, &data);
	mlx_hook(data.mlx_win, 4, 1L << 2, wheel, &data);
	mlx_loop(data.mlx);
}
