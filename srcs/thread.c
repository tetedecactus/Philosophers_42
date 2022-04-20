/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:21:14 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/20 17:16:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_dead(void *data)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)data;
	stop = 0;
	while (!stop)
	{
		pthread_mutex_lock(&philo->infos->meal_check);
		if (time_ms() - philo->time_last_meal >= philo->infos->tt_die)
		{
			pthread_mutex_unlock(&philo->infos->meal_check);
			print_status(philo, DEAD, 1);
		}
		else
			pthread_mutex_unlock(&philo->infos->meal_check);
		pthread_mutex_lock(&philo->infos->is_dead);
		stop = philo->infos->stop + philo->stop;
		pthread_mutex_unlock(&philo->infos->is_dead);
	}
	return (NULL);
}

void	routine_poutine(t_philo *philo)
{
	int	stop;

	stop = 0;
	while (!stop)
	{
		check_hand(philo);
		if (philo->infos->num_must_eat != -1 \
			&& philo->x_ate == philo->infos->num_must_eat)
		{
			pthread_mutex_lock(&philo->infos->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->infos->is_dead);
			return ;
		}
		print_status(philo, SLEEP, 0);
		ft_usleep(philo->infos->tt_sleep);
		print_status(philo, THINK, 0);
		pthread_mutex_lock(&philo->infos->is_dead);
		stop = philo->infos->stop + philo->stop;
		pthread_mutex_unlock(&philo->infos->is_dead);
	}
	return ;
}

void	*poutine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->time_last_meal = philo->infos->start_time;
	if (pthread_create(&philo->checker, NULL, &is_dead, philo))
		return (NULL);
	routine_poutine(philo);
	pthread_detach(philo->checker);
	return (NULL);
}
