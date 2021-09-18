/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:51:45 by sehkang           #+#    #+#             */
/*   Updated: 2021/09/17 13:06:30 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	set_color(int n, t_data *data)
{
	int	i;
	int	color;

	if (data->color_set_nu == -1)
	{
		if (n == MAX_ITER)
			return (0);
		else
			return (n * 5);
	}
	else
	{
		if (n < MAX_ITER && n > 0)
		{
			i = n % 16;
			color = data->palette[i];
		}
		else
			color = 0;
	}
	return (color);
}

void	palette_zero(t_data *data)
{
	data->palette[0] = 0x421e0f;
	data->palette[1] = 0x19071a;
	data->palette[2] = 0x09012f;
	data->palette[3] = 0x04044a;
	data->palette[4] = 0x000764;
	data->palette[5] = 0x0c2c8a;
	data->palette[6] = 0x1852b1;
	data->palette[7] = 0x397dd1;
	data->palette[8] = 0x86b5e5;
	data->palette[9] = 0xd3ecf8;
	data->palette[10] = 0xf1e9bf;
	data->palette[11] = 0xf8c95f;
	data->palette[12] = 0xffaa00;
	data->palette[13] = 0xcc8000;
	data->palette[14] = 0x995700;
	data->palette[15] = 0x6a3400;
	data->color_set_nu = 0;
}

void	palette_one(t_data *data)
{
	data->palette[0] = 0xf09e38;
	data->palette[1] = 0xe93324;
	data->palette[2] = 0x5dca3c;
	data->palette[3] = 0x4eaced;
	data->palette[4] = 0xf9ed53;
	data->palette[5] = 0xa321e6;
	data->palette[6] = 0xea3368;
	data->palette[7] = 0xba3ff6;
	data->palette[8] = 0xf9ed53;
	data->palette[9] = 0xea3368;
	data->palette[10] = 0xec7c30;
	data->palette[11] = 0x4eac5c;
	data->palette[12] = 0xea4238;
	data->palette[13] = 0x1852b1;
	data->palette[14] = 0x397dd1;
	data->palette[15] = 0x86b5e5;
	data->color_set_nu = 1;
}

void	palette_two(t_data *data)
{
	data->palette[0] = 0x8ceafc;
	data->palette[1] = 0x69e4fb;
	data->palette[2] = 0x47ddfa;
	data->palette[3] = 0x24d7f9;
	data->palette[4] = 0x06cef3;
	data->palette[5] = 0x05b0d0;
	data->palette[6] = 0x8cd5fb;
	data->palette[7] = 0x6ac8fa;
	data->palette[8] = 0x47bbfa;
	data->palette[9] = 0x24aff9;
	data->palette[10] = 0x06a1f3;
	data->palette[11] = 0x058ad0;
	data->palette[12] = 0x0473ad;
	data->palette[13] = 0x035c8b;
	data->palette[14] = 0x024568;
	data->palette[15] = 0x012e45;
	data->color_set_nu = 2;
}

void	palette_three(t_data *data)
{
	data->palette[0] = 0x472300;
	data->palette[1] = 0xf90000;
	data->palette[2] = 0xf91f00;
	data->palette[3] = 0xf93e00;
	data->palette[4] = 0xf95e00;
	data->palette[5] = 0xf97d00;
	data->palette[6] = 0xff8f1e;
	data->palette[7] = 0xffa142;
	data->palette[8] = 0xffb266;
	data->palette[9] = 0xffc489;
	data->palette[10] = 0xd61a00;
	data->palette[11] = 0xd60000;
	data->palette[12] = 0xb20000;
	data->palette[13] = 0x8e0000;
	data->palette[14] = 0x6b0000;
	data->palette[15] = 0x470000;
	data->color_set_nu = 3;
}
