#include "../includes/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info.mutex->forks[philo->left_fork]);
	print_status(philo, FORK, 0);
	if (philo->info.nb_philo == 1)
	{
		pthread_mutex_unlock(&philo->info.mutex->forks[philo->left_fork]);
		ft_usleep(philo->info.tt_die);
		return ;
	}
	pthread_mutex_lock(&philo->info.mutex->forks[philo->right_fork]);
	print_status(philo, FORK, 0);
	print_status(philo, EAT, 0);
	philo->x_ate++;
	philo->time_last_meal = time_ms();
	ft_usleep(philo->info.tt_eat);
	pthread_mutex_unlock(&philo->info.mutex->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->info.mutex->forks[philo->right_fork]);
}

void	*is_dead(void *data)
{
	t_philo	*philo;
	int		stop;

	philo = (t_philo *)data;
	stop = 0;
	while (!stop)
	{
		pthread_mutex_lock(&philo->info.mutex->meal_check);
		if (time_ms() - philo->time_last_meal >= philo->info.tt_die)
		{
			pthread_mutex_unlock(&philo->info.mutex->meal_check);
			print_status(philo, DEAD, 1);
			return (NULL);
		}
		stop = philo->info.stop + philo->stop;
		pthread_mutex_unlock(&philo->info.mutex->meal_check);
	}
	return (NULL);
}

void    *routine(void *data)
{
	int	stop;
	t_philo	*philo;

	stop = 0;
	philo = (t_philo *)data;
	philo->time_last_meal = philo->info.start_time;
	if (pthread_create(&philo->checker, NULL, &is_dead, philo))
		return (NULL);
	while (!stop)
	{
		eat(philo);
		if (philo->info.num_must_eat != -1 \
			&& philo->x_ate == philo->info.num_must_eat)
		{
			pthread_mutex_lock(&philo->info.mutex->is_dead);
			philo->stop = 1;
			pthread_mutex_unlock(&philo->info.mutex->is_dead);
			return ;
		}
		print_status(philo, SLEEP, 0);
		ft_usleep(philo->info.tt_sleep);
		print_status(philo, THINK, 0);
		if (!philo->id % 2)
			ft_usleep(100);
		pthread_mutex_lock(&philo->info.mutex->is_dead);
		stop = philo->info.stop + philo->stop;
		pthread_mutex_unlock(&philo->info.mutex->is_dead);
	}
	if (pthread_join(philo->checker, NULL))
		return (NULL);
	return (NULL);
}