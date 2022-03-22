/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/21 13:31:21 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    display_info(void)
{
    printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
    printf("|---------|-------|-------------------------|\n");
}

int    print_status(t_philo  *philo, char *status)
{
    pthread_mutex_lock(&philo->info.status);
    if (philo->is_dead)
    {
        pthread_mutex_unlock(&philo->info.status);
        return (1);
    }
    printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&philo->info.status);
    return (0);
}

// int	philo_print(t_main *main, int id, char *color, char *status)
// {
// 	long long	now;

// 	now = delta_time(main->t0);
// 	if (main->philo_dead == TRUE)
// 		return (FALSE);
// 	pthread_mutex_lock(&main->write);
// 	if (main->philo_dead == TRUE)
// 	{
// 		pthread_mutex_unlock(&main->write);
// 		return (FALSE);
// 	}
// 	else
// 		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, status, RESET);
// 	pthread_mutex_unlock(&main->write);
// 	return (TRUE);
// }