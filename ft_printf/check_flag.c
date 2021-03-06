/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:52:32 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 09:31:25 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_opt(t_opt *opt)
{
	opt->left = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->precision = -1;
}

const char	*check_width(const char *str, t_opt *opt, va_list *ap)
{
	if (ft_isdigit(*str))
	{
		while (ft_isdigit(*str))
		{
			opt->width *= 10;
			opt->width += *str - '0';
			str++;
		}
	}
	else if (*str == '*')
	{
		if ((opt->width = va_arg(*ap, int)) < 0)
		{
			opt->width *= -1;
			opt->left |= 1;
		}
		str++;
	}
	return (str);
}

const char	*check_prec(const char *str, t_opt *opt, va_list *ap)
{
	if (*str == '.')
	{
		str++;
		opt->precision = 0;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
			{
				opt->precision *= 10;
				opt->precision += *str - '0';
				str++;
			}
		}
		else if (*str == '*')
		{
			opt->precision = va_arg(*ap, int);
			str++;
		}
	}
	return (str);
}

const char	*check_flag(const char *str, t_opt *opt)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
		{
			opt->left = 1;
			str++;
		}
		if (*str == '0')
		{
			opt->zero = 1;
			str++;
		}
	}
	return (str);
}
