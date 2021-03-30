/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 10:08:01 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 09:36:02 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 9 && nb >= 0)
	{
		ft_putchar(48 + (nb % 10));
	}
	else if (nb != -2147483648)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		ft_putnbr(nb / 10);
		ft_putchar(48 + (nb % 10));
	}
	else if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
}
int main()
{
	ft_putnbr(02345);
}

