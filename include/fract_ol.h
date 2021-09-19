/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:24:44 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/19 10:58:02 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

# define MAX_ITER 1000
# define SCALE 0.6
# define K_ESC 53 
# define K_SPACE 49
# define K_L 123
# define K_R 124
# define K_D 125
# define K_U 126
# define K_C 8
# define SCR_U 4
# define SCR_D 5

typedef struct s_axis
{
	double	x0;
	double	x1;
	double	y0;
	double	y1;

}				t_axis;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_x;
	int		win_y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		(*fractal)(double, double, struct s_data *data);
	t_axis	axis;
	int		palette[16];
	int		color_set_nu;
	double	cx;
	double	cy;
}				t_data;

void	arrows(int keycode, t_data *data);
int		key(int keycode, t_data *data);
void	color_set(t_data *data);
int		wheel(int button, int x, int y, t_data *data);
int		mandelbrot(double a, double b, t_data *data);
int		burning_ship(double a, double b, t_data *data);
int		julia(double a, double b, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	default_axis(t_data *data);
void	check_arg(int argc, char **argv, t_data *data);
void	draw_fractal(t_data *data);
int		set_color(int n, t_data *data);
void	palette_zero(t_data *data);
void	palette_one(t_data *data);
void	palette_two(t_data *data);
void	palette_three(t_data *data);
double	julia_arg(char *str, char axis);
void	wrong_parameter(int code);
void	zoom_in(t_data *data, int x, int y);
void	zoom_out(t_data *data, int x, int y);
#endif
