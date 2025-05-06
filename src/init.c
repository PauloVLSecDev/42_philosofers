/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:13 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/06 18:37:57 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_struct(t_info *program, char **av)
{
	pthread_mutex_init(&program->m_stop, NULL);
	pthread_mutex_init(&program->m_eat, NULL);
	pthread_mutex_init(&program->dead, NULL);
	program->stop = 0;
	program->num_philo = ft_atoi(av[1]);
	program->time_to_die = ft_atoi(av[2]);
	program->time_to_eat = ft_atoi(av[3]);
	program->time_to_spleep = ft_atoi(av[4]);
	if (av[5])
		program->n_satisfied = ft_atoi(av[5]);
	if (program->num_philo == 0)
		return (1);
	return (0);
}

int	init_fork(t_info *program)
{
	int	i;
	int	philos;

	i = 0;
	philos = program->num_philo;
	program->forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (!program->forks)
		return (1);
	while (i < philos)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philos(t_info *program)
{
	int	i;

	i = 0;
	program->philo = malloc(sizeof(t_philo) * program->num_philo);
	if (!program->philo)
		return (1);
	program->start_time = get_absolute_time();
	while (i < program->num_philo)
	{
		program->philo[i].id = i + 1;
		program->philo[i].last_eat = program->start_time;
		program->philo[i].n_satisfied = 0;
		program->philo[i].fork_r = &program->forks[i];
		program->philo[i].fork_l = &program->forks[(i + 1)
			% program->num_philo];
		program->philo[i].info = program;
		i++;
	}
	return (0);
}

int	init_all(char **av, t_info *program)
{
	if (init_struct(program, av))
		return (1);
	if (init_philos(program))
		return (1);
	if (init_fork(program))
		return (1);
	return (0);
}
