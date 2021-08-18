/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:35:33 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 16:20:31 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base_add(unsigned long long n)
{
	size_t	size;
	char	*ret_ptr;
	size_t	i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	size = int_len_base(n);
	size += 2;
	if (!(ret_ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret_ptr[size] = '\0';
	while (i < size--)
	{
		ret_ptr[size] = base[n % 16];
		n /= 16;
	}
	ret_ptr[0] = '0';
	ret_ptr[1] = 'x';
	return (ret_ptr);
}
