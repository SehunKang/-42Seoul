/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:20:26 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 09:20:31 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int val;

	i = 0;
	val = 1;
	if (nb < 0)
		return (0);
	while (++i != nb + 1)
		val *= i;
	return (val);
}
