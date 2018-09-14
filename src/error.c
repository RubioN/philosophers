/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** error file for the philosopher
*/

#include "my.h"

int	p_err(char *str)
{
	fprintf(stderr, "%s\n", str);
	exit (84);
}

int	check_digit(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			p_err("Arg 2 and 4 must be numbers");
		i++;
	}
	return (0);
}

int	check_args_bis(char **av)
{
	if (strcmp(av[1], "-p") == 0 && strcmp(av[3], "-e") == 0) {
		check_digit(av[2]);
		check_digit(av[4]);
	}
	else
		p_err("Bad arguments");
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac == 1)
		p_err("Must have arguments");
	if (strcmp(av[1], "--help") == 0) {
		printf("USAGE\n\t./philo -p nbr_p -e nbr_e\n\n");
		printf("DESCRIPTION\n\t-p nbr_p number of philosophers\n");
		printf("\t-e nbr_e ");
		printf("maximum number times a philosopher eats ");
		printf("before exiting the program\n");
		exit (0);
	}
	if (ac != 5)
		p_err("Bad arguments");
	return (check_args_bis(av));
}
