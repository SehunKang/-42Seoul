/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:59:54 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/04 15:45:08 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *cp;

	cp = (unsigned char *)b;
	while (0 < len)
	{
		*cp++ = (unsigned char)c;
		len--;
	}
	return (b);
}
