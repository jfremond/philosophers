/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:24:45 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 18:57:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	clean_exit(t_infos *infos)
{
	int	i;

	i = 0;
	while (i < infos->nb_philos)
	{
		if (pthread_join(infos->ptr_philo[i].tid, NULL))
			return (1);
		++i;
	}
	mutex_destroy(infos);
	free(infos->forks);
	free(infos->ptr_philo);
	return (0);
}

int	create_thread(t_infos *infos, int i)
{
	pthread_mutex_unlock(&infos->thread_create);
	infos->ptr_philo[i].id = i + 1;
	infos->ptr_philo[i].nb_meal = 0;
	infos->ptr_philo[i].ptr_infos = infos;
	pthread_mutex_lock(&infos->thread_create);
	if (pthread_create(&infos->ptr_philo[i].tid, NULL,
			&dispatch_philos, &infos->ptr_philo[i]))
		return (free_error(infos));
	if (usleep(40) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_infos		infos;

	if (check_arg_validity(argc, argv) || init_values(&infos, argv)
		|| init_forks(&infos) || mutex_init(&infos) || init_time(&infos))
		return (1);
	i = 0;
	while (i < infos.nb_philos)
	{
		pthread_mutex_lock(&infos.thread_create);
		if (create_thread(&infos, i))
			return (1);
		i += 2;
		if (i >= infos.nb_philos && i % 2 == 0)
			i = 1;
		pthread_mutex_unlock(&infos.thread_create);
	}
	while (!is_dead(infos.ptr_philo) && !has_eaten_enough(infos.ptr_philo)
		&& infos.nb_philos > 1)
		death_watcher(&infos);
	clean_exit(&infos);
	return (0);
}
