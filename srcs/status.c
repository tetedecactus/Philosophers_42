/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/21 20:44:34 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

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
    if (!info->dieded)
        printf("| %ld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
    pthread_mutex_unlock(&info->writing_status);
    return ;
}
