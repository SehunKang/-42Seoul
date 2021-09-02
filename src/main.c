/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 22:28:19 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/02 20:26:24 by sehkang          ###   ########.fr       */
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

int	mandelbrot(double a, double b, int max)
{
	int		i; 
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = 0;
	y = 0;
	while (i < MAX_ITER)
	{
		if (x * x + y * y > 4)
			return (i);
		tmp = x * x - y * y + a;
		y = 2 * x * y + b;
		x = tmp;
		i++;
	}
	return (MAX_ITER);
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

void	arrows(int keycode, t_data *data)
{
	double	x_len;
	double	y_len;

	x_len = data->axis.x1 - data->axis.x0;
	y_len = data->axis.y1 - data->axis.y0;
	if (keycode == K_L)
	{
		data->axis.x0 -= x_len * 0.3;
		data->axis.x1 -= x_len * 0.3;
	}
	else if (keycode == K_R)
	{
		data->axis.x0 += x_len * 0.3;
		data->axis.x1 += x_len * 0.3;
	}
	else if (keycode == K_U)
	{
		data->axis.y0 += y_len * 0.3;
		data->axis.y1 += y_len * 0.3;
	}
	else if (keycode == K_D)
	{
		data->axis.y0 -= y_len * 0.3;
		data->axis.y1 -= y_len * 0.3;
	}
	draw_fractal(data, &data->axis);
}

int	key(int keycode, t_data *data)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	else if (keycode == K_SPACE)
	{
		default_axis(data);
		draw_fractal(data, &data->axis);
	}
	else if (123 <= keycode && keycode <= 126)/* represnt arrows*/
		arrows(keycode, data);
	return (0);
}

int	wheel(int button, int x, int y, t_data *data)
{
	double	px;
	double	py;
	double	x_len;
	double	y_len;

	x_len = (data->axis.x1 - data->axis.x0);
	y_len = (data->axis.y1 - data->axis.y0);
	px = x * (data->axis.x1 - data->axis.x0) / data->win_x + data->axis.x0;
	py = y * (data->axis.y1 - data->axis.y0) / data->win_y + data->axis.y0;
	if (button == SCR_U)
	{
		data->axis.x0 = px - (x_len) * 0.4;
		data->axis.x1 = px + (x_len) * 0.4;
		data->axis.y0 = py - (y_len) * 0.4;
		data->axis.y1 = py + (y_len) * 0.4;
	}
	else if (button == SCR_D)
	{
		data->axis.x0 = data->axis.x0 - (x_len) * 0.125;
		data->axis.x1 = data->axis.x1 + (x_len) * 0.125;
		data->axis.y0 = data->axis.y0 - (y_len) * 0.125;
		data->axis.y1 = data->axis.y1 + (y_len) * 0.125;
	}
	draw_fractal(data, &data->axis);
	return (0);
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
