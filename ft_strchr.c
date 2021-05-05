/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:34:45 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/05 13:52:00 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *s_ptr;

	s_ptr = (char *)s;
	while (*s_ptr)
	{
		if (*s_ptr == c)
			return (s_ptr);
		s_ptr++;
	}
	return (NULL);
}
