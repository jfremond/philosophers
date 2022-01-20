/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:06:10 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 11:47:58 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_values(t_infos *init, char **argv)
{
	init->died = 0;
	init->nb_philos = ft_atoll(argv[1]);
	init->time_to_die = ft_atoll(argv[2]);
	init->time_to_eat = ft_atoll(argv[3]);
	init->time_to_sleep = ft_atoll(argv[4]);
	if (argv[5])
		init->meals = ft_atoll(argv[5]);
	else
		init->meals = -1;
	if (init->nb_philos > 200 || init->time_to_die < 60
		|| init->time_to_eat < 60 || init->time_to_sleep < 60)
	{
		print_error(ERR_ARG_VAL);
		return (1);
	}
	return (0);
}
