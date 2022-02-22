// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   routine.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/12 11:03:25 by olabrecq          #+#    #+#             */
// /*   Updated: 2022/02/21 11:52:42 by olabrecq         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/philo.h"

// int	check_meals(t_philo *philo)
// {
// 	int	i;
// 	i = -1;
// 	while (++i < philo->args->nb_philo)
// 	{
// 		if (philo[i].meals < philo->args->nb_eat)
// 			return (0);
// 	}
// 	philo->args->is_dead = 1;
// 	return (1);
// }

// void thinking(t_philo *philo)
// {
//     print_status(philo, think_message);
// }

// void sleeping(t_philo *philo)
// {
//     long start_sleep;

//     start_sleep = time_ms();
//     print_status(philo, sleep_message);
//     while (time_ms() - start_sleep <= philo->args->tt_sleep && \
// 	!philo->args->is_dead)
//         ft_usleep(philo->args->tt_sleep);
// }

// void eating(t_philo *philo)
// {
//     if (philo->args->nb_philo == 1)
// 	{
// 		pthread_mutex_lock(&philo->args->fork[philo->fork_r]);
// 		print_status(philo, fork_message);
// 		while (!philo->args->is_dead)
// 			usleep(1000);
// 		pthread_mutex_unlock(&philo->args->fork[philo->fork_r]);
// 	}
//     else
//     {
//         pthread_mutex_lock(&philo->args->fork[philo->fork_r]);
//         print_status(philo, fork_message);
//         pthread_mutex_lock(&philo->args->fork[philo->fork_l]);
//         print_status(philo, fork_message);
//         pthread_mutex_lock(&philo->fork_protect);
//         print_status(philo, eat_mesage);
//         philo->start_time = time_ms();
//         pthread_mutex_unlock(&philo->fork_protect);
//         ft_usleep(philo->args->tt_eat);
//         while (time_ms() - philo->start_time <= philo->args->tt_eat && \
// 		!philo->args->is_dead)
// 			usleep(1000);
//         philo->meals++;
//         pthread_mutex_unlock(&philo->args->fork[philo->fork_r]);
//         pthread_mutex_unlock(&philo->args->fork[philo->fork_l]);
//     }
// }

// /*This function is the send theard to 3 differente routine_action eating(), sleeping(), thinking()*/
// void *routine(void *data)
// {
//     t_philo *philo;
//     //BESOIN DE CHANGER CETTE FUNCTION
//     philo = (t_philo*)data;
//     if (philo->id % 2 == 0)
//         ft_usleep(16000);
//     while(!philo->args->is_dead)
//     {
//         eating(philo);
// 		if (philo->args->nb_eat != -1 && check_meals(philo))
// 			break;
// 		if (philo->args->is_dead)
// 			break ;
// 		sleeping(philo);
// 		if (philo->args->is_dead)
// 			break ;
// 		thinking(philo);
// 		if (philo->args->is_dead)
// 			break ;
//     }
//     return (NULL);
// }

