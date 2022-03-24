/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/24 10:45:07 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    display_info(void)
{
    printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
    printf("|---------|-------|-------------------------|\n");
}

void   print_status(t_philo  *philo, char *status)
{
    t_info *info;

    info = philo->infos;
    pthread_mutex_lock(&info->writing_status);
    if (!info->dieded)
        printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&info->writing_status);
    return ;
}

void print_philo_info(t_info *info)
{
    for (int i = 0; i < info->nb_philo; i++) {
        printf("info->philo[i].id = %d\n", info->philos[i].id);
        printf("info->philo[i].info.time_to_death = %d\n", info->philos[i].infos->tt_die);
        printf("info->philo[i].info.time_to_sleep = %d\n", info->philos[i].infos->tt_sleep);
        printf("info->philo[i].info.time_to_eat = %d\n", info->philos[i].infos->tt_eat);
        
    }
}