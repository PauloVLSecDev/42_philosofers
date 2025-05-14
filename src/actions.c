/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:37:14 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 16:47:00 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_fork(t_philo *philo)
{
	if (!run_simulation(philo->table))
		return (0);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_r);
		pthread_mutex_lock(philo->fork_l);
		print(philo, "has taken a fork");
		return (1);
	}
	else
	{
		pthread_mutex_lock(philo->fork_l);
		pthread_mutex_lock(philo->fork_r);
		print(philo, "has taken a fork");
		return (1);
	}
	if (!run_simulation(philo->table))
		return (0);
}

void	drop_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->fork_r);
		pthread_mutex_unlock(philo->fork_l);
	}
	else
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
	}
	return ;
}

void	eating(t_philo *philo)
{
	long	s_time;
	t_info	*table;

	table = philo->table;
	if (!run_simulation(table))
		return ;
	pthread_mutex_lock(&philo->table->m_eat);
	philo->last_meal = get_absolute_time();
	philo->meals_count++;
	if (philo->meals_count >= table->n_satisfied)
		philo->is_full = true;
	pthread_mutex_unlock(&philo->table->m_eat);
	if (!run_simulation(table))
		return ;
	print(philo, "is eating");
	s_time = get_time(table);
	while (run_simulation(table) && get_time(table)
		- s_time < table->time_to_eat)
		usleep(50);
}

void	sleeping(t_philo *philo)
{
	long	s_time;
	t_info	*table;

	table = philo->table;
	if (!run_simulation(table))
		return ;
	print(philo, "is sleeping");
	s_time = get_time(table);
	while (run_simulation(table) && get_time(table)
		- s_time < table->time_to_sleep)
		usleep(50);
	return ;
}

void	thinking(t_philo *philo)
{
	long	s_time;
	t_info	*table;

	table = philo->table;
	if (!run_simulation(table))
		return ;
	print(philo, "is thinking");
	s_time = get_time(table);
	while (run_simulation(table) && get_time(table)
		- s_time < table->time_to_sleep)
		usleep(50);
}
