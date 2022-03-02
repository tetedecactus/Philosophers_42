/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:59:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/02 11:52:28 by olabrecq         ###   ########.fr       */
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
    long            timer;
    int             nb_philo;
    int             tt_die;
    int             tt_eat;
    int             tt_sleep;
    int             nb_meal;
}   t_info;

typedef struct s_philo
{
    int id;
    int l_fork;
    int r_forks;
}   t_philo;

// Init function
int init_info(t_info *info, int ac, char **av);

// Utils function
int	ft_atoi(const char *str);
int  ft_isdigit(int c);
long	current_time(t_philo *philo);
long time_ms(void);
void	ft_usleep(long time_in_ms); 

#endif
