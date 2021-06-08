/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_len_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:16 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 16:07:07 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	int_len_base(size_t num)
{
	size_t i;

	i = 0;
	if (num < 0)
		i = 1;
	while (num /= 16)
		i++;
	return (++i);
}
