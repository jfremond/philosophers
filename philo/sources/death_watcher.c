/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_watcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:17:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 17:25:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr_infos->has_died);
	if (philo->ptr_infos->died)
	{
		pthread_mutex_unlock(&philo->ptr_infos->has_died);
		return (1);
	}
	pthread_mutex_unlock(&philo->ptr_infos->has_died);
	return (0);
}

int	has_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr_infos->enough_meals);
	if (philo->nb_meal == philo->ptr_infos->meals)
	{
		pthread_mutex_unlock(&philo->ptr_infos->enough_meals);
		return (1);
	}
	pthread_mutex_unlock(&philo->ptr_infos->enough_meals);
	return (0);
}

void	death_watcher(t_infos *infos)
{
	int			i;
	long		time;

	i = 0;
	pthread_mutex_lock(&infos->print_state);
	while (i < infos->nb_philos)
	{
		time = get_time(infos);
		if (time > infos->time_to_die + infos->ptr_philo[i].last_meal
			&& !is_dead(&infos->ptr_philo[i])
			&& !has_eaten_enough(&infos->ptr_philo[i]))
		{
			pthread_mutex_lock(&infos->has_died);
			infos->died = 1;
			pthread_mutex_unlock(&infos->has_died);
			printf("%ld %d died\n", get_time(infos), infos->ptr_philo[i].id);
		}
		pthread_mutex_unlock(&infos->print_state);
		return ;
		++i;
	}
}
