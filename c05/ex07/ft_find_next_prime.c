/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:29:04 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 16:26:32 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long x;
	long y;

	x = nb;
	y = 1;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	while (x - y > 0)
	{
		x = (x + y) / 2;
		y = (long)nb / x;
	}
	return (x);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}
