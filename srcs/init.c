/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:52:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/20 10:30:41 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_fork(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->infos->nb_philo)
	{
		if (philo->infos->nb_philo == 1)
			philo[i].r_fork = NULL;
		else
		{
			if (i == philo->infos->nb_philo - 1)
				philo[i].r_fork = &philo[0].l_fork;
			else
				philo[i].r_fork = &philo[i + 1].l_fork;
		}
	}
}

int	init_info(t_info *info, int ac, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	info->tt_die = ft_atoi(av[2]);
	info->tt_eat = ft_atoi(av[3]);
	info->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->num_must_eat = ft_atoi(av[5]);
	else
		info->num_must_eat = -1;
	info->stop = 0;
	info->start_time = 0;
	if (pthread_mutex_init(&info->writing_status, NULL) \
		|| pthread_mutex_init(&info->meal_check, NULL) \
		|| pthread_mutex_init(&info->is_dead, NULL))
		return (printf("%s\n", MUTEX_INIT_ERR));
	return (0);
}

int	init_philo(t_info *info, t_philo *philo, int ac, char **av)
{
	int	i;
	int	n;

	n = info->nb_philo;
	i = -1;
	while (++i < n)
	{
		philo[i].id = i + 1;
		philo[i].x_ate = 0;
		philo[i].time_last_meal = 0;
		philo[i].stop = 0;
		philo[i].infos = info;
		pthread_mutex_init(&philo->l_fork, NULL);
	}
	init_fork(philo);
	return (0);
}
