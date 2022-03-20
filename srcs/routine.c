/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/20 19:40:03 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int	think(t_philo *philo)
{
	print_status(philo, SLEEP);
}

int	sleep_dodo(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->info.tt_sleep);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info.fork[philo->fork_l]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->info.fork[philo->fork_r]);
	print_status(philo, FORK);
	print_status(philo, EAT);
	ft_usleep(philo->info.tt_eat);
	philo->timer = time_ms();
	ft_usleep(philo->info.tt_eat);
	philo->info.num_have_ate++;
	// usleep(philo->info.tt_eat * 1000);
	pthread_mutex_unlock(&philo->info.fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->info.fork[philo->fork_r]);

}

void	*check_death(void *data)
{
	t_philo *philo;
	
	philo =(t_philo*)data;
	// ft_usleep(philo->info.tt_die);
	
}

void    *routine(void *d)
{
	t_data *data;
	// t_philo *philo;
	
	data = (t_data*)d;
	// philo = data->philo;
	if (data->philo->id % 2 == 0)
		usleep(300);
	while (data->philo->is_dead == false)
	{
		if (eat(data->philo))
			break ;
		if (sleep_dodo(data->philo))
			break ;
		if (think(data->philo))
			break ;
	}
}