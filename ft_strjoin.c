/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:05:05 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/06 16:53:45 by sehkang          ###   ########.fr       */
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
	(void)ft_strlcat(ret_ptr, s1, len);
	(void)ft_strlcat(ret_ptr, s2, len);
	return (ret_ptr);
}
