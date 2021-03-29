/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:43:43 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 18:53:52 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 33 || 126 < str[i])
			return (0);
		i++;
	}
	return (1);
}

int main ()
{
	char *str1 = "ABC";
	char *str2 = "abc";
	char *str3 = "a\ta\0bc";
	char *str4 = "\0";

	printf("1 : %d\n", ft_str_is_printable(str1));
	printf("2 : %d\n", ft_str_is_printable(str2));
	printf("3 : %d\n", ft_str_is_printable(str3));
	printf("4 : %d\n", ft_str_is_printable(str4));

}
	
