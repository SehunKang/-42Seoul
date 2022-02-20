/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:08:14 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/12 09:52:32 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int *arr;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (-1);
	*range = arr;
	i = 0;
	while (i <= size - 1)
	{
		arr[i] = min + i;
		i++;
	}
	return (size);
}
