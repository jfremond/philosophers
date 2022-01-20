/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_destroy_mutex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:56:23 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 16:03:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	mutex_init(t_infos *mutex)
{
	if (pthread_mutex_init(&mutex->has_died, NULL))
		return (free_error(mutex));
	if (pthread_mutex_init(&mutex->enough_meals, NULL))
		return (free_error(mutex));
	if (pthread_mutex_init(&mutex->print_state, NULL))
		return (free_error(mutex));
	if (pthread_mutex_init(&mutex->thread_create, NULL))
		return (free_error(mutex));
	return (0);
}

int	mutex_destroy(t_infos *mutex)
{
	if (pthread_mutex_destroy(&mutex->has_died))
		return (free_error(mutex));
	if (pthread_mutex_destroy(&mutex->enough_meals))
		return (free_error(mutex));
	if (pthread_mutex_destroy(&mutex->print_state))
		return (free_error(mutex));
	if (pthread_mutex_destroy(&mutex->thread_create))
		return (free_error(mutex));
	return (0);
}
