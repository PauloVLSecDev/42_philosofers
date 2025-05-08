/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:37:14 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/07 21:16:30 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_fork(t_philo *philo, t_info data)
{
	int	i;
	if (philo->id % 2 == 0)	
	{
		pthread_mutex_lock(philo->fork_r)
		pthread_mutex_lock(philo->fork_l)
		print("has take  a fork");
	}
	else 
		pthread_mutex_lock(philo->fork_l)
		pthread_mutex_lock(kphilo->fork_r)
		print(philo, "has take  a fork");
	if (drop_fork(philo->info, philo))
	{
		pthread_mutex_unlock(&philo->fork_r)
			
	}
}

void print(t_philo *philo, char *str)
{
	long	ms;

	pthread_mutex_lock(philo->info->m_stop);
	ms = get_current_time(phiolo->info);	
	printf("%ld %d %s\n", ms, philo->id, str);  
	pthread_mutex_unlock(philo->info->m_stop);

}

void	drop_fork(t_philo *philo)

void	eating(t_philo *philo)

void	sleeping(t_philo *philo)

bool	is_dead(t_philo *philo)

