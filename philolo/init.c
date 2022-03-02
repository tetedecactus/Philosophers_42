/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:52:18 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/02 11:47:24 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int  init_info(t_info *info, int ac, char **av)
{
    info->nb_philo = ft_atoi(av[1]);
    info->tt_die = ft_atoi(av[2]);
    info->tt_eat = ft_atoi(av[3]);
    info->tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->nb_meal = ft_atoi(av[5]);
    info->nb_meal = 0;
//    if (init_fork(info))
  //      return (printf("%s\n", FORK_INIT_ERR));
    if (pthread_mutex_init(&info->status, NULL))
            return (printf("%s\n", MUTEX_INIT_ERR));
    return (0);
}
