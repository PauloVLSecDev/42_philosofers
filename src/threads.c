/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:07:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 16:48:45 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philos_threads(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&data->philo[i].thread_id, NULL, (void *)routine,
			&data->philo[i]);
		i++;
	}
	pthread_create(&data->monitor_id, NULL, (void *)monitor_philo, data);
	i = 0;
	while (i < data->num_philo)
		pthread_join(data->philo[i++].thread_id, NULL);
	pthread_join(data->monitor_id, NULL);
	return ;
}

void	routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->num_philo == 1)
		return ;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (run_simulation(philo->table))
	{
		if (take_fork(philo))
		{
			eating(philo);
			drop_fork(philo);
			sleeping(philo);
			thinking(philo);
		}
		usleep(100);
	}
	return ;
}

void	*monitor_philo(void *data)
{
	int		i;
	t_info	*table;

	i = 0;
	table = (t_info *)data;
	while (run_simulation(table))
	{
		i = 0;
		while (i < table->num_philo)
		{
			if (is_dead(&table->philo[i]))
			{
				print(table->philo, "is dead");
				pthread_mutex_lock(&table->m_stop);
				table->stop = true;
				pthread_mutex_unlock(&table->m_stop);
				return (NULL);
			}
			i++;
		}
		full_philo(table);
	}
	return (NULL);
}

void	*full_philo(t_info *table)
{
	int	philo_is_full;
	int	i;

	i = 0;
	philo_is_full = 0;
	while (i < table->num_philo && table->n_satisfied > 0)
	{
		pthread_mutex_lock(&table->m_stop);
		if (table->philo[i].is_full)
			philo_is_full++;
		pthread_mutex_unlock(&table->m_stop);
		i++;
		if (philo_is_full == table->num_philo)
		{
			pthread_mutex_lock(&table->m_stop);
			table->stop = true;
			pthread_mutex_unlock(&table->m_stop);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

bool	run_simulation(t_info *table)
{
	bool	run;

	pthread_mutex_lock(&table->m_stop);
	run = !table->stop;
	pthread_mutex_unlock(&table->m_stop);
	return (run);
}
