/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:54:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 09:29:10 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per(t_opt opt)
{
	char c;
	char space_zero;

	if (opt.zero == 1)
		space_zero = '0';
	else
		space_zero = ' ';
	opt.width--;
	c = '%';
	if (!(opt.left))
	{
		while (0 < opt.width--)
		{
			write(1, &space_zero, 1);
			g_ret++;
		}
	}
	write(1, &c, 1);
	g_ret++;
	while (0 < opt.width--)
	{
		write(1, " ", 1);
		g_ret++;
	}
}
