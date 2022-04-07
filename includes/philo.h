/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:59:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/07 11:00:10 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include "def.h"

// Init function
int init_philo(t_info *info, int ac, char **av);
int init_info(t_info *info, int ac, char **av);
int init_fork(t_info *info);

// Utils function
long	current_time(t_philo philo);
long    time_ms(void);
int	    ft_atoi(const char *str);
int     ft_isdigit(int c);
void	ft_usleep(long time_in_ms); 

// Routine function 
void    *routine(void *data);

// Status function
int     check_meal(t_philo *philo);
void    print_status(t_philo  *philo, char *status);
void    display_info(void);
void    print_philo_info(t_info *info);
int     check_which_die(t_info *info);

#endif
