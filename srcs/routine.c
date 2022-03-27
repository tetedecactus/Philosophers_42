/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/27 19:41:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	sleep_dodo(t_philo *philo)
{
	t_info *info;

	info = philo->infos;
	print_status(philo, SLEEP);
	ft_usleep(info->tt_sleep);
}

void	eat(t_philo *philo)
{
	t_info *info;

	info = philo->infos;
	pthread_mutex_lock(&info->fork[philo->l_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&info->fork[philo->r_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&info->meal_check);
	print_status(philo, EAT);
	philo->t_last_meal = time_ms();
	pthread_mutex_unlock(&info->meal_check);
	ft_usleep(info->tt_eat);
	philo->x_ate++;
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
}

void	*check_which_die(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	ft_usleep(philo->infos->tt_die);
	
}

void    *routine(void *data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = (t_philo *)data;
	info = philo->infos;
	if (!philo->id % 2)
		usleep(300);
	while (!info->dieded)
	{
		check_death();
		pthread_create(&philo->checker, NULL, check_which_die, data);
		eat(philo);
		if (info->all_ate)
			break ;
		sleep_dodo(philo);
		print_status(philo, THINK);
		// pthread_detach
	}
}
