/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:08:04 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/12 09:50:57 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max)
{
	int					*arr;
	unsigned int		size;
	unsigned int		i;

	if (max <= min)
		return (NULL);
	size = max - min;
	if (!(arr = malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int		main(void)
{
	int *arr;
	int i;

	arr = ft_range(2147483640, 217483647);
	i = 0;
	while (i <= 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
}
