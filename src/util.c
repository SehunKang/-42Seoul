/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:16:00 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/18 07:27:49 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int val;
	int sign;

	val = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			val *= 10;
			val += *str - '0';
		}
		else
			return (-1);
		str++;
	}
	return (sign * val);
}

int	arg_check(t_info *info)
{
	if (info->nb_philosphers < 0 || 200 < info->nb_philosophers)
		return (1);
	if (info->time_to_die < 0 || MAX_TIME < info->time_to_die)
		return (1);
	if (info->time_to_eat < 0 || MAX_TIME < info->time_to_eat)
		return (1);
	if (info->time_to_sleep < 0 || MAX_TIME < info->time_to_sleep)
		return (1);
	if (is_number_to_eat == 1)
		if (info->number_to_eat < 0)
			return (1);
	return (0);
}

int	arg_set(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (1);
	info->nb_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->is_number_to_eat = 0;
	info->number_to_eat = -1;
	if (argc == 6)
	{
		info->is_number_to_eat = 1;
		info->number_to_eat = ft_atoi(argv[5]);	
	}
	return (arg_check(info));
}
