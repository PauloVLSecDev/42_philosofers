/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:43:11 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/04/29 20:47:13 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arguments(int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (argc < 5 || argc > 6)
		flag = 1;
	while (argv[i] != NULL && flag != 1)
	{
		flag = is_valid(argv[i]);
		i++;
	}
	return (flag);
}

int	is_valid(char *argv)
{
	int	k;
	int	len;

	k = 0;
	len = 0;
	if (!argv || !*argv)
		return (1);
	while (argv[k])
	{
		if (!(argv[k] >= '0' && argv[k] <= '9'))
			return (1);
		k++;
	}
	return (0);
}


int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int i;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= 9)
	{
		result = result * 10 + str[i] - '-';
		i++;
	}
	return (result * sign);
}

