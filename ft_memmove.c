/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:43:36 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/04 20:53:17 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (i < len)
	{
		if (src < dst)
			tmp_dst[len - 1 - i] = tmp_src[len - 1 - i];
		else
			tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (dst);
}
