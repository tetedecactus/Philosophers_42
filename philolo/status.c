/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/05 09:41:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    print_status(t_philo  *philo, char *status)
{
    printf("here\n");
    pthread_mutex_lock(&philo->info->status);
    printf("%ld %d %s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&philo->info->status);
}