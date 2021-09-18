/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:12:45 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/18 21:49:56 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	check_arg(int argc, char **argv, t_data *data)
{
	if (argv[1][0] == 'm')
	{
		if (argc != 2)
			wrong_parameter(1);
		if (ft_strlen(argv[1]) != 1)
			wrong_parameter(1);
		data->fractal = mandelbrot;
	}
	else if (argv[1][0] == 'j')
	{
		if (argc != 4)
			wrong_parameter(2);
		data->cx = julia_arg(argv[2], 'x');
		data->cy = julia_arg(argv[3], 'y');
		data->fractal = julia;
	}	
	else
		wrong_parameter(1);
}

void	wrong_parameter(int code)
{
	if (code == 1)
		printf("Available parameters : 'm' for Mandelbrot, 'j' for Julia\n");
	else if (code == 2)
	{
		printf("A real number and an imaginary number required for Julia set");
		printf(", e.g.*****./fract_ol j -0.5125 0.5213*****\n");
	}
	else if (code == 3)
		printf("Wrong parameter\n");
	exit(1);
}

double	julia_arg(char *str, char axis)
{
	int		i;
	int		j;
	int		sign;
	double	val;

	i = -1;
	j = 0;
	sign = 1;
	if (str[0] == '-')
		sign = i++;
	while (++i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && j == 0)
				j = i + 1;
			else
				wrong_parameter(3);
		}
	}
	if (j != 0)
		return (val = ft_atoi(str) + (ft_atoi(str + j)
				* (1 / pow(10, (ft_strlen(str) - j)))) * sign);
	else
		return (val = ft_atoi(str));
}
