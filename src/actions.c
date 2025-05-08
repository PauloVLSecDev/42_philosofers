/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:37:14 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/08 20:13:00 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_fork(t_philo *philo)
{
	int	i;
	if (philo->id % 2 == 0)	
	{
		pthread_mutex_lock(philo->fork_r)
		pthread_mutex_lock(philo->fork_l)
		print("has take  a fork");
	}
	else 
	{
		pthread_mutex_lock(philo->fork_l)
		pthread_mutex_lock(kphilo->fork_r)
		print(philo, "has take  a fork");
	}
}

void	drop_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)	
	{
		pthread_mutex_unlock(philo->fork_r)
		pthread_mutex_unlock(philo->fork_l)
		print("has give a fork");
	}
	else 
	{
		pthread_mutex_unlock(philo->fork_l)
		pthread_mutex_unlock(kphilo->fork_r)
		print(philo, "has give  a fork");
	}
	return 
}
void	print(t_philo *philo, char *str)
{
	long	ms;

	pthread_mutex_lock(philo->info->m_stop);
	ms = get_current_time(phiolo->info);	
	printf("%ld %d %s\n", ms, philo->id, str);
	pthread_mutex_unlock(philo->info->m_stop);
	return ;
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->info->m_eat);
	philo->last_meat = get_absolute_time();
	philo->meal_count++;
	if (philo->meat_count >= philo->info->n_satisfed)
		philo->is_full = true;
	print(philo, "is eating");
	star_time = get_current_time(philo->infoli);
	pthread_mutex_unlock(philo->info->m_eat)
	drop_fork(philo);
	while(valid start_time  < philo->info->time_to_eat)
		usleep(50);
}

void	sleeping(t_philo *philo)
{

}

bool	is_dead(t_philo *philo)

