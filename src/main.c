/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:51:10 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/24 02:13:38 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_info *info, int	index)
{
	info->philosopher[index].id = index;
	info->philosopher[index].left_fork = (index + info->nb_philosophers - 1) % info->nb_philosophers;
	info->philosopher[index].right_fork = index + 1;
	info->philosopher[index].eat_count = 0;
	info->philosopher[index].info = info;
}

int	info_set(t_info *info)
{
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	philos = (t_philosopher *)malloc(sizeof(t_philosopher) * info->nb_philosophers);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->nb_philosophers);
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
	pthread_mutex_init(&(info->print), NULL);
	info->is_all_eat = 0;
	info->is_dead = 0;
	return (0);
}

void	ft_sleep(time_t milisec)
{
	time_t	start_time;

	start_time = get_time();
	while (1)
	{
		if (milisec < get_time() - start_time)
			return ;
		usleep(10);
	}
	return ;
}

void	philo_print(t_info *info, t_philosopher *philo, const char *str)
{
	pthread_mutex_lock(&(info->print));
	if (!(info->is_dead))
	{
		if (ft_strncmp(str, "died", 4) == 0)
			info->is_dead = 1;
		printf("%ld %d %s\n", get_time() - info->start_time, philo->id, str);
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
	philo->eat_time = get_time();
	philo_print(info, philo, "is eating");
	ft_sleep(info->time_to_eat);
	philo->eat_count += 1;
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
	if (philo->id % 2)
		usleep(100);
	while (!(info->is_dead))
	{
		eat(info, philo);
		if (info->is_number_to_eat)
			if (info->is_all_eat)
				return (NULL);
		philo_print(info, philo, "is sleeping");
		ft_sleep(info->time_to_sleep);
		philo_print(info, philo, "is thinking");
	}
	return (NULL); 
}

void	philo_monitor(t_info *info)
{
	int i;
	int	total_eat;

	while (1)
	{
		i = 0;
		total_eat = 0;
		while (i < info->nb_philosophers)
		{
			if (get_time() - info->philosopher[i].eat_time > info->time_to_die)
			{
				philo_print(info, &(info->philosopher[i]), "died");
				return ;
			}//usleep을 통해 식사시간과 동기화 할 수 있을까?
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
	int i;

	i = 0;
	while (i < info->nb_philosophers)
	{
		pthread_join(info->philosopher[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < info->nb_philosophers)
	{
		pthread_mutex_destroy(&(info->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(info->print));
	return ;
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;
	
	if (arg_set(argc, argv, &info))
	{
		printf("Wrong input\n");
		return (1);
	}
	if (info_set(&info))
	{
		printf("ERROR\n");
		return (1);
	}
	i = 0;
	info.start_time = get_time();
	while (i < info.nb_philosophers)
	{
		info.philosopher[i].eat_time = info.start_time;
		pthread_create(&(info.philosopher[i].thread), NULL, supper_ready, &(info.philosopher[i]));
		i++;
	}
	philo_monitor(&info);
	philo_end(&info);	
}
