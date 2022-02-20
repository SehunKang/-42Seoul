/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:05:40 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 20:28:15 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list *ap, s_opt opt)
{
	char c;

	opt.width--;
	c = va_arg(*ap, int);
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
