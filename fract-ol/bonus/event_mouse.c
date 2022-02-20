/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:11:59 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/18 21:12:36 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	wheel(int button, int x, int y, t_data *data)
{
	if (button == SCR_U)
		zoom_in(data, x, y);
	else if (button == SCR_D)
		zoom_out(data, x, y);
	draw_fractal(data);
	return (0);
}

void	zoom_in(t_data *data, int x, int y)
{
	double	px;
	double	py;
	double	x_len;
	double	y_len;

	x_len = fabs(data->axis.x1 - data->axis.x0);
	y_len = fabs(data->axis.y1 - data->axis.y0);
	px = x * (x_len / data->win_x) + data->axis.x0;
	py = y * (y_len / data->win_y) + data->axis.y0;
	if (data->fractal == burning_ship)
		py = (data->win_y - y) * (y_len / data->win_y) + data->axis.y0;
	data->axis.x0 = px - (x_len * 0.4);
	data->axis.x1 = px + (x_len * 0.4);
	data->axis.y0 = py - (y_len * 0.4);
	data->axis.y1 = py + (y_len * 0.4);
}

void	zoom_out(t_data *data, int x, int y)
{
	double	px;
	double	py;
	double	x_len;
	double	y_len;

	x_len = fabs(data->axis.x1 - data->axis.x0);
	y_len = fabs(data->axis.y1 - data->axis.y0);
	px = x * (x_len / data->win_x) + data->axis.x0;
	py = y * (y_len / data->win_y) + data->axis.y0;
	if (data->fractal == burning_ship)
		py = (data->win_y - y) * (y_len / data->win_y) + data->axis.y0;
	data->axis.x0 = data->axis.x0 - (x_len) * 0.125;
	data->axis.x1 = data->axis.x1 + (x_len) * 0.125;
	data->axis.y0 = data->axis.y0 - (y_len) * 0.125;
	data->axis.y1 = data->axis.y1 + (y_len) * 0.125;
}
