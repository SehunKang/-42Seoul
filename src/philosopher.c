/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:29:18 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/26 15:57:06 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_info *info, t_philosopher *philo, const char *str)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->is_dead))
	{
		if (ft_strncmp(str, "died", 4) == 0)
			info->is_dead = 1;
		printf("%ld %d %s\n", get_time() - info->start_time, philo->id + 1, str);
	}
	pthread_mutex_unlock(&(info->print));
	return ;
}

void	eat(t_info *info, t_philosopher *philo)
{
	pthread_mutex_lock(&(info->fork[philo->left_fork]));
	philo_print(info, philo, "has taken a fork");
	pthread_mutex_lock(&(info->fork[philo->right_fork]));
	philo_print(info, philo, "has taken a fork");
	//pthread_mutex_lock(&(info->eat));
	philo->eat_time = get_time();
	philo->eat_count += 1;
	philo_print(info, philo, "is eating");
	//pthread_mutex_unlock(&(info->eat));
	ft_sleep(info->time_to_eat);
	pthread_mutex_unlock(&(info->fork[philo->left_fork]));
	pthread_mutex_unlock(&(info->fork[philo->right_fork]));
	return ;
}

void	*supper_ready(void *arg)
{
	t_info			*info;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	info = philo->info;
	philo->eat_time = info->start_time;
	if (philo->id % 2)
		usleep(100);
	while (!(info->is_dead))
	{
		eat(info, philo);
		if (info->is_number_to_eat)
			if (philo->eat_count == info->number_to_eat)
				return (NULL);
		philo_print(info, philo, "is sleeping");
		ft_sleep(info->time_to_sleep);
		philo_print(info, philo, "is thinking");
	}
	return (NULL);
}

void	philo_monitor(t_info *info)
{
	int	i;
	int	total_eat;

	while (1)
	{
		i = 0;
		total_eat = 0;
		while (i < info->nb_philosophers)
		{
			if (get_time() - info->philosopher[i].eat_time > info->time_to_die)
			{
	//			pthread_mutex_lock(&(info->eat));
				philo_print(info, &(info->philosopher[i]), "died");
	//			pthread_mutex_unlock(&(info->eat));
				return ;
			}
			total_eat += info->philosopher[i].eat_count;
			if (total_eat == info->number_to_eat * info->nb_philosophers)
			{
				info->is_all_eat = 1;
				return ;
			}
			i++;
		}
	}
}

void	philo_end(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philosophers)
	{
		if (pthread_mutex_destroy(&(info->fork[i])))
		{
			pthread_mutex_unlock(&info->fork[i]);
			pthread_mutex_destroy(&(info->fork[i]));
		}
		i++;
	}
	i = 0;
	while (i < info->nb_philosophers)
	{
		pthread_join(info->philosopher[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&(info->eat));
	free(info->fork);
	free(info->philosopher);
	return ;
}
