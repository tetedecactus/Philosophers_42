#include "../includes/philo.h"

t_mutex *init_mutex(int ac, char **av)
{
    int i;
    t_mutex *mutex;
    pthread_mutex_t *forks;

    mutex = malloc(sizeof(t_mutex) * ft_atoi(av[1]));
    forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
    if (!forks)
	    return (NULL);
    mutex->forks = forks;
    while (++i < ft_atoi(av[1]))
		if (pthread_mutex_init(&mutex->forks[i], NULL))
			return (NULL);
    if (pthread_mutex_init(&mutex->print_status, NULL) \
		|| pthread_mutex_init(&mutex->meal_check, NULL) \
		|| pthread_mutex_init(&mutex->is_dead, NULL))
		return (NULL);
    return (mutex);
}   

t_info  init_info(int ac, char **av)
{
    t_info info;

    t_mutex *mutex;

    mutex = init_mutex(ac, av);
    info.nb_philo = ft_atoi(av[1]);
	info.tt_die = ft_atoi(av[2]);
	info.tt_eat = ft_atoi(av[3]);
	info.tt_sleep = ft_atoi(av[4]);
    if (ac == 6)
		info.num_must_eat = ft_atoi(av[5]);
	else
		info.num_must_eat = -1;
    info.stop = 0;
	info.start_time = 0;
    info.mutex = mutex;
    return (info);
}

int init_philo(t_philo *philo, int ac, char **av)
{
    int i;
    int n;
	
    n = ft_atoi(av[1]);
    i = -1;
    while (++i < n)
    {
        philo[i].id = i + 1;
		philo[i].left_fork = 0;
		philo[i].right_fork = ((i + 1) % n);
		philo[i].x_ate = 0;
        philo[i].time_last_meal = 0;
		philo[i].stop = 0;
		philo[i].info = init_info(ac, av);;
    }
    if (!philo)
		return (1);
    return (0);
}