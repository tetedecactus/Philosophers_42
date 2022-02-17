/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:48:17 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/17 16:27:45 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

// Status Message
# define fork_message "\e[1;90m has taken a fork 🍴 \e[0m"
# define eat_mesage "\e[1;93m is eating 🍝 \e[0m"
# define sleep_message "\e[1;35m is sleeping 😴 \e[0m"
# define think_message "\e[1;92m is thinking 🤔 \e[0m"
# define dead_message "\e[1;91m died 💀 \e[0m"

// Error message if the args are wrong!
# define args_error "To run it:\n./<Name_of_program>   <Number_of_philosopher> \
  <Time_to_die>   <Time_to_eat>   <Time_to_sleep>   :optionel \
<Number_of_times_each_philosopher_must_eat>\n"
# define mutex_error "Mutex intialization failed\n"

typedef enum e_status
{
    eat,
    sleep_dodd,
    think,
    dead,
}   t_status;

typedef struct s_info
{
    int                 nb_philo;
    int                 tt_die;
    int                 tt_eat;
    int                 tt_sleep;
    int                 nb_eat;
	long    			start_time;
    pthread_mutex_t     *fork;
    pthread_mutex_t     status;
    
}       t_info;

typedef struct s_philo
{
	int				    id;
	int				    fork_l;
	int				    fork_r;
	int				    meals;
    int                 is_dead;
	pthread_mutex_t	    fork_protect;
    t_info              args;
    t_status            status;
    
}       t_philo;

typedef struct s_data
{
    t_philo *philo;
    t_info  info;
    
} t_data;

//Main 
void        start_diner(t_data *data);

//Init
t_info init_info(int ac, char **av, t_data *data);
t_philo *init_philo(t_data *data);

//Utils
int         ft_atoi(const char *str);
int         ft_isdigit(int c);
long         time_ms(void);
void	    ft_usleep(long time_in_ms);
long 	    current_time(t_philo *philo);

// Status
void print_status(t_philo *philo, char *message);

//Routine 
void *routine(void *data);

#endif