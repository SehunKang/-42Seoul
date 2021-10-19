/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:20:58 by sehkang           #+#    #+#             */
/*   Updated: 2021/10/09 21:44:24 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	struct timeval time;
	long double before;
	long double after;

	gettimeofday(&time, NULL);
	before = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (after - before < 2000)
	{
		gettimeofday(&time, NULL);
		after = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		usleep(1);
	}
	gettimeofday(&time, NULL);
	after = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("%.Lf\n", after - before);



}
