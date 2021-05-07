/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:56:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/06 20:16:20 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*ret_ptr;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[s1_len - j - 1]) && s1[s1_len - j - 1])
		j++;
	if (i + j < s1_len)
		ret_ptr = ft_substr(s1, i, s1_len - i - j);
	else
		return (ret_ptr = (char *)ft_calloc(1, 1));
	return (ret_ptr);
}
