/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:18:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/06 22:03:49 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_len(char const *str, char c)
{
	int		i;
	int		flag;
	int		len;

	i = 0;
	flag = 1;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
				len++;
			flag = 0;
		}
		i++;
	}
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	arr = (char **)malloc((arr_len(str, c) + 1) * sizeof(char*));

