/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:13 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/02 18:06:06 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_struct(t_info *program, char **argv)
{
	pthread_mutex_init(&program->m_stop, NULL);
	pthread_mutex_init(&program->m_eat, NULL);
	pthread_mutex_init(&program->dead, NULL);
	program->stop = 0;
	program->num_philo = ft_atoi(argv[1]); 
	program->time_to_die = ft_atoi(argv[2]); 
	program->time_to_eat = ft_atoi(argv[3]); 
	program->time_to_spleep = ft_atoi(argv[4]); 
	if (argv[5])
		program->n_satisfied = ft_atoi(argv[5]);
	if (program->num_philo == 0)
		return (1);
	return (0);
}

// this function will be who init the struct philo
int	init_philos(t_info *program)
{
	int i = 0;
	program->philo = malloc(sizeof(t_philo) * program->num_philo);
	if (!program->philo)
		return (2);
	//	program->time_start = time_marker;
	while (i < program->num_philo)
	{
		program->philo[i].thread_id = i + 1;
		program->philo[i].last_eat = program->time_start;
		program->philo[i].n_satisfied = 0;
		program->philo[i].fork_r = &program->philo->fork_r[i];
		program->philo[i].fork_l = &program->philo->fork_l[i + 1 % program->num_philo];
		i++;
	
	}
	return (0);
}
