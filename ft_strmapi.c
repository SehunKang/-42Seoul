/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 22:14:16 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/09 20:39:28 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret_ptr;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	if (!(ret_ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ret_ptr[i] = f(i, s[i]);
		i++;
	}
	ret_ptr[i] = '\0';
	return (ret_ptr);
}
