/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:13:50 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/18 21:12:46 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
		draw_fractal(data);
	}
	else if (keycode == K_C)
	{
		color_set(data);
		draw_fractal(data);
	}
	else if (123 <= keycode && keycode <= 126)
	{
		arrows(keycode, data);
		draw_fractal(data);
	}
	return (0);
}

void	color_set(t_data *data)
{
	if (data->color_set_nu == -1)
		palette_zero(data);
	else if (data->color_set_nu == 0)
		palette_one(data);
	else if (data->color_set_nu == 1)
		palette_two(data);
	else if (data->color_set_nu == 2)
		palette_three(data);
	else if (data->color_set_nu == 3)
		data->color_set_nu = -1;
}
