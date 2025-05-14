/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:22:51 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 16:24:44 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_absolute_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_time(t_info *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->start_time);
}

void	free_all(t_info *table)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&table->m_stop);
	pthread_mutex_destroy(&table->m_print);
	pthread_mutex_destroy(&table->m_eat);
	pthread_mutex_destroy(&table->dead);
	if (!table)
		return ;
	if (table->forks)
	{
		i = 0;
		while (i < table->num_philo)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philo)
		free(table->philo);
	return ;
}
