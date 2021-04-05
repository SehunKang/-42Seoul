/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:47:47 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/05 18:34:20 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_nbr(int nbr, char *base, int b_len)
{
	if (nbr == -2147483648)
	{
		ft_write_nbr(nbr / b_len, base, b_len);
		ft_putchar(base[-(nbr % b_len)]);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_write_nbr(-nbr, base, b_len);
	}
	else
	{
		if (nbr > b_len - 1)
			ft_write_nbr(nbr / b_len, base, b_len);
		ft_putchar(base[nbr % b_len]);
	}
}

int		ft_checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	b = ft_checkbase(base);
	if (b < 2)
		return ;
	ft_write_nbr(nbr, base, b);
}
