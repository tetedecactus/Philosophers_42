/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/07 20:37:23 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	sleep_dodo(t_philo *philo)
{
	print_status(philo, SLEEP, 0);
	ft_usleep(philo->infos->tt_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->infos->fork[philo->r_fork]);
	print_status(philo, FORK, 0);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(&philo->infos->fork[philo->r_fork]);
		ft_usleep(philo->infos->tt_die);
		return ;
	}
	pthread_mutex_lock(&philo->infos->fork[philo->l_fork]);
	print_status(philo, FORK, 0);
	pthread_mutex_lock(&philo->infos->meal_check);
	print_status(philo, EAT, 0);
    philo->x_ate++;
	philo->time_last_meal = time_ms();
	pthread_mutex_unlock(&philo->infos->meal_check);
	ft_usleep(philo->infos->tt_eat);
	pthread_mutex_unlock(&philo->infos->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->infos->fork[philo->r_fork]);
}

void 	*is_dead(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (philo->infos->dieded == false)
	{
		pthread_mutex_lock(&philo->infos->meal_check);
		if (time_ms() - philo->time_last_meal >= philo->infos->tt_die)
		{
			pthread_mutex_unlock(&philo->infos->meal_check);
			pthread_mutex_lock(&philo->infos->writing_status);
			print_status(philo, DEAD, 1);
			pthread_mutex_unlock(&philo->infos->writing_status);
		}
		else
			pthread_mutex_unlock(&philo->infos->meal_check);
		pthread_mutex_lock(&philo->infos->meal_check);
		philo->infos->dieded = true;
		pthread_mutex_unlock(&philo->infos->meal_check);
	}
	return NULL;
}

void    *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	philo->time_last_meal = philo->infos->start_time;
	if (pthread_create(&philo->checker, NULL, &is_dead, philo))
		perror("cacacacaacacaca");
	if (!philo->infos->nb_philo % 2)
			ft_usleep(100);
	while (philo->infos->dieded == false)
	{
		eat(philo);
		if (philo->infos->num_must_eat != -1 && philo->x_ate == philo->infos->num_must_eat)
		{
			pthread_mutex_lock(&philo->infos->is_dead);
			philo->infos->dieded = true;
			pthread_mutex_unlock(&philo->infos->is_dead);
			return NULL;
		}
		sleep_dodo(philo);
		print_status(philo, THINK, 0);
	}
	return NULL;
}

// void	*routine(void *arg)
// {
// 	t_p	*p;
// 	int	stop;

// 	p = (t_p *)arg;
// 	p->t_last_eat = p->info->t_start;
// 	if (pthread_create(&p->faucheuse, NULL, &is_dead, p))
// 		perror("pthread_create failed");
// 	stop = 0;
// 	while (!stop)
// 	{
// 		activity(p);
// 		pthread_mutex_lock(&p->info->m_stop);
// 		stop = p->info->stop + p->stop;
// 		pthread_mutex_unlock(&p->info->m_stop);
// 	}
// 	if (pthread_join(p->faucheuse, NULL))
// 		perror("pthread_join failed");
// 	return (NULL);
// }