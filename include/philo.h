/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:17:24 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/18 07:27:56 by sehkang          ###   ########.fr       */
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

struct

typedef struct	s_info
{
	int	nb_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	is_number_to_eat;
	int	number_to_eat;
	



}	t_info;

int	arg_set(int argc, char **argv, t_info *info);
int	arg_check(t_info *info);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
#endif
