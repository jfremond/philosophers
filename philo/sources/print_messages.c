/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:49:25 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 17:25:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_error(char *error_message)
{
	printf("%s", error_message);
	return (1);
}

void	print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(&philo->ptr_infos->print_state);
	if (!is_dead(philo))
		printf("%ld %d %s\n", get_time(philo->ptr_infos), philo->id, state);
	pthread_mutex_unlock(&philo->ptr_infos->print_state);
}
