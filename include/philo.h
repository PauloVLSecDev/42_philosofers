/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:30:38 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/05 21:00:02 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				n;
	int				is_eating;
	int				num_philo;
	int				last_eat;
	int				n_satisfied;
	pthread_t		thread_id;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct t_info	*info;
}					t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				num_philo;
	int				time_to_spleep;
	int				time_to_eat;
	int				n_satisfied;
	int				time_start;
	int				stop;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;

}					t_info;

int					main(int argc, char **argv);
int					check_arguments(int argc, char **argv);
int					is_valid(char *argv);
int					ft_atoi(char *str);
int					init_struct(t_info *program, char **av);
int					init_philos(t_info *program);
int					init_fork(t_info *program);
int					init_all(char **av, t_info *program);
size_t					get_current_time(void);
#endif
