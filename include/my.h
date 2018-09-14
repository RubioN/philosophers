/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** my.h
*/

#pragma once

#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "extern.h"

#define EAT_TIME 1000
#define THINK_TIME 1000

typedef struct	s_philo
{
	int		n;
	int		state;
	int		e;
	pthread_t	id;
	pthread_mutex_t	mutex;
	struct s_philo	*next;
}	t_philo;

typedef struct	s_data
{
	int	nb_p;
	int	nb_e;
}	t_data;

extern t_philo	**philo;
extern t_data	*data;

int	check_args(int ac, char **av);
int	p_err(char *str);
void	clean_all();
int	init_all(int ac, char **av);
void	*algo_core(void *philo);
int	p_sleep(t_philo *philo);
int	eat(t_philo *philo);
int	think(t_philo *philo);
