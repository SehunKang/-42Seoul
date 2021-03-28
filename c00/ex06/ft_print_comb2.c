/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:06:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/27 14:35:30 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_write_dec(int dec)
{
	int ten;
	int uni;

	if (dec < 10)
	{
		ft_putchar('0');
		ft_putchar(48 + dec);
	}
	else
	{
		ten = dec / 10;
		uni = dec % 10;
		ft_putchar(48 + ten);
		ft_putchar(48 + uni);
	}
}

void	ft_write_comb2(int l, int r)
{
	ft_write_dec(l);
	ft_putchar(' ');
	ft_write_dec(r);
	if (l != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int l;
	int r;

	l = 0;
	while (l <= 98)
	{
		r = l + 1;
		while (r <= 99)
		{
			ft_write_comb2(l, r);
			r++;
		}
		l++;
	}
}
