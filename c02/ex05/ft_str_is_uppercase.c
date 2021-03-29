/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:43:43 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 18:48:41 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || 90 < str[i])
			return (0);
		i++;
	}
	return (1);
}

int main ()
{
	char *str1 = "ABC";
	char *str2 = "abc";
	char *str3 = "Abc";
	char *str4 = "123";

	printf("1 : %d\n", ft_str_is_uppercase(str1));
	printf("2 : %d\n", ft_str_is_uppercase(str2));
	printf("3 : %d\n", ft_str_is_uppercase(str3));
	printf("4 : %d\n", ft_str_is_uppercacse(str4));

}
	
