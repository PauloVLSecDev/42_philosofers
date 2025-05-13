/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/06 20:33:27 by pvitor-l         ###   ########.fr       */
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
	{
		printf("error\n");
		return (0);
	}
	create_philos_threads(&program);
	printf("VALID\n");
	return (0);
}
