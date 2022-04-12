/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:57:43 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/12 11:35:13 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_diner(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	info->start_time = time_ms();
	display_info();
	while (++i < info->nb_philo)
	{
		if (pthread_create(&philo[i].philo_th, NULL, poutine, &philo[i]))
			return (printf("%s\n", THREAD_ERR));
	}
	i = -1;
	while (++i < info->nb_philo)
		pthread_join(philo[i].philo_th, 0);
	return (0);
}

void	clear_table(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&info->writing_status);
	pthread_mutex_destroy(&info->writing_status);
	pthread_mutex_destroy(&info->is_dead);
	free(philo);
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
	t_info	info;
	t_philo	*philo;

	if (ac < 5 || ac > 6 || check_args(ac, av))
		return (printf("%s\n", ARG_ERR));
	if (init_info(&info, ac, av))
		return (printf("%s\n", INIT_DATA_ERR));
	philo = malloc(sizeof(t_philo) * info.nb_philo);
	if (!philo || init_philo(&info, philo, ac, av))
		return (printf("%s\n", INIT_DATA_ERR));
	if (start_diner(&info, philo))
		return (printf("%s\n", DINER_ERR));
	clear_table(&info, philo);
	return (0);
}
