/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:13:24 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/11 15:58:09 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h_ptr;
	char	*n_ptr;
	size_t	i;

	h_ptr = (char *)haystack;
	n_ptr = (char *)needle;
	i = 0;
	if (*n_ptr == '\0')
		return (h_ptr);
	while (0 < len && h_ptr[i] != 0)
	{
		if (*h_ptr == *n_ptr)
		{
			while (h_ptr[i] == n_ptr[i] && i < len)
			{
				i++;
				if (n_ptr[i] == '\0')
					return (h_ptr);
			}
			i = 0;
		}
		h_ptr++;
		len--;
	}
	return (NULL);
}
