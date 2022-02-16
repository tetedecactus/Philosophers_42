/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:48:17 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/16 14:38:09 by olabrecq         ###   ########.fr       */
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
    sleep_dodo,
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
    int                 timer;
    pthread_mutex_t     *fork;
    pthread_mutex_t     status;
    //t_philo *philo;changer pour que les strcut ce call entre ell
    
}       t_info;

typedef struct s_philo
{
	int				    id;
	int				    fork_l;
	int				    fork_r;
	int				    start_time;
    int                 is_dead;
	pthread_mutex_t	    fork_protect;
    t_info              args;
    // t_info              *args;// 

    t_status            status;
    
}       t_philo;

typedef struct s_data
{
    t_philo *philo;
    t_info  info;
    
} t_data;

// Init struct 
t_philo *init_philo(t_data *data);
t_info init_info(int ac, char **av, t_data *data);

//Utils
int         ft_atoi(const char *str);
int         ft_isdigit(int c);
long        time_ms(void);
long        current_time(t_philo *philo);
void	      ft_usleep(long time_in_ms);
void        print_info_philo(t_philo philo);

// Routine
void *routine(void *data);

// Status
void print_status(t_philo *philo, char *message);


#endif