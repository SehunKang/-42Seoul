/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:33:53 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 13:01:55 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int value_a;
	int value_b;

	value_a = *a;
	value_b = *b;
	*a = value_a / value_b;
	*b = value_a % value_b;
}
