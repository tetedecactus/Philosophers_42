/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:59:50 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 14:19:06 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include "def.h"

// Init function
int     init_data(t_data *data, int ac, char **av);

// Utils function
int	    ft_atoi(const char *str);
int     ft_isdigit(int c);
long	current_time(t_philo *philo);
long    time_ms(void);
void	ft_usleep(long time_in_ms); 

// Routine function
void    *routine(void *d);

// Status function
void    print_status(t_philo  *philo, char *status);
void    display_info(void);

#endif