/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 11:28:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_status(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->info->status);
    if (philo->info->is_dead)
    {
        pthread_mutex_unlock(&philo->info->status);
        return ;
    }
    printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, message);
    pthread_mutex_unlock(&philo->info->status);
}
