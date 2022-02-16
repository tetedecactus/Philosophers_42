/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:50:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/16 14:39:44 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

t_philo *init_philo(t_data *data)
{
    t_philo *philo;
    
    int i;
    
    philo = malloc(sizeof(t_philo) * data->info.nb_philo);
    if (!philo)
        return (NULL);
    i = -1;
    while (++i < data->info.nb_philo)
    {
        philo[i].id = i + 1;
        philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % data->info.nb_philo;
        philo[i].start_time = time_ms();
		if (pthread_mutex_init(&philo[i].fork_protect, NULL))
			printf("L'initialisation du mutex de for a échoué.\n");
        philo[i].args = data->info;
    }
    data->philo = philo;
    return (philo);
    
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
// besoin de changer pour int function
t_info init_info(int ac, char **av, t_data *data)
{
    t_info      info;

    info.nb_philo = ft_atoi(av[1]);
    info.tt_die = ft_atoi(av[2]);
    info.tt_eat =  ft_atoi(av[3]);
    info.tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info.nb_eat = ft_atoi(av[5]);
    else
        info.nb_eat = 0;
    info.timer = 0;
    if (pthread_mutex_init(&info.status, NULL))
		printf("L'initialisation du mutex a échoué.\n");
    if (init_fork(&info))
        printf("fork error\n");
    data->info = info;
    return (info);
}