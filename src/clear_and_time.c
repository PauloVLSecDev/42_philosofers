/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:22:51 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/06 18:48:32 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_absolute_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_current_time(t_info *data)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->start_time);
}
