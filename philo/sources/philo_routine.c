/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:51:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 18:00:56 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dispatch_philos(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ptr_infos->nb_philos == 1)
		one_philo_routine(philo);
	else
		routine(philo);
	return (NULL);
}

void	one_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, FORK);
	standing_action(philo->ptr_infos, philo->ptr_infos->time_to_die);
	pthread_mutex_unlock(philo->right_fork);
	printf("%ld %d died\n", get_time(philo->ptr_infos), philo->id);
}

void	routine(t_philo *philo)
{
	while (!is_dead(philo) && !has_eaten_enough(philo))
	{
		philo_eat(philo);
		if (!is_dead(philo) && !has_eaten_enough(philo))
			print_state(philo, SLEEP);
		if (!is_dead(philo) && !has_eaten_enough(philo))
			standing_action(philo->ptr_infos, philo->ptr_infos->time_to_sleep);
		if (!is_dead(philo) && !has_eaten_enough(philo))
			print_state(philo, THINK);
	}
}
