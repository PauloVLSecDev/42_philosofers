/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:30:38 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/04/29 20:34:06 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	main(int argc, char **argv);
int	check_arguments(int argc, char **argv);
int	is_valid(char *argv);
int 	ft_atoi(char *str);
void	*teste_thread(void *thread_id);

#endif
