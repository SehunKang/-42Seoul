/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:30:20 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/31 14:07:48 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < (size) / 2)
	{
		temp = tab[i];
		tab[i] = tab[(size - 1) - i];
		tab[(size - 1) - i] = temp;
		i++;
	}
}
