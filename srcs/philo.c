/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/19 13:13:35 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void start_diner(t_data *data)
{
	int i;
	int n;
	
	n = data->info.nb_philo;
	pthread_t th[n];
	i = -1;
	while (++i < n) 
	{
		if (pthread_create(&th[i], NULL, routine, &data->philo[i]) != 0)
			printf("Error when thread %d create\n", i);
		usleep(10);
	}
	// i = -1;
	// while (1)
	// {
		
	// 	while (++i <  n)
	// 	{
	// 		check_if_dead(&data->philo[i]);
			
	// 	}
	// }
	i = -1;
	while (++i < n)
	{
		if (pthread_join(th[i], NULL) != 0)
			printf("Error threads join\n");
	}
}

void clear_table(t_data *data)
{
	for (int i = 0; i < data->info.nb_philo; i++) {
		pthread_mutex_destroy(&data->philo[i].fork_protect);
		pthread_mutex_destroy(&data->info.fork[i]);
	}
	pthread_mutex_destroy(&data->info.status);
	free(data->info.fork);
	free(data->philo);
}

// This function makes sure it has valid arguments and then
// looks at what those arguments are
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
	t_data data;
	
    if (check_args(ac, av))
       return (printf("%s", args_error));
	memset(&data.info, 0, sizeof(t_info));
    if (init_info(ac, av, &data))
		return (printf("%s", init_error));
	start_diner(&data);
	clear_table(&data);
}

