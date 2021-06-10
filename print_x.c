/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:06:54 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 16:37:20 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(va_list *ap, t_opt opt)
{
	int				total_len;
	char			*str;
	int				str_len;
	int				max_len;
	unsigned int	origin;

	origin = va_arg(*ap, unsigned int);
	if (opt.precision == 0 && origin == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_x(origin);
	if (str == NULL)
		return ;
	str_len = ft_strlen(str);
	if (opt.precision >= 0)
		opt.zero = 0;
	if (opt.precision < 0)
		opt.precision = str_len;
	max_len = opt.precision > str_len ? opt.precision : str_len;
	total_len = max_len > opt.width ? max_len : opt.width;
	g_ret += total_len;
	print_out(str, &opt, max_len, total_len);
}
