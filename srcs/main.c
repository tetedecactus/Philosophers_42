/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:57:43 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/04 15:17:42 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void   *start_diner(void *data)
{
    t_info *info;
    int i;
    t_philo *philo;
	
	i = -1;
    info = (t_info*)data;
    philo = info->philos;
    info->first_timestamp = time_ms();
    display_info();
    // print_philo_info(info);
	while (++i < info->nb_philo)
	{
		if (pthread_create(&philo[i].philo_th, NULL, routine,  &philo[i]))
         {
            printf("%s\n", THREAD_ERR);
			return NULL; 
         }
        usleep(16000);
	}
    return (0);
}

int    waiter_punch_in(t_info *info)
{
    pthread_create(&info->waiter, NULL, start_diner, &info);
    return (0);
}

int clear_table(t_info *info)
{
    int i;
    
    i = -1;
    while (++i < info->nb_philo)
        pthread_join(info->philos[i].philo_th, 0);
    i = -1;
    while (++i < info->nb_philo)
        pthread_mutex_destroy(&info->fork[i]);
    pthread_mutex_destroy(&info->writing_status);
    pthread_mutex_destroy(&info->meal_check);
    free(info->fork);
    free(info->philos);
    return (0);
}

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
    t_info  info;
    
    if (ac < 5 || ac > 6)
        return (printf("%s\n", ARG_ERR));
    if (check_args(ac, av))
        return (printf("%s\n", ARG_ERR));
    if (init_philo(&info, ac, av))
        return (printf("%s\n", INIT_DATA_ERR));
    if (waiter_punch_in(&info))
        return (printf("%s\n", DINER_ERR));
    if (clear_table(&info))
        return (printf("%s\n", CLEAR_ERR));
    return (0);
}
