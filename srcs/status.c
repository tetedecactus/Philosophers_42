/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/17 15:58:53 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_status(t_philo *philo, char *message)
{
    // pthread_mutex_lock(&philo->status);
    // printf("%ld philo[%d] %s\n", current_time(philo), philo->id, message);
    // if (!philo->is_dead)
    //     pthread_mutex_unlock(&philo->status);
    
    if (!philo->is_dead)
    {
        pthread_mutex_lock(&philo->args.status);
        printf("%ld philo[%d] %s\n", current_time(philo), philo->id, message);
        pthread_mutex_unlock(&philo->args.status);
    }
}