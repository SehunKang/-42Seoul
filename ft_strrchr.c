/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:54:28 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/05 14:12:54 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*s_ptr;

	s_ptr = (char *)s;
	s_len = ft_strlen(s) + 1;
	s_ptr = s_ptr + s_len;
	while (0 < s_len--)
	{
		if (*s_ptr == c)
			return (s_ptr);
		s_ptr--;
	}
	return (NULL);
}
