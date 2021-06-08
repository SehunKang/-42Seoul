/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_capx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:07:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 20:28:41 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_capx(va_list *ap, s_opt opt)
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
		str = ft_itoa_base_capx(origin);
	str_len = ft_strlen(str);
	if (opt.precision >= 0)
		opt.zero = 0;
	if (opt.precision < 0)
		opt.precision = str_len;
	max_len = opt.precision > str_len ? opt.precision : str_len;
	total_len = max_len > opt.width ? max_len : opt.width;
	print_out(str, &opt, max_len, total_len);
	g_ret += total_len;
}
