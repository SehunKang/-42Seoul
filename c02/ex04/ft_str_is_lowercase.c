/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:43:43 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/29 18:50:04 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || 122 < str[i])
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

	printf("1 : %d\n", ft_str_is_lowercase(str1));
	printf("2 : %d\n", ft_str_is_lowercase(str2));
	printf("3 : %d\n", ft_str_is_lowercase(str3));
	printf("4 : %d\n", ft_str_is_lowercase(str4));

}
	
