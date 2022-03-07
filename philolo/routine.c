/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/05 14:41:30 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*think(t_philo *philo)
{
	print_status(philo, SLEEP);
}
void	*sleep_dodo(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->info->tt_sleep);
}

void 	*eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->fork_l]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->info->fork[philo->fork_r]);
	print_status(philo, FORK);
	philo->timer = time_ms();
	print_status(philo, EAT);
	ft_usleep(philo->info->tt_eat);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info->fork[philo->fork_r]);

}

void    *routine(void *data)
{
	t_philo *philo;
	
	
	philo = (t_philo*)data;
	if (philo->id % 2 == 0)
		usleep(300);
	while (philo->is_dead == false)
	{
		think(philo);
		eat(philo);
		sleep_dodo(philo);
	}
}