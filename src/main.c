/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** main
*/

#include "my.h"

void	clean_all(void)
{
	int	i = 0;

	while (i < data->nb_p) {
		free(philo[i]);
		i++;
	}
	free(philo);
	free(data);
}

int	main(int ac, char **av)
{
	if (check_args(ac, av) == 84)
		return (84);
	RCFStartup(ac, av);
	init_all(ac, av);
	RCFCleanup();
	clean_all();
}