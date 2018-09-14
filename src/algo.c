/*
** EPITECH PROJECT, 2018
** algo
** File description:
** philo
*/

#include "my.h"

void	all_chop_available(t_philo *p)
{
	think(p);
	eat(p);
	p_sleep(p);
}

void	unlock_chop(t_philo *p, int check, int check_next)
{
	if (check_next == 0)
		pthread_mutex_unlock(&p->next->mutex);
	if (check == 0)
		pthread_mutex_unlock(&p->mutex);
}

void	*algo_core(void *philo)
{
	t_philo *p = ((t_philo *)philo);
	int     check;
	int     check_next;

	while (p->e < data->nb_e) {
		check = pthread_mutex_trylock(&p->mutex);
		check_next = pthread_mutex_trylock(&p->next->mutex);
		if (check == 0 && check_next == 0)
			all_chop_available(p);
		else
			unlock_chop(p, check, check_next);
	}
	return (NULL);
}
