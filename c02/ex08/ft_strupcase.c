/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:11:40 by sehkang           #+#    #+#             */
/*   lowdated: 2021/03/29 19:20:13 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (65 < str[i] && str[i] < 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
int		main(void)
{
	char str[] = "Hello WORld 1234!\n";

	ft_strlowcase(str);
	printf("%s", str);
}

