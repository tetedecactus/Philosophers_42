/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:52:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/30 20:49:18 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int init_fork(t_info *info)
{
    int i;

    i = -1;
    info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
    if (!info->fork)
        return (printf("%s\n", FORK_INIT_ERR));
    while (++i < info->nb_philo)
    {
        if (pthread_mutex_init(&info->fork[i], NULL))
			return (printf("%s\n", MUTEX_INIT_ERR));
    }
    return (0);
}

int init_info(t_info *info, int ac, char **av)
{
    info->nb_philo = ft_atoi(av[1]);
    info->tt_die = ft_atoi(av[2]);
    info->tt_eat = ft_atoi(av[3]);
    info->tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->num_must_eat = ft_atoi(av[5]);
    info->num_must_eat = 0;
    info->first_timestamp = time_ms();
    info->dieded = false;
    info->all_ate = false;
    if (init_fork(info))
       return (printf("%s\n", FORK_INIT_ERR));
    if (pthread_mutex_init(&info->writing_status, NULL) \
        || pthread_mutex_init(&info->meal_check, NULL) \
        || pthread_mutex_init(&info->is_dead, NULL))
        return (printf("%s\n", MUTEX_INIT_ERR));
   
    return (0);
}

int init_philo(t_info *info, int ac, char **av)
{
    t_philo     *philo;
	int i;
    int n;
    
    init_info(info, ac, av);

    n = info->nb_philo;
    philo = malloc(sizeof(t_philo) * n);
    if (!philo)
        return (1);
	i = -1;
	while (++i < n)
	{
		philo[i].id = i + 1;
        philo[i].x_ate = 0;
        philo[i].l_fork = i;
		philo[i].r_fork = (i + 1) % n;
        philo[i].t_last_meal = 0;
		philo[i].infos = info;
	}
    info->philos = philo;
    return (0);
}