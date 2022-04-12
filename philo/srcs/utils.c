#include "../includes/philo.h"

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

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = time_ms();
	while ((time_ms() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

/* This function give the delta between now and the time we start*/
long long	current_time(t_philo *philo)
{
	long long	time_in_ms;

	time_in_ms = (time_ms() - philo->info.start_time);
	return (time_in_ms);
}

/* This function give the actual time in micro second */
long long	time_ms(void)
{
	struct timeval	time;
	long long		real_time;

	real_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		return (printf("gettimeofday failed.\n"));
	real_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (real_time);
}