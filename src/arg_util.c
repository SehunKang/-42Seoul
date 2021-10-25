/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:16:00 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/25 21:30:21 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	info->is_all_eat = 0;
	info->is_dead = 0;
	if (argc == 6)
	{
		info->is_number_to_eat = 1;
		info->number_to_eat = ft_atoi(argv[5]);
	}
	return (arg_check(info));
}

void	set_philo(t_info *info, int	index)
{
	info->philosopher[index].id = index;
	info->philosopher[index].left_fork = (index + info->nb_philosophers - 1)
		% info->nb_philosophers;
	info->philosopher[index].right_fork = index;
	info->philosopher[index].eat_count = 0;
	info->philosopher[index].info = info;
}

int	info_set(t_info *info)
{
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	philos = (t_philosopher *)malloc(sizeof(t_philosopher)
			* info->nb_philosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->nb_philosophers);
	if (philos == NULL || forks == NULL)
	{
		free(philos);
		free(forks);
		return (1);
	}
	info->fork = forks;
	info->philosopher = philos;
	while (i < info->nb_philosophers)
	{
		set_philo(info, i);
		pthread_mutex_init(&(info->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(info->eat), NULL);
	return (0);
}
