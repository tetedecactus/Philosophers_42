/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/31 07:39:26 by olabrecq         ###   ########.fr       */
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
	pthread_mutex_lock(&info->fork[philo->l_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&info->fork[philo->r_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&info->meal_check);
	print_status(philo, EAT);
	philo->t_last_meal = time_ms();
    philo->x_ate++;
	pthread_mutex_unlock(&info->meal_check);
	ft_usleep(info->tt_eat);
	pthread_mutex_unlock(&info->fork[philo->l_fork]);
	pthread_mutex_unlock(&info->fork[philo->r_fork]);
}

void	*check_which_die(void *data)
{
	t_philo *philo;
    t_info *info;
	int n;
    
	philo = (t_philo *)data;
    info = philo->infos;
	n = philo->infos->num_must_eat;
	ft_usleep(info->tt_die);
    pthread_mutex_lock(&info->meal_check);
	if (n != 0 && philo->x_ate == n) 
	{
		info->all_ate++;
		printf("all ate= %d\n", info->all_ate);
    }
	printf("id: %d x ate : %d\n", philo->id, philo->x_ate);
    pthread_mutex_unlock(&info->meal_check);
}

void    *routine(void *data)
{
	t_philo *philo;
	t_info	*info;
	
	philo = (t_philo *)data;
	info = philo->infos;
	if (!philo->id % 2)
		usleep(300);
	while (info->dieded == false)
	{
		pthread_create(&philo->checker, NULL, check_which_die, data);
		eat(philo);
		if (info->all_ate == 5) {
			printf("philo: %d break ;\n", philo->id);
			break ;
		}
		sleep_dodo(philo);
		print_status(philo, THINK);
		pthread_detach(philo->checker);
		if (check_meal(philo) != 0) {
			printf("Sa sort surment ici\n");
			// break ;
		}
	}
}
