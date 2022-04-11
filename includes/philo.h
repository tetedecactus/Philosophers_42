/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:59:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/11 18:29:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include "def.h"

// Init function
// t_philo *init_philo(t_info *info, t_philo *philo, int ac, char **av);
int     init_philo(t_info *info, t_philo *philo, int ac, char **av);
int init_info(t_info *info, int ac, char **av);
int init_fork(t_philo *philo);

// Utils function
long long	current_time(t_philo *philo);
long long time_ms(void);
int	    ft_atoi(const char *str);
int     ft_isdigit(int c);
void	ft_usleep(long long time_in_ms); 

// Routine function 
void    *routine(void *data);

// Status function
void    print_status(t_philo  *philo, char *status, int dead);
void    display_info(void);
void    print_philo_info(t_philo *philo, t_info *info);
int     check_which_die(t_info *info);
void 	*is_dead(void *data);
void	sleep_dodo(t_philo *philo);
int    ft_strcmp(const char *s1, const char *s2);


// void    print_status(t_philo *philo, char *str);

#endif
