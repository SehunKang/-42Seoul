/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:42:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/05 16:44:54 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_isneg(char c, int *sign)
{
	if (c == '+')
		return (1);
	else if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	return (0);
}

int		ft_isnum(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int value;
	int sign;

	value = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (ft_isneg(*str, &sign))
		str++;
	while (ft_isnum(*str))
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value * sign);
}
