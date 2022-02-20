/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:24:11 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/18 21:15:32 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	mandelbrot(double a, double b, t_data *data)
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

int	julia(double a, double b, t_data *data)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = a;
	y = b;
	while (i < MAX_ITER)
	{
		if (x * x + y * y >= 4)
			return (i);
		tmp = x * x - y * y;
		y = 2 * x * y + data->cy;
		x = tmp + data->cx;
		i++;
	}
	return (MAX_ITER);
}

int	burning_ship(double a, double b, t_data *data)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = a;
	y = b;
	while (i < MAX_ITER)
	{
		if (x * x + y * y >= 4)
			return (i);
		tmp = x * x - y * y + a;
		y = fabs(2 * x * y) + b;
		x = tmp;
		i++;
	}
	return (MAX_ITER);
}
