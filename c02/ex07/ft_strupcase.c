/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:11:40 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 19:20:13 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (96 < str[i] && str[i] < 123)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
int		main(void)
{
	char str[] = "Hello World 1234!\n";

	ft_strupcase(str);
	printf("%s", str);
}

