/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:23:33 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 11:35:37 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int base;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	base = nb;
	while (i++ < power)
		nb *= base;
	return (nb);
}
