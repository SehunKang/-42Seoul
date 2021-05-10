/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:35:33 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/09 21:11:38 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int num)
{
	int i;

	i = 0;
	if (num == -2147383648)
		return (11);
	if (num < 0)
		i = 1;
	while (num /= 10)
		i++;
	return (++i);
}

static void	num_arr(int n, int size, char *ptr)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		ptr[--size] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	else if (n == 0)
		ptr[0] = '0';
	while (0 < n)
	{
		ptr[--size] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	int		size;
	char	*ret_ptr;
	int		i;

	i = 0;
	size = int_len(n);
	if (!(ret_ptr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	num_arr(n, size, ret_ptr);
	ret_ptr[size] = '\0';
	return (ret_ptr);
}
