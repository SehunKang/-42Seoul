/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:37:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 16:35:35 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_ret;

void		print_out(char *str, t_opt *opt, int max_len, int total_len)
{
	if (!(opt->left))
		if (opt->zero == 1)
		{
			check_print_neg(str[0]);
			while (max_len < total_len--)
				write(1, "0", 1);
		}
		else
		{
			while (max_len < total_len--)
				write(1, " ", 1);
			check_print_neg(str[0]);
		}
	else
		check_print_neg(str[0]);
	while ((int)ft_strlen(str) < opt->precision--)
		write(1, "0", 1);
	if (str[0] == '-')
		write(1, str + 1, ft_strlen(str + 1));
	else
		write(1, str, ft_strlen(str));
	while (max_len < total_len--)
		write(1, " ", 1);
	free(str);
}

int			check_spec(char c, va_list *ap, t_opt opt)
{
	if (c == 'c')
		print_c(ap, opt);
	else if (c == 's')
		print_s(ap, opt);
	else if (c == 'p')
		print_p(ap, opt);
	else if (c == 'd' || c == 'i')
		print_d(ap, opt);
	else if (c == 'u')
		print_u(ap, opt);
	else if (c == 'x')
		print_x(ap, opt);
	else if (c == 'X')
		print_capx(ap, opt);
	else if (c == '%')
		print_per(opt);
	else
		return (0);
	return (1);
}

const char	*check_opt(const char *str, va_list *ap)
{
	t_opt		opt;
	const char	*tmp;

	tmp = str;
	str++;
	set_opt(&opt);
	str = check_flag(str, &opt);
	str = check_width(str, &opt, ap);
	str = check_prec(str, &opt, ap);
	if (!(check_spec(*str, ap, opt)))
		return (++tmp);
	str++;
	return (str);
}

int			ft_printf(const char *str, ...)
{
	va_list ap;

	g_ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			str = check_opt(str, &ap);
		else
		{
			write(1, str, 1);
			g_ret++;
			str++;
		}
	}
	va_end(ap);
	return (g_ret);
}
