/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:57:43 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 14:46:30 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    start_diner(t_data *data)
{
    int i;
	
	i = -1;
    display_info();
    for (int j = 0; j < data->info.nb_philo; j++)
    {
        printf("philo id = %d\n", data->philo[j].id);
    }
	while (++i < data->info.nb_philo)
	{
		if (pthread_create(&data->philo[i].philo_th, NULL, routine, (void *) data) != 0)
			return ;
        usleep(5);
	}
}

// void clear_table(t_info *info)
// {
//     int i;

//     i = -1;
// 	while (i < info->nb_philo) 
//     {
// 		// pthread_mutex_destroy(&info->philo[i].info->fork);
// 		pthread_mutex_destroy(&info->fork[i]);
// 	}
// 	pthread_mutex_destroy(&info->status);
// 	free(info->fork);
// 	free(info->philo);
// }


int check_args(int ac, char **av)
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

int main(int ac, char **av)
{ 
    t_data data;
    
    if (ac < 5 || ac > 6)
        return (printf("%s\n", ARG_ERR));
    if (check_args(ac, av))
            return (printf("%s\n", ARG_ERR));
    memset(&data, 0, sizeof(t_data));
    if (init_data(&data, ac, av))
        return (printf("%s\n", INIT_DATA_ERR));
    start_diner(&data);
    // // clean_table(&info);
    return (0);
}
