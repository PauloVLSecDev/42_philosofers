/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:13 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 16:36:38 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_struct(t_info *table, char **av)
{
	pthread_mutex_init(&table->m_stop, NULL);
	pthread_mutex_init(&table->m_eat, NULL);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_init(&table->m_print, NULL);
	table->stop = false;
	table->num_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->n_satisfied = ft_atoi(av[5]);
	else
		table->n_satisfied = -1;
	if (table->num_philo == 0)
		return (1);
	return (0);
}

int	init_fork(t_info *table)
{
	int	i;
	int	philos;

	i = 0;
	philos = table->num_philo;
	table->forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (!table->forks)
		return (1);
	while (i < philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philos(t_info *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->num_philo);
	if (!table->philo)
		return (1);
	table->start_time = get_absolute_time();
	while (i < table->num_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].last_meal = table->start_time;
		table->philo[i].meals_count = 0;
		table->philo[i].is_full = false;
		table->philo[i].fork_r = &table->forks[i];
		table->philo[i].fork_l = &table->forks[(i + 1) % table->num_philo];
		table->philo[i].table = table;
		i++;
	}
	return (0);
}

int	init_all(char **av, t_info *table)
{
	if (init_struct(table, av))
		return (1);
	if (init_fork(table))
		return (1);
	if (init_philos(table))
		return (1);
	return (0);
}
