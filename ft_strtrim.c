/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:56:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/18 14:43:07 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1_len - j > 0 && ft_strchr(set, s1[s1_len - j - 1]))
		j++;
	if (i + j < s1_len)
		return (ft_substr(s1, i, s1_len - i - j));
	else
		return (ft_strdup(""));
}
