/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:43:11 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 19:14:42 by pvitor-l         ###   ########.fr       */
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
		if (ft_atoi(argv[i]) == 0)
			return (1);
		flag = is_valid(argv[i]);
		i++;
	}
	return (flag);
}

int	is_valid(char *argv)
{
	int	k;

	k = 0;
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
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	print(t_philo *philo, char *str)
{
	long	ms;

	if (!run_simulation(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->m_print);
	ms = get_time(philo->table);
	printf("%ld %d %s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->table->m_print);
	return ;
}

bool	is_dead(t_philo *philo)
{
	t_info	*table;
	long	time_of_life;
	bool	dead_status;

	dead_status = false;
	table = philo->table;
	pthread_mutex_lock(&table->m_eat);
	time_of_life = get_absolute_time() - philo->last_meal;
	if (time_of_life >= table->time_to_die + 1)
		dead_status = true;
	pthread_mutex_unlock(&table->m_eat);
	return (dead_status);
}
