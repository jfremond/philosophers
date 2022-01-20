/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:24:58 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 16:03:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
