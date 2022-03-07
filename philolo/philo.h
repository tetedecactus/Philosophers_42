/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:59:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/04 18:59:37 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include "def.h"

typedef struct s_philo   t_philo;
typedef struct s_info    t_info;

typedef struct s_info
{
	pthread_mutex_t *fork;
	pthread_mutex_t status;
	t_philo         *philo;
	int             nb_philo;
	int             tt_die;
	int             tt_eat;
	int             tt_sleep;
	int             nb_meal;
}   t_info;

typedef struct s_philo
{
	t_info 			*info;
	long            timer;
	int 			id;
	int				fork_l;
	int				fork_r;
	bool			is_dead;
}   t_philo;

// Init function
int     init(t_info *info, int ac, char **av);

// Utils function
int	    ft_atoi(const char *str);
int     ft_isdigit(int c);
long	current_time(t_philo *philo);
long    time_ms(void);
void	ft_usleep(long time_in_ms); 

// Routine function
void    *routine(void *data);

// Status function
void    print_status(t_philo  *philo, char *status);

#endif
