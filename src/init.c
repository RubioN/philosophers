/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** init
*/

#include "my.h"

t_philo	**philo;
t_data	*data;

void	create_list(void)
{
	int	i = 0;

	while (i < data->nb_p) {
		if (i + 1 >= data->nb_p)
			philo[i]->next = philo[0];
		else
			philo[i]->next = philo[i + 1];
		pthread_create(&(philo[i]->id), NULL, algo_core, philo[i]);
		i++;
	}
}

void	create_philo(t_data *data)
{
	int	i = 0;

	philo = malloc(sizeof(t_philo *) * (data->nb_p + 1));
	if (philo == NULL)
		p_err("Error with malloc(philo)");
	while (i < data->nb_p) {
		philo[i] = malloc(sizeof(t_philo *) * 10);
		if (philo[i] == NULL)
			p_err("Error with malloc(philo[i])");
		philo[i]->n = i;
		philo[i]->state = 2;
		philo[i]->e = 0;
		pthread_mutex_init(&(philo[i]->mutex), NULL);
		i++;
	}
	create_list();
}

void	join_philo(t_data *data)
{
	int	i = 0;

	while (i < data->nb_p)
	{
		pthread_join(philo[i]->id, NULL);
		i++;
	}
}

int	init_all(int ac, char **av)
{
	ac = ac;
	data = malloc(sizeof(t_data *));
	if (data == NULL)
		p_err("Error with malloc(data)");
	data->nb_p = atoi(av[2]);
	data->nb_e = atoi(av[4]);
	if (data->nb_p == 0 || (data->nb_p < 2 || data->nb_p > 2000)
		|| data->nb_e == 0)
		p_err("Bad args 2 or 4");
	create_philo(data);
	join_philo(data);
	return (0);
}