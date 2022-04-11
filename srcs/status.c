/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/11 13:39:32 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_philo_info(t_philo *philos, t_info *info)
{
    for (int i = 0; i < info->nb_philo; i++) 
    {
        printf("info->philo[i].id = %d\n", philos[i].id);
        printf("info->philo[i].info.time_to_death = %d\n", philos[i].infos->tt_die);
        printf("info->philo[i].info.time_to_sleep = %d\n", philos[i].infos->tt_sleep);
        printf("info->philo[i].info.time_to_eat = %d\n", philos[i].infos->tt_eat);
    }
}

void    display_info(void)
{
    printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
    printf("|---------|-------|-------------------------|\n");
}

// void   print_status(t_philo  *philo, char *status, int dead)
// {
//     t_info *info;

//     info = philo->infos;
//     pthread_mutex_lock(&info->writing_status);
//     pthread_mutex_lock(&info->is_dead);
//     if (philo->infos->stop == 1)
//     {
//         pthread_mutex_unlock(&info->is_dead);
// 		return ;
//     }
//     if (dead == 1)
//         philo->infos->stop = 1;
//     pthread_mutex_unlock(&info->is_dead);
//     printf("| %lld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
//     pthread_mutex_unlock(&info->writing_status);
//     return ;
// }

void    print_status(t_philo *philo, char *str)
{
    long long    elapsed_time;

    pthread_mutex_lock(&philo->infos->is_dead);
    if (philo->infos->stop == 1)
    {
        pthread_mutex_unlock(&philo->infos->is_dead);
        return ;
    }
    if (!ft_strcmp(str, "died"))
        philo->infos->stop = 1;
    pthread_mutex_unlock(&philo->infos->is_dead);
    elapsed_time = time_ms() - philo->infos->start_time;
    pthread_mutex_lock(&philo->infos->writing_status);
    printf("%lld : Philosopher #%d %s.\n", elapsed_time, philo->id, str);
    pthread_mutex_unlock(&philo->infos->writing_status);
}

// void	sleep_dodo(t_philo *philo)
// {
// 	print_status(philo, SLEEP, 0);
// 	ft_usleep(philo->infos->tt_sleep);
// }