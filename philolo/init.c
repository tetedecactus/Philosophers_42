/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:52:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/05 09:44:12 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int init_fork(t_info *info)
{
    int i;

    i = 0;
    info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
    if (!info->fork)
        return (printf("%s", FORK_INIT_ERR));
    while (i < info->nb_philo)
    {
        if (pthread_mutex_init(&info->fork[i++], NULL))
			return (printf("%s", MUTEX_INIT_ERR));
    }
    return (0);
}

int init_philo(t_info *info)
{
    t_philo     *philo;
	int i;

    philo = malloc(sizeof(t_philo) * info->nb_philo);
    if (!philo)
        return (1);
	i = -1;
	while (++i < info->nb_philo)
	{
        philo[i].timer = time_ms();
		philo[i].id = i + 1;
        philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % info->nb_philo;
		philo[i].info = info;
        philo[i].is_dead = false;
	}
    info->philo = philo;
	return (0);
}

int init(t_info *info, int ac, char **av)
{
    info->nb_philo = ft_atoi(av[1]);
    info->tt_die = ft_atoi(av[2]);
    info->tt_eat = ft_atoi(av[3]);
    info->tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->nb_meal = ft_atoi(av[5]);
    info->nb_meal = 0;
    if (init_fork(info))
       return (printf("%s\n", FORK_INIT_ERR));
    if (pthread_mutex_init(&info->status, NULL))
        return (printf("%s\n", MUTEX_INIT_ERR));
    if (init_philo(info))
        return (printf("%s\n", PHILO_INIT_ERR));
    return (0);
}
