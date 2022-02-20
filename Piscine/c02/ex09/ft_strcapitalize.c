/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:39:27 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/04 12:39:16 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_alphanum(char c)
{
	int i;

	i = 0;
	if ((64 < c && c < 90) || (96 < c && c < 123))
		i++;
	else if (47 < c && c < 58)
		i++;
	return (i);
}

int		ft_char_is_cap(char c)
{
	int i;

	i = 0;
	if (64 < c && c < 91)
		i++;
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_cap(str[i]))
			str[i] += 32;
		if (ft_char_is_alphanum(str[i]))
			j++;
		if (!(ft_char_is_alphanum(str[i])))
		{
			if (96 < str[i - j] && str[i - j] < 123)
				str[i - j] = str[i - j] - 32;
			j = 0;
		}
		i++;
	}
	if (i != 0 && str[i] == '\0')
		if (96 < str[i - j] && str[i - j] < 123)
			str[i - j] = str[i - j] - 32;
	return (str);
}
