/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/01 17:03:27 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_philo_info(t_info *info)
{
    for (int i = 0; i < info->nb_philo; i++) {
        printf("info->philo[i].id = %d\n", info->philos[i].id);
        printf("info->philo[i].info.time_to_death = %d\n", info->philos[i].infos->tt_die);
        printf("info->philo[i].info.time_to_sleep = %d\n", info->philos[i].infos->tt_sleep);
        printf("info->philo[i].info.time_to_eat = %d\n", info->philos[i].infos->tt_eat);
        
    }
}

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
    if (info->dieded == false)
        printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&info->writing_status);
    return ;
}

int check_meal(t_philo *philo)
{
    t_info *info;
    int n;
    
	n = philo->infos->num_must_eat;
    info = philo->infos;
    pthread_mutex_lock(&info->meal_check);
	if (n != 0 && philo->x_ate == n) 
	{
		info->all_ate++;
		printf("all ate= %d\n", info->all_ate);
    }
    else if (info->all_ate == n) {
        info->dieded = true;    
        print_status(philo, DEAD);
        pthread_mutex_unlock(&info->meal_check);
        return (1);
    }
    else {
        printf("id: %d x ate : %d\n", philo->id, philo->x_ate);
        pthread_mutex_unlock(&info->meal_check);
        return (0);
        
    }
}