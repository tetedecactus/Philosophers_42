/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/18 16:33:56 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	right_handed(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK, 0);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		ft_usleep(philo->infos->tt_die);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, FORK, 0);
	print_status(philo, EAT, 0);
	philo->x_ate++;
	philo->time_last_meal = time_ms();
	ft_usleep(philo->infos->tt_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	left_handed(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, FORK, 0);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_usleep(philo->infos->tt_die);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, FORK, 0);
	print_status(philo, EAT, 0);
	philo->x_ate++;
	philo->time_last_meal = time_ms();
	ft_usleep(philo->infos->tt_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	check_hand(t_philo *philo)
{
	if (philo->id % 2 == 0)
		right_handed(philo);
	else
		left_handed(philo);
}
