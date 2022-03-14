/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:37:47 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 16:36:50 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
	
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	pthread_mutex_t *fork;
	pthread_mutex_t status;
	int             nb_philo;
	int             tt_die;
	int             tt_eat;
	int             tt_sleep;
	int             nb_meal;
}   t_info;

typedef struct s_philo
{
	pthread_t 		philo_th;
	pthread_t 		is_dead_th;
	t_info 			info;
	long            timer;
	int 			id;
	int				fork_l;
	int				fork_r;
	bool			is_dead;
}   t_philo;

typedef struct s_data
{
	t_philo *philo;
	t_info 	info;
	pthread_t 	timere;
} t_data;

#endif