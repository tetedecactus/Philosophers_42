/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:22:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/11 13:39:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	right_handed(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "take fork");
	// print_status(philo, FORK, 0);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		ft_usleep(philo->infos->tt_die);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "take fork");
	// print_status(philo, FORK, 0);
	// print_status(philo, EAT, 0);
	print_status(philo, "is eating");
	philo->x_ate++;
	pthread_mutex_lock(&philo->infos->meal_check);
	philo->time_last_meal = time_ms();
	pthread_mutex_unlock(&philo->infos->meal_check);
	ft_usleep(philo->infos->tt_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	left_handed(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_status(philo, "take fork");
	// print_status(philo, FORK, 0);
	if (philo->infos->nb_philo == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		ft_usleep(philo->infos->tt_die);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_status(philo, "take fork");
	print_status(philo, "is eating");
	// print_status(philo, FORK, 0);
	// print_status(philo, EAT, 0);
	philo->x_ate++;
	pthread_mutex_lock(&philo->infos->meal_check);
	philo->time_last_meal = time_ms();
	pthread_mutex_unlock(&philo->infos->meal_check);
	ft_usleep(philo->infos->tt_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		right_handed(philo);
	else
		left_handed(philo);
}

// void    death(void arg)
// {
//     t_philo ph;
//     int        stop;

//     ph = (t_philo)arg;
//     stop = 0;
//     while (!stop)
//     {
//         pthread_mutex_lock(&ph->d->last_ate);
//         if (get_time() - ph->last_t_ate > ph->d->tt_die)
//         {
//             pthread_mutex_unlock(&ph->d->last_ate);
//             log_activity(ph, "died");
//         }
//         else
//             pthread_mutex_unlock(&ph->d->last_ate);
//         pthread_mutex_lock(&ph->d->stop_lock);
//         stop = ph->stop + ph->d->stop;
//         pthread_mutex_unlock(&ph->d->stop_lock);
//     }
//     return (NULL);
// }

void 	*is_dead(void *data)
{
	t_philo *philo;
	int stop;

	philo = (t_philo *)data;
	stop = 0;
	while (!stop)
	{
		// printf("philo id %d inside IS DEAD\n"÷, philo->id);
		pthread_mutex_lock(&philo->infos->meal_check);
		if (time_ms() - philo->time_last_meal >= philo->infos->tt_die)
		{
			pthread_mutex_unlock(&philo->infos->meal_check);
			pthread_mutex_lock(&philo->infos->writing_status);
			// print_status(philo, DEAD, 1);
			print_status(philo, "died");
			pthread_mutex_unlock(&philo->infos->writing_status);
		}
		else
			pthread_mutex_unlock(&philo->infos->meal_check);
		pthread_mutex_lock(&philo->infos->meal_check);
		stop = philo->infos->stop + philo->stop;
		pthread_mutex_unlock(&philo->infos->meal_check);
	}
	return NULL;
}



void    *routine(void *data)
{
	t_philo *philo;
	int stop;

	philo = (t_philo *)data;
	philo->time_last_meal = philo->infos->start_time;
	if (pthread_create(&philo->checker, NULL, &is_dead, philo))
		perror("cacacacaacacaca");
	stop = 0;
	while (!stop)
	{
		if (philo->id % 2 == 0)
			right_handed(philo);
		else
			left_handed(philo);
		if (philo->infos->num_must_eat != -1 && philo->x_ate == philo->infos->num_must_eat)
		{
			pthread_mutex_lock(&philo->infos->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->infos->is_dead);
			return NULL;
		}
		print_status(philo, "is sleeping");
		ft_usleep(philo->infos->tt_sleep);
		print_status(philo, "is thinking");
		if (!philo->id % 2)
			ft_usleep(100);
			
		pthread_mutex_lock(&philo->infos->is_dead);
		stop = philo->infos->stop + philo->stop;
		pthread_mutex_unlock(&philo->infos->is_dead);
	}
	if (pthread_join(philo->checker, NULL))
		perror("pthread_join failed");
	return NULL;
}
