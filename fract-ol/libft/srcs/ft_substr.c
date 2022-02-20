/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:47:41 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/31 20:45:11 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_ptr;
	size_t	ptr_len;

	if (len <= ft_strlen(s) - start)
		ptr_len = len;
	else
		ptr_len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	ret_ptr = (char *)malloc((ptr_len + 1) * sizeof(char));
	if (!ret_ptr)
		return (NULL);
	ret_ptr = (char *)ft_memcpy(ret_ptr, s + start, ptr_len);
	ret_ptr[ptr_len] = '\0';
	return (ret_ptr);
}
