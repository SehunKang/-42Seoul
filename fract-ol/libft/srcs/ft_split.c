/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:18:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/31 20:40:39 by sehkang          ###   ########.fr       */
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

static void	add_arr(char const *str, char c, int *add)
{
	int	i;
	int	j;
	int	flag;
	int	len;

	len = ft_strlen(str) + 1;
	i = -1;
	j = 0;
	flag = 1;
	while (++i < len)
	{
		if (str[i] == c || str[i] == '\0')
		{
			if (flag == 0)
				add[j++] = i;
			flag = 1;
		}
		else
		{
			if (flag == 1)
				add[j++] = i;
			flag = 0;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		*add;
	int		len;

	i = -1;
	len = arr_len(s, c);
	arr = (char **)malloc((len + 1) * sizeof(char *));
	add = (int *)malloc((len * 2) * sizeof(int));
	add_arr(s, c, add);
	while (++i < len)
	{
		arr[i] = ft_substr(s, add[i * 2], add[i * 2 + 1] - add[i * 2]);
		if (!arr[i])
		{
			while (i < 0)
				free(arr[i--]);
			free(arr);
			return (NULL);
		}
	}
	arr[i] = NULL;
	free(add);
	return (arr);
}
