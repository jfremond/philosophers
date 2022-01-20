/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:07:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 22:14:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdio.h>

# include "messages.h"

/* Structures */
typedef struct s_infos
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	long			start_time;
	long			start_time_sec;
	long			start_time_usec;
	int				died;
	struct s_philo	*ptr_philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	has_died;
	pthread_mutex_t	enough_meals;
	pthread_mutex_t	print_state;
	pthread_mutex_t	thread_create;
}		t_infos;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	long			last_meal;
	t_infos			*ptr_infos;
	pthread_t		tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}		t_philo;

/* Parsing */
int			check_arg_digit(char *arg);
int			check_arg_int(char *arg);
int			check_arg_sign(char *arg);
int			check_arg_validity(int argc, char **argv);

/* Time */
int			init_time(t_infos *time);
long		get_time(t_infos *time);
int			standing_action(t_infos *infos, int time_to_reach);

/* Messages */
void		print_state(t_philo *philo, char *state);
int			print_error(char *error_message);

/* Init structures */
int			init_values(t_infos *init, char **argv);
int			init_philo(t_infos *infos);
int			init_forks(t_infos *infos);

/* Stop routine */
int			is_dead(t_philo *philo);
int			has_eaten_enough(t_philo *philo);
void		death_watcher(t_infos *infos);

/* Routine */
void		philo_eat(t_philo *philo);
void		*dispatch_philos(void *arg);
void		routine(t_philo *philo);
void		one_philo_routine(t_philo *philo);

/* Mutexes */
int			mutex_init(t_infos *mutex);
int			mutex_destroy(t_infos *mutex);

/* Errors */
int			free_error(t_infos *infos);

/* Auxiliary functions */
long long	ft_atoll(const char *str);
int			ft_isdigit(char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);

#endif