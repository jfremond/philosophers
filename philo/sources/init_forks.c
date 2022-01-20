/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:13:52 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 09:12:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_infos *infos)
{
	int	i;

	i = -1;
	infos->ptr_philo = ft_calloc(sizeof(t_philo), infos->nb_philos);
	if (!infos->ptr_philo)
		return (free_error(infos));
	infos->forks = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * infos->nb_philos);
	if (!infos->forks)
		return (free_error(infos));
	while (++i < infos->nb_philos)
	{
		if (pthread_mutex_init(&infos->forks[i], NULL))
			return (free_error(infos));
	}
	i = -1;
	while (++i < infos->nb_philos)
	{
		infos->ptr_philo[i].left_fork = &infos->forks[i];
		if (i == infos->nb_philos - 1)
			infos->ptr_philo[i].right_fork = &infos->forks[0];
		else
			infos->ptr_philo[i].right_fork = &infos->forks[i + 1];
	}
	return (0);
}
