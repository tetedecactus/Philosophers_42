/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:57:43 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/21 21:42:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int    start_diner(t_info *info)
{
    int i;
    t_philo *philo;
	
	i = -1;
    philo = info->philo;
    info->first_timestamp = time_ms();
    display_info();
	while (++i < info->nb_philo)
	{
		if (pthread_create(&philo[i].philo_th, NULL, routine,  &philo[i]))
			return (printf("%s\n", THREAD_ERR));
        philo[i].t_last_meal = time_ms();
	}
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
    t_info info;
    
    if (ac < 5 || ac > 6)
        return (printf("%s\n", ARG_ERR));
    if (check_args(ac, av))
        return (printf("%s\n", ARG_ERR));
    // info = malloc(sizeof(t_info) * ft_atoi(av[1]));
    if (init_data(&info, ac, av))
        return (printf("%s\n", INIT_DATA_ERR));
    if (start_diner(&info))
        return (printf("%s\n", DINER_ERR));
    // if (clear_table(&info))
        // return (printf("%s\n", CLEAR_ERR));
    return (0);
}
