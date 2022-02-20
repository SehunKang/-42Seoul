/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:05:55 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 20:29:59 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(va_list *ap, t_opt opt)
{
	char	*str;
	int		len;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	if (opt.precision < 0)
		opt.precision = ft_strlen(str);
	len = ft_strnlen(str, opt.precision);
	if (!(opt.left))
	{
		while (len < opt.width--)
		{
			write(1, " ", 1);
			g_ret++;
		}
	}
	write(1, str, len);
	g_ret += len;
	while (len < opt.width--)
	{
		write(1, " ", 1);
		g_ret++;
	}
}
