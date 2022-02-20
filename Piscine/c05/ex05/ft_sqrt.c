/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:27:03 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 18:51:54 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long i;

	long sqrt;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);

	i = 0;
	while((sqrt = i * i) <= (long)nb)
		i++;
	i--;
	if (i * i == nb)
		return (i);
	else
		return (0);
}
