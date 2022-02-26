/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:50:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/23 11:10:32 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int init_philo(t_info *info)
{
    t_philo *philo;
    
    int i;
    
    philo = malloc(sizeof(t_philo) * info->nb_philo);
    if (!philo)
        return (1);
    i = -1;
    while (++i < info->nb_philo)
    {
        philo[i].id = i + 1;
        philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % info->nb_philo;
        philo[i].start_time = 0;
        philo[i].meals = 0;
        philo[i].info = info;
		if (pthread_mutex_init(&philo[i].fork_protect, NULL))
			printf("L'initialisation du mutex de for a échoué.\n");
    }
    info->philo = philo;
    return (0);
}

int init_fork(t_info *info)
{
    int i;

    i = 0;
    info->fork = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
    if (!info->fork)
        return (printf("%s", mutex_error));
    while (i < info->nb_philo)
    {
        if (pthread_mutex_init(&info->fork[i++], NULL))
			return (printf("%s", mutex_error));
    }
    return (0);
}


int init_info(int ac, char **av, t_info *info)
{
    info->nb_philo = ft_atoi(av[1]);
    info->tt_die = ft_atoi(av[2]);
    info->tt_eat =  ft_atoi(av[3]);
    info->tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->nb_eat = ft_atoi(av[5]);
    else
        info->nb_eat = 0;
    // data->info.start_time = time_ms();
    info->is_dead = 0;
    if (pthread_mutex_init(&info->status, NULL))
		return (printf("%s", mutex_error));
    if (init_fork(info))
        return (printf("Fork init failed\n"));
    if (init_philo(info))
        return (1);
    return (0);
}

