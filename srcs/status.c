/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:46:30 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/18 15:17:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	display_info(void)
{
	printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
	printf("|---------|-------|-------------------------|\n");
}

void	print_status(t_philo *philo, char *status, int dead)
{
	t_info	*info;

	info = philo->infos;
	pthread_mutex_lock(&info->is_dead);
	if (philo->infos->stop == 1)
	{
		pthread_mutex_unlock(&info->is_dead);
		return ;
	}
	if (dead == 1)
		philo->infos->stop = 1;
	pthread_mutex_unlock(&info->is_dead);
	pthread_mutex_lock(&info->writing_status);
	printf("| %lld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
	pthread_mutex_unlock(&info->writing_status);
}
