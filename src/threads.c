/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:07:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/06 19:21:35 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_philos_threads(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&data->philo[i].id, NULL, (void *)routine_teste,
			&data->philo[i]);
		pthread_join(data->philo->id, NULL);
		i++;
	}
	return ;
}

void	routine_teste(void *data)
{
	long	time;
	int		i;
	t_philo	*philo;
	t_info	*count;

	philo = (t_philo *)data;
	count = philo->info;
	time = get_current_time(count);
	i = 0;
	while (i < count->num_philo)
	{
		usleep(1000);
		printf("%ld o id desta thread e este %i\n", time, i);
		i++;
	}
	return ;
}
