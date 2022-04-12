#include "../includes/philo.h"

int	start_diner(t_philo *philo)
{
	int	i;

	i = -1;
	philo->info.start_time = time_ms();
	display_info();
	while (++i < philo->info.nb_philo)
	{
		if (pthread_create(&philo[i].philo_th, NULL, routine, &philo[i]))
			return (printf("%s\n", THREAD_ERR));
	}
	i = -1;
	while (++i < philo->info.nb_philo)
		if (pthread_join(philo[i].philo_th, 0))
			return (printf("%s\n", THREAD_ERR));
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (printf("%s\n", AV1_ERR));
	if (ft_atoi(av[2]) < 60)
		return (printf("%s\n", AV2_ERR));
	if (ft_atoi(av[3]) < 60)
		return (printf("%s\n", AV3_ERR));
	if (ft_atoi(av[4]) < 60)
		return (printf("%s\n", AV4_ERR));
	if (ac == 6 && ft_atoi(av[5]) < 1)
		return (printf("%s\n", AV5_ERR));
	return (0);
}

int	main(int ac, char **av)
{
	t_philo *philo;

	philo = NULL;
	if (ac < 5 || ac > 6 || check_args(ac, av))
		return (printf("%s\n", ARG_ERR));
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo || init_philo(philo, ac, av))
		return (printf("%s\n", INIT_DATA_ERR));
	if (start_diner(philo))
		return (printf("%s\n", DINER_ERR));
	// for (int i = 0; i < 5; i++)
	// {
	// 	printf("philo id = %d", philo[i].id);

	// }
}