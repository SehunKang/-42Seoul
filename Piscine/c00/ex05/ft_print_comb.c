/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:05:38 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/27 14:33:04 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_write_hund(char hun, char ten, char uni)
{
	ft_putchar(hun);
	ft_putchar(ten);
	ft_putchar(uni);
	if (hun != '7')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char hun;
	char ten;
	char uni;

	hun = '0';
	while (hun <= '7')
	{
		ten = hun + 1;
		while (ten <= '8')
		{
			uni = ten + 1;
			while (uni <= '9')
			{
				ft_write_hund(hun, ten, uni);
				uni++;
			}
			ten++;
		}
		hun++;
	}
}
