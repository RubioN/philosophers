/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** algorithm for the philosopher
*/

#include "my.h"

t_philo	**philo;
t_data	*data;

int	eat(t_philo *philo)
{
	lphilo_take_chopstick(&philo->next->mutex);
	lphilo_take_chopstick(&philo->mutex);
	philo->state = 0;
	lphilo_eat();
	usleep(EAT_TIME);
	lphilo_release_chopstick(&philo->next->mutex);
	lphilo_release_chopstick(&philo->mutex);
	philo->e++;
	pthread_mutex_unlock(&philo->next->mutex);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	think(t_philo *philo)
{
	lphilo_take_chopstick(&philo->mutex);
	philo->state = 1;
	lphilo_think();
	usleep(THINK_TIME);
	lphilo_release_chopstick(&philo->mutex);
	return (0);
}

int	p_sleep(t_philo *philo)
{
	philo->state = 2;
	lphilo_sleep();
	return (0);
}
