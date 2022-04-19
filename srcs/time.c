/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:44:40 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/18 15:17:10 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* This function give the delta between now and the time we start*/
long long	current_time(t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = (time_ms() - philo->infos->start_time);
	return (time_in_ms);
}

/* This function give the actual time in micro second */
long long	time_ms(void)
{
	struct timeval	time;
	long long		real_time;

	real_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		return (printf("gettimeofday failed.\n"));
	real_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (real_time);
}
