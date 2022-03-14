/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 14:39:16 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	think(t_philo *philo)
{
	print_status(philo, SLEEP);
}

void	sleep_dodo(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->info.tt_sleep);
}

void 	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info.fork[philo->fork_l]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->info.fork[philo->fork_r]);
	print_status(philo, FORK);
	philo->timer = time_ms();
	print_status(philo, EAT);
	ft_usleep(philo->info.tt_eat);
	pthread_mutex_unlock(&philo->info.fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info.fork[philo->fork_r]);

}

void	*check_death(void *data)
{
	t_philo *philo;
	
	philo =(t_philo*)data;
	ft_usleep(philo->info.tt_die);
	
}

void    *routine(void *d)
{
	t_data *data;
	t_philo *philo;
	
	data = (t_data*)d;
	philo = data->philo;
	if (data->philo->id % 2 == 0)
		usleep(300);
	while (data->philo->is_dead == false)
	{
		// if (pthread_create(&philo->is_dead_th, NULL, check_death, &philo[i]))
		// 	exit(1);
		eat(philo);
		sleep_dodo(philo);
		think(philo);
	}
}