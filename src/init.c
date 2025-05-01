/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:27:13 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/04/30 21:10:30 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	init_struct(t_info *program, char **argv)
{
	pthread_mutex_init(&program->m_stop, NULL);
	pthread_mutex_init(&program->m_eat, NULL);
	pthread_mutex_init(&program->dead, NULL);
	program->stop = 0;
	progam->philo = malloc(sizeof(t_philo) * program->num_philo);
	if (!program->philo)
		return (2);
	program->number_philo = ft_atoi(argv[1]); 
	program->time_to_die = ft_atoi(argv[2]); 
	program->time_to_eat = ft_atoi(argv[3]); 
	program->time_to_spleep = ft_atoi(argv[4]); 
	if (argv[5])
		program->n_satisfid = ft_atoi(argv[5]);
	if (program->num_philo == 0)
		return (1);			
	return (0);
}


/* this function will be who init the struct philo
int	init_philos(t_info *progam, )
{
	int value;
	value = ft_atoi(argv[1]);
	while (i < value)
	{
		printf("criando threads numero %i\n", i);
		result = pthread_create(&threads[i], NULL, teste_thread,
				(void *)(intptr_t)i);
		if (result)
			printf("falha na criacao da thread %i\n", result);
		i++;
	}

}
*/
