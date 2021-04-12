/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:09:13 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/12 18:07:27 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isspace(char c);
int		ft_isneg(char c, int *sign);
int		ft_checkbase(char *base);
int		ft_findbval(char c, char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_find_digitlen(int pre_val, int t_len)
{
	int i;
	int check_neg;

	check_neg = pre_val;
	if (pre_val < 0)
		pre_val = -pre_val;
	i = 1;
	while (t_len <= pre_val)
	{
		pre_val /= t_len;
		i++;
	}
	if (check_neg < 0)
		i++;
	return (i);
}

char	*ft_convert_value(int num, int b_len, int d_len, char *base)
{
	int i;
	char *r_val;

	i = 1;
	r_val = (char*)malloc(sizeof(char) * d_len + 1);
	while (i <= d_len)
	{
		r_val[d_len - i] = base[num % b_len];
		i++;
		num /= b_len;
	}
	r_val[d_len] = '\0';
	return (r_val);
}

char	*ft_convert_nvalue(int num, int b_len, int d_len, char *base)
{
	int i;
	char *r_val;

	i = 1;
	r_val = (char*)malloc(sizeof(char) * d_len + 1);
	num = -num;
	r_val[0] = '-';
	while (i < d_len)
	{
		r_val[d_len - i] = base[num % b_len];
		i++;
		num /= b_len;
	}
	r_val[d_len] = '\0';
	return (r_val);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_len;
	int		to_len;
	int		num;
	int		digit_len;

	from_len = ft_checkbase(base_from);
	to_len = ft_checkbase(base_to);
	if (from_len < 2 || to_len < 2)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	digit_len = ft_find_digitlen(num, to_len);
	if (num < 0)
		return (ft_convert_nvalue(num, to_len, digit_len, base_to));
	else
		return (ft_convert_value(num, to_len, digit_len, base_to));
}
