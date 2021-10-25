/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:51:10 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/25 21:29:52 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		pthread_create(&(info.philosopher[i].thread), NULL,
			supper_ready, &(info.philosopher[i]));
		i++;
	}
	ft_sleep(50);
	philo_monitor(&info);
	philo_end(&info);
}
