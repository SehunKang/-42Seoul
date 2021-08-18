/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:05:05 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/20 19:30:42 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret_ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret_ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ret_ptr, s1, ft_strlen(s1));
	ft_memcpy(ret_ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ret_ptr[len] = '\0';
	return (ret_ptr);
}
