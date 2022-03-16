/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:52:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/15 08:45:19 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int init_fork(t_info *info)
{
    int i;

    i = -1;
    info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
    if (!info->fork)
        return (printf("%s", FORK_INIT_ERR));
    while (++i < info->nb_philo)
    {
        if (pthread_mutex_init(&info->fork[i], NULL))
			return (printf("%s", MUTEX_INIT_ERR));
    }
    return (0);
}

int init_philo(t_data *data)
{
    t_philo     *philo;
	int i;
    int n;

    n = data->info.nb_philo;
    philo = malloc(sizeof(t_philo) * n);
    if (!philo)
        return (1);
	i = -1;
	while (++i < n)
	{
        philo[i].timer = time_ms();
		philo[i].id = i + 1;
        philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % n;
		philo[i].info = data->info;
        philo[i].is_dead = false;
	}
    data->philo = philo;
	return (0);
}

int init_info(t_data *data, int ac, char **av)
{
    data->info.nb_philo = ft_atoi(av[1]);
    data->info.tt_die = ft_atoi(av[2]);
    data->info.tt_eat = ft_atoi(av[3]);
    data->info.tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->info.num_must_eat = ft_atoi(av[5]);
    data->info.num_must_eat = 0;
    if (init_fork(&data->info))
       return (printf("%s\n", FORK_INIT_ERR));
    if (pthread_mutex_init(&data->info.status, NULL))
        return (printf("%s\n", MUTEX_INIT_ERR));
    return (0);
}

int init_data(t_data *data, int ac, char **av)
{
    if (init_info(data, ac, av))
        return (printf("%s\n", INIT_INFO_ERR));
    if (init_philo(data))
        return (printf("%s\n", PHILO_INIT_ERR));
    return (0);
}