/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:29:04 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 18:46:22 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long i;
	long sqrt;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	i = 0;
	while ((sqrt = i * i) <= (long)nb)
		i++;
	i--;
	return (i);
}

int		ft_is_prime(int nb)
{
	int i;
	int sqrt;

	i = 2;
	if (nb < 2)
		return (0);
	sqrt = ft_sqrt(nb);
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
