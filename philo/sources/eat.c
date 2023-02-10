/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:20:20 by jfremond          #+#    #+#             */
/*   Updated: 2023/02/10 11:12:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	if (!is_dead(philo))
	{
		if (philo->id == philo->ptr_infos->nb_philos)
		{
			pthread_mutex_lock(philo->right_fork);
			print_state(philo, FORK);
			pthread_mutex_lock(philo->left_fork);
			print_state(philo, FORK);
		}
		else
		{
			pthread_mutex_lock(philo->left_fork);
			print_state(philo, FORK);
			pthread_mutex_lock(philo->right_fork);
			print_state(philo, FORK);
		}
	}
}

void	increase_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->ptr_infos->enough_meals);
	if (philo->ptr_infos->meals != -1)
		++philo->nb_meal;
	philo->last_meal = get_time(philo->ptr_infos);
	pthread_mutex_unlock(&philo->ptr_infos->enough_meals);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	if (!is_dead(philo))
	{
		pthread_mutex_lock(&philo->ptr_infos->print_state);
		increase_meal(philo);
		printf("%ld %d is eating\n", get_time(philo->ptr_infos), philo->id);
		pthread_mutex_unlock(&philo->ptr_infos->print_state);
		standing_action(philo->ptr_infos, philo->ptr_infos->time_to_eat, philo);
	}
	release_forks(philo);
}
