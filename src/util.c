/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:16:00 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/24 01:57:19 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (0 < n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

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

time_t	get_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	arg_check(t_info *info)
{
	if (info->nb_philosophers < 0 || 10000 < info->nb_philosophers)
		return (1);
	if (info->time_to_die < 0 || MAX_TIME < info->time_to_die)
		return (1);
	if (info->time_to_eat < 0 || MAX_TIME < info->time_to_eat)
		return (1);
	if (info->time_to_sleep < 0 || MAX_TIME < info->time_to_sleep)
		return (1);
	if (info->is_number_to_eat == 1)
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
