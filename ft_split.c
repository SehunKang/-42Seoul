/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:18:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/07 16:51:57 by sehkang          ###   ########.fr       */
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

static int	*add_arr(char const *str, char c, int len)
{
	int i;
	int j;
	int flag;
	int *add;

	add = (int *)malloc((len * 2) * sizeof(int));
	i = 0;
	j = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (flag == 0)
				add[j++] = i;
			flag = 1;
		}
		else
			if (flag == 1)
				add[j++] = i;
			flag = 0;
		i++;
	}
	return (add);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		*add;
	int		len;

	i = 0;
	len = arr_len(s, c);
	if (!(arr = (char **)malloc((len + 1) * sizeof(char*))))
		return (NULL);
	add = add_arr(s, c, len);
	while (i < len)
	{
		arr[i] = ft_substr(s, add[i * 2], add[i * 2 + 1] - add[i * 2]);
/*		if (!(arr[i]))
			while (i < 0)
				free(arr[i--]);
			free(arr);*/
		i++;
	}
/*	if (arr)
		arr[i] = NULL;
	free(add); */
	return (arr);
}
