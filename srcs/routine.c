/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/05 14:04:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	sleep_dodo(t_philo *philo)
{
	t_info *info;

	info = philo->infos;
	print_status(philo, SLEEP);
	ft_usleep(info->tt_sleep);
}

void	eat(t_philo *philo)
{
	t_info *info;

	info = philo->infos;
	pthread_mutex_lock(&info->fork[philo->r_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&info->fork[philo->l_fork]);
	print_status(philo, FORK);
	philo->time_next_meal = time_ms() + (long)philo->infos->tt_die;
	pthread_mutex_lock(&info->meal_check);
	print_status(philo, EAT);
	philo->present_time = time_ms();//
    philo->x_ate++;
	pthread_mutex_unlock(&info->meal_check);
	ft_usleep(info->tt_eat);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
}

int check_which_die(t_info *info)
{
	int i;

	i = 0;
	while (1)
	{
		long time;
		// comparer present et last meal entre present et last
		current_time(info->philos[i++]);
		if (i == info->nb_philo)
			i = 0;
	}
}

void    *routine(void *data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = (t_philo *)data;
	info = philo->infos;
	while (info->dieded == false)
	{
		// pthread_create(&philo->checker, NULL, check_which_die, data);
		eat(philo);
		// if (info->all_ate == info->nb_philo) {
		// 	printf("philo: %d break ;\n", philo->id);
		// 	break ;
		// }
		sleep_dodo(philo);
		print_status(philo, THINK);
		// pthread_detach(philo->checker);
		if (check_meal(philo) != 0) {
			printf("Sa sort surment ici\n");
			break ;
		}
	}
	return NULL;
}