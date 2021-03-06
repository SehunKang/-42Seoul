/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:35:33 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 10:25:56 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(long long n)
{
	int		size;
	char	*ret_ptr;
	int		i;

	i = 0;
	size = int_len(n);
	if (!(ret_ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret_ptr[size] = '\0';
	if (n < 0)
	{
		ret_ptr[i++] = '-';
		n = -n;
	}
	while (i < size--)
	{
		ret_ptr[size] = '0' + n % 10;
		n /= 10;
	}
	return (ret_ptr);
}
