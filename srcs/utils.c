/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:22:07 by olabrecq          #+#    #+#             */
/*   Updated: 2022/04/21 10:43:20 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = time_ms();
	while ((time_ms() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pstr;

	i = 0;
	pstr = (unsigned char *)s;
	while (i < n)
	{
		pstr[i] = 0;
		i++;
	}
	s = pstr;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	size *= count;
	b = (void *)malloc(size);
	if (b)
		ft_bzero(b, size);
	return (b);
}
