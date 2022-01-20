/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:21:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/12 18:46:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg_int(char *arg)
{
	int	len;

	len = 0;
	while (arg[len])
		++len;
	if (len > 11)
		return (1);
	if (len == 11 && ft_atoll(arg) < INT_MIN)
		return (1);
	if (len == 10 && ft_atoll(arg) > INT_MAX)
		return (1);
	return (0);
}
