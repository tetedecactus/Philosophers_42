/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:22:07 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/14 12:31:32 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	long			num;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return ((long)(sign * num));
}

int  ft_isdigit(int c)
{
    return ((c >= '0' && c <= '9'));
}

long	current_time(t_philo *philo)
{
	long time_in_ms;

	time_in_ms = time_ms() - philo->timer;
	return (time_in_ms);
}

long time_ms(void)
{
  struct timeval time;
  long rtime;

  rtime = 0;
  if (gettimeofday(&time, NULL) == -1)
        return (printf("gettimeofday failed.\n"));
  rtime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
  return (rtime);
}

void	ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = 0;
	start_time = time_ms();
	while ((time_ms() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
