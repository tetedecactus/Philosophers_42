/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/21 07:44:42 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_status(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->args.status);
    if (philo->args.is_dead)
    {
        pthread_mutex_unlock(&philo->args.status);
        return ;
        
    }
    printf("%ld %d %s\n", current_time(philo), philo->id, message);
    pthread_mutex_unlock(&philo->args.status);
}

void check_if_dead(t_philo *philo)
{
    long time = time_ms();
    if (time - philo->start_time > philo->args.tt_die)
    {
        print_status(philo, dead_message);
        philo->args.is_dead++;
        usleep(10);
        exit (1);
        // int i = -1;
    }
}