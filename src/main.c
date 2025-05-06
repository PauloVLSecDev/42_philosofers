/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/05 20:57:01 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_info	program;
	int		i;

	i = 0;
	if (check_arguments(argc, argv))
	{
		printf("invalid argument\n");
		return (0);
	}
	if (init_all(argv, &program))
		printf("error");
	printf("VALID\n");
	return (0);
}

/*
void	*teste_thread(void *thread_id)
{
	int	id;

	usleep(10000);
	id = (int)(intptr_t)thread_id;
	printf("eu sou um thread %d\n", id);
	pthread_exit(NULL);
}
*/
