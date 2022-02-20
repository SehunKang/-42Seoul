/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:08:37 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/12 17:08:25 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_fullen(int size, char **strs, char *sep)
{
	int i;
	int fullen;

	i = 0;
	fullen = 0;
	while (i < size)
	{
		fullen += ft_strlen(strs[i]);
		i++;
	}
	fullen += ft_strlen(sep) * (size - 1);
	return (fullen);
}

char	*ft_strcpy(char *d_str, char *s_str)
{
	int i;
	
	i = 0;
	while (s_str[i])
	{
		d_str[i] = s_str[i];
		i++;
	}
	d_str[i] = '\0';
	return (d_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		full_len;
	char	*r_str;
	char	*cp_str;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	full_len = ft_fullen(size, strs, sep);
	if (!(r_str = (char *)malloc(sizeof(char) * (full_len + 1))))
		return (NULL);
	cp_str = r_str;
	i = 0;
	while (i < size)
	{
		ft_strcpy(cp_str, strs[i]);
		cp_str += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(cp_str, sep);
			cp_str += ft_strlen(sep);
		}
		i++;
	}
	*cp_str = '\0';
	return (r_str);
}
