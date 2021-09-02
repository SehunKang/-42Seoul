/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:24:44 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/02 20:24:53 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

# define MAX_ITER 1000
# define SCALE 0.6
/* keycode values */
# define K_ESC 53 
# define K_SPACE 49
# define K_L 123
# define K_R 124
# define K_D 125
# define K_U 126
# define SCR_U 4
# define SCR_D 5

typedef struct s_axis
{
	double x0;
	double x1;
	double y0;
	double y1;

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
	int		(*fractal)(double, double, int);
	t_axis	axis;
}				t_data;

#endif
