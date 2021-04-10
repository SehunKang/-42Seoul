/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:46:07 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/05 18:44:55 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ')
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

int		ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int		ft_findbval(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int b_len;
	int value;
	int sign;
	int	b_index;

	value = 0;
	sign = 1;
	b_len = ft_checkbase(base);
	if (b_len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	while (ft_isneg(*str, &sign))
		str++;
	while ((b_index = ft_findbval(*str, base)) != -1)
	{
		value *= b_len;
		value += b_index;
		str++;
	}
	return (value * sign);
}
