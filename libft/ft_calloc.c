/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:22:52 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/06 14:17:46 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t counts, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(counts * size)))
		return (NULL);
	ft_bzero(ptr, counts * size);
	return (ptr);
}
