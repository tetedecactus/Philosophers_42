/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 11:26:10 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void start_diner(t_info *info)
{
	int i;
	int n;
	
	n = info->nb_philo;
	i = -1;
	printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
	printf("|---------|-------|-------------------------|\n");
	while (++i < n) 
	{
		info->philo[i].start_time = time_ms();
		if (pthread_create(&info->philo[i].philo_th, NULL, &routine, &info->philo[i]) != 0)
			printf("Error when thread %d create\n", i);
		if (pthread_create(&info->philo[i].monitor, NULL, &monitor, &info->philo[i]))
			printf("Failed to create thread.\n");
		usleep(10);
	}
	i = -1;
	while (++i < n)
	{
		if (pthread_join(info->philo[i].philo_th, NULL) != 0)
			printf("Error threads join\n");
		if (pthread_join(info->philo[i].monitor, NULL) != 0)
		printf("Error threads join\n");
	}
}

void clear_table(t_info *info)
{
	for (int i = 0; i < info->nb_philo; i++) {
		pthread_mutex_destroy(&info->philo[i].fork_protect);
		pthread_mutex_destroy(&info->fork[i]);
	}
	pthread_mutex_destroy(&info->status);
	free(info->fork);
	free(info->philo);
}

int check_args(int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
		if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
			return (printf("Number_of_philosopher doit etre entre 1 et 200 .\n"));
		if (ft_atoi(av[2]) < 60)
			return (printf("Time_to_die doit etre au minimum a 60.\n"));
		if (ft_atoi(av[3]) < 60)
			return (printf("Time_to_eat doit etre au minimum a 60.\n")); 
		if (ft_atoi(av[4]) < 60)
			return (printf("Time_to_sleep doit etre au minimum a 60.\n"));
        if (ac == 6 && ft_atoi(av[5]) < 1)
			return (printf("Number_of_times_each_philosopher_must_eat doit etre \
            au minimum 60.\n"));
        return (0);
	}
    return (1);
}

int main(int ac, char **av)
{
    t_info info;

    if (check_args(ac, av))
       return (printf("%s", args_error));
	memset(&info, 0, sizeof(t_info));
    if (init_info(ac, av, &info))
		return (printf("%s", init_error));
	start_diner(&info);
	clear_table(&info);
    return (0);
}

