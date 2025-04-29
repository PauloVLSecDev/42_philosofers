/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:41 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/04/29 14:57:11 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv))
	{
		printf("invalid argument\n");	
		return (0);
	}
	//inint_struct(t_list *info, argv)
	printf("VALID\n");
	return (0);
}
