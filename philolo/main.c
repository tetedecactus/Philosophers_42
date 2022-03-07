/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:57:43 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/05 09:42:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    start_diner(t_info *info)
{
	pthread_t 	th[info->nb_philo];
    int i;
	
	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_create(&th[i], NULL, routine, &info->philo[i++]))
			return ;
	}
}

int check_args(int ac, char **av)
{
    if (ac == 5 || ac == 6)
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
    return (1);
}

int main(int ac, char **av)
{
    t_info info;

    if (check_args(ac, av))
            return (printf("%s\n", ARG_ERR));
    memset(&info, 0, sizeof(t_info));
    if (init(&info, ac, av))
        return (printf("%s\n", INIT_INFO_ERR));
    start_diner(&info);
    // clean_table(&info);
    return (0);
}
