/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:29:01 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/17 12:44:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	free_error(t_infos *infos)
{
	if (infos->ptr_philo)
		free(infos->ptr_philo);
	if (infos->forks)
		free(infos->forks);
	return (1);
}
