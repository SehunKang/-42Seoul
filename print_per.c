/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:54:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 20:44:24 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_per(s_opt opt)
{
	char c;

	opt.width--;
	c = '%';
	if (!(opt.left))
	{
		while (0 < opt.width--)
		{
			write(1, " ", 1);
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
