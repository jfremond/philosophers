/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:42:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 16:31:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_time(t_infos *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (free_error(time));
	time->start_time_sec = tv.tv_sec;
	time->start_time_usec = tv.tv_usec;
	time->start_time = time->start_time_usec * 1000
		+ time->start_time_usec / 1000;
	return (0);
}

long	get_time(t_infos *time)
{
	struct timeval	tv;
	long			current_time;

	if (gettimeofday(&tv, NULL) != 0)
		return (free_error(time));
	current_time = (tv.tv_sec - time->start_time_sec) * 1000
		+ (tv.tv_usec - time->start_time_usec) / 1000;
	return (current_time);
}

int	standing_action(t_infos *infos, int time_to_reach)
{
	long	time;
	long	start_time;

	time = get_time(infos);
	start_time = get_time(infos);
	while (time < time_to_reach + start_time)
	{
		if (usleep(200) == -1)
			return (free_error(infos));
		time = get_time(infos);
	}
	return (0);
}
