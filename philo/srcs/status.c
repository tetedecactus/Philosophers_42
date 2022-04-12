#include "../includes/philo.h"

void	display_info(void)
{
	printf("|---------|-------|-------------------------|\n");
	printf("| Time ms | Philo |         Action          |\n");
	printf("|---------|-------|-------------------------|\n");
}

void	print_status(t_philo *philo, char *status, int dead)
{
	pthread_mutex_lock(&philo->info.mutex->is_dead);
	if (philo->info.stop == 1)
	{
		pthread_mutex_unlock(&philo->info.mutex->is_dead);
		return ;
	}
	if (dead == 1)
		philo->info.stop = 1;
	pthread_mutex_unlock(&philo->info.mutex->is_dead);
	pthread_mutex_lock(&philo->info.mutex->print_status);
	printf("| %lld\t  | %d\t  |%s\n", current_time(philo), philo->id, status);
	pthread_mutex_unlock(&philo->info.mutex->print_status);
}