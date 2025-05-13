/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:07:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/12 21:20:12 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philos_threads(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&data->philo[i].thread_id, NULL, (void *)routine_teste,
			&data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
		pthread_join(data->philo[i++].thread_id, NULL);
	return ;
}

void	routine_teste(void *data)
{
	long		time;
	int		i;
	t_philo		*philo;
	t_info		*count;

	philo = (t_philo *)data;
	count = philo->table;
	time = get_time(count);
	i = 0;
	while (run_simulation(count))
	{
		if (take_fork(philo))
		{
			eating(philo);
			drop_fork(philo);
			sleeping(philo);
			thinking(philo);
		}
		i++;
	}
	return ;
}
