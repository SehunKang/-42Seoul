/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:16 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/09 10:28:16 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_len_base(long long num)
{
	int	i;

	i = 0;
	if (num < 0)
		i = 1;
	while (num /= 16)
		i++;
	return (++i);
}
