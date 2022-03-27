/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:37:47 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/27 10:06:48 by olabrecq         ###   ########.fr       */
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

struct s_info;

typedef	struct			s_philo
{
	pthread_t			philo_th;
	pthread_t 			checker;
	struct s_info		*infos;
	long				t_last_meal;
	int					id;
	int					x_ate;
	int					l_fork;
	int					r_fork;
}						t_philo;

typedef struct			s_info
{
	pthread_mutex_t		*fork;
	pthread_mutex_t 	is_dead;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		writing_status;
	t_philo				*philos;
	long				first_timestamp;
	int					nb_philo;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					num_must_eat;
	bool				dieded;
	bool				all_ate;
} t_info;

#endif