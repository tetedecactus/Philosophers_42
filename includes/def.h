/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:29:01 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 17:23:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H 

# define ARG_ERR "ERROR"
# define AV1_ERR "NUMBER_OF_PHILOSOPHERS MUST BE BETWEEN [1-200]"
# define AV2_ERR "TIME_TO_DIE MUST BE [60["
# define AV3_ERR "TIME_TO_EAT MUST BE [60["
# define AV4_ERR "TIME_TO_SLEEP MUST BE [60["
# define AV5_ERR "NUMBER_OF_TIME_EAT MUST BE [1["

# define MEMSET_ERR "ERROR MEMSET"
# define THREAD_ERR "THREAD ERROR"
# define FORK_INIT_ERR "ERROR FORK INIT"
# define MUTEX_INIT_ERR "ERROR MUTEX INIT"
# define INIT_DATA_ERR "ERROR DATA INIT"
# define INIT_INFO_ERR "ERROR INFO INIT"
# define PHILO_INIT_ERR "ERROR PHILO INIT"
# define JOIN_THREAD_ERR "ERROR JOIN THREAD"
# define DESTROY_MUTEX_ERR "ERROR DESTROY MUTEX"

# define DINER_ERR "NOBODY WAS HUNGRY"
# define CLEAR_ERR "WAITIER LEFT URLY"

# define EAT "\e[1;93m is eating 🍝 \e[0m"
# define FORK "\e[1;90m has taken a fork 🍴 \e[0m"
# define SLEEP "\e[1;35m is sleeping 😴 \e[0m"
# define THINK "\e[1;92m is thinking 🤔 \e[0m"
# define DEAD "\e[1;91m died 💀 \e[0m"

#endif 
