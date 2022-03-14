/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 16:51:33 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    display_info(void)
{
    printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
    printf("|---------|-------|-------------------------|\n");
}

void    print_status(t_philo  *philo, char *status)
{
    pthread_mutex_lock(&philo->info.status);
    printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&philo->info.status);
}