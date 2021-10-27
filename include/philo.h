/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:17:24 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/27 15:08:55 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define MAX_TIME 3600000

typedef struct s_philosopher
{
	int				id;
	int				left_fork;
	int				right_fork;
	time_t			eat_time;
	int				eat_count;
	pthread_t		thread;
	struct s_info	*info;
}				t_philosopher;

typedef struct s_info
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				is_number_to_eat;
	int				number_to_eat;
	int				is_all_eat;
	int				is_dead;
	time_t			start_time;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
	t_philosopher	*philosopher;
}				t_info;

void	philo_monitor(t_info *info);
void	philo_end(t_info *info);
void	ft_sleep(time_t milisec);
void	philo_print(t_info *info, t_philosopher *philo, const char *str);
void	eat(t_info *info, t_philosopher *philo);
void	*supper_ready(void *arg);
time_t	get_time(void);
int		arg_set(int argc, char **argv, t_info *info);
int		arg_check(t_info *info);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		info_set(t_info *info);
void	set_philo(t_info *info, int index);

#endif
