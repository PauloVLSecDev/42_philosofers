/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:37:14 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/12 21:06:29 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_fork(t_philo *philo)
{
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
	//	print(philo, "is thinking");
	return ;
}

void	print(t_philo *philo, char *str)
{
	long	ms;

	if (!run_simulation(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->m_print);
	ms = get_time(philo->table);
	printf("%ld %d %s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->table->m_print);
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
	drop_fork(philo);
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
	while (run_simulation(table) && get_time(table) - s_time < table->time_to_sleep)
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
	while (run_simulation(table) && get_time(table) - s_time < table->time_to_sleep)
		usleep(50);
}

bool	is_dead(t_philo *philo)
{
	t_info	*table;
	long	time_of_life;
	bool	dead_status;

	dead_status = false;
	table = philo->table;
	pthread_mutex_lock(&table->m_eat);
	time_of_life = get_absolute_time() - philo->last_meal;
	if (time_of_life >= table->time_to_die)
		dead_status = true;
	pthread_mutex_unlock(&table->m_eat);
	return (dead_status);
}

bool	run_simulation(t_info *table)
{
	bool	run;

	pthread_mutex_lock(&table->m_stop);
	run = !table->stop;
	pthread_mutex_unlock(&table->m_stop);
	return (run);
}
