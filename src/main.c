/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/04/30 21:03:41 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int			i;
	int			result;
	int			value;
	pthread_t	threads[ft_atoi(argv[1])];

	i = 0;
	if (check_arguments(argc, argv))
	{
		printf("invalid argument\n");
		return (0);
	}
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
	// inint_struct(t_list *info, argv)
	printf("VALID\n");
	return (0);
}

void	*teste_thread(void *thread_id)
{
	int	id;

	usleep(10000);
	id = (int)(intptr_t)thread_id;
	printf("eu sou um thread %d\n", id);
	pthread_exit(NULL);
}



