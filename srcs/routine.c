/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:03:25 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/17 16:20:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int check_if_dead(t_philo *philo)
{
    long time = time_ms();
    if (time - philo->args.start_time > philo->args.tt_die)
    {
        print_status(philo, dead_message);
        philo->is_dead++;
        return (1);
    }
    return (0);
}

void *thinking(t_philo *philo)
{
    if (!philo->is_dead)
        print_status(philo, think_message);
    // else
    //     print_status(philo, dead_message);
    return (NULL);
}

void *sleeping(t_philo *philo)
{
    if (!philo->is_dead)
    {
        print_status(philo, sleep_message);
        ft_usleep(philo->args.tt_sleep);
    }
    // else
    //     print_status(philo, dead_message);
    return (NULL);
}

void *eating(t_philo *philo)
{
    // faire un sleep de time_to_eat
    if (!philo->is_dead)
    {
        pthread_mutex_lock(&philo->args.fork[philo->fork_r]);
        print_status(philo, fork_message);
        pthread_mutex_lock(&philo->args.fork[philo->fork_l]);
        print_status(philo, fork_message);
        print_status(philo, eat_mesage);
        philo->args.start_time = time_ms();
        while (time_ms() - philo->args.start_time <= philo->args.tt_eat)  
            ft_usleep(philo->args.tt_eat);
        pthread_mutex_unlock(&philo->args.fork[philo->fork_r]);
        pthread_mutex_unlock(&philo->args.fork[philo->fork_l]);
    }
    // else
    //     print_status(philo, dead_message);
    return (NULL);
}

/*This function is the send theard to 3 differente routine_action eating(), sleeping(), thinking()*/
void *routine(void *data)
{
    t_philo *philo;
    
    philo = (t_philo*)data;
    if (philo->id % 2 == 0)
        usleep(16000);
    while(!philo->is_dead)
    {
        if (philo->is_dead)
            break;
        eating(philo);
        if (philo->is_dead)
            break;
        sleeping(philo);
        if (philo->is_dead)
            break;
        thinking(philo);
    }
    return (NULL);
}

