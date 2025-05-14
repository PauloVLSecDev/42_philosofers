/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:30:38 by pvitor-l          #+#    #+#             */
/*   Updated: 2025/05/14 16:48:16 by pvitor-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info	t_info;

typedef struct s_philo
{
	int					n;
	int					is_eating;
	int					num_philo;
	long				last_meal;
	int					meals_count;
	int					n_satisfied;
	bool				is_full;
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		*fork_l;
	t_info				*table;
}						t_philo;

typedef struct s_info
{
	int					time_to_die;
	int					num_philo;
	int					time_to_sleep;
	int					time_to_eat;
	int					n_satisfied;
	long				start_time;
	bool				stop;
	pthread_t			monitor_id;
	t_philo				*philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		dead;

}						t_info;

int						main(int argc, char **argv);
int						check_arguments(int argc, char **argv);
int						is_valid(char *argv);
int						ft_atoi(char *str);
int						init_struct(t_info *table, char **av);
int						init_philos(t_info *table);
int						init_fork(t_info *table);
int						init_all(char **av, t_info *table);
long					get_time(t_info *data);
long					get_absolute_time(void);
void					routine(void *philo);
void					create_philos_threads(t_info *data);
int						take_fork(t_philo *philo);
void					drop_fork(t_philo *philo);
void					print(t_philo *philo, char *str);
void					eating(t_philo *philo);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);
bool					is_dead(t_philo *philo);
bool					run_simulation(t_info *table);
void					*monitor_philo(void *data);
void					*full_philo(t_info *table);
void					free_all(t_info *table);
#endif
