/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:45:26 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/18 19:53:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void print_status(t_philo *philo, char *message)
{
    if (!check_if_dead(philo) && philo->is_dead == 0)
    {
        pthread_mutex_lock(&philo->args.status);
        printf("%ld %d %s\n", current_time(philo), philo->id, message);
        pthread_mutex_unlock(&philo->args.status);
    }
}