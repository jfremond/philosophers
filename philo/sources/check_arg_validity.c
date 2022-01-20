/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:16:23 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/12 19:00:12 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg_validity(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc < 5 || argc > 6)
		return (print_error(ERR_ARG_NUM));
	while (argv[index])
	{
		if (check_arg_digit(argv[index]) == 1)
			return (print_error(ERR_ARG_DIGIT));
		if (check_arg_int(argv[index]) == 1)
			return (print_error(ERR_ARG_INT));
		if (check_arg_sign(argv[index]) == 1)
			return (print_error(ERR_ARG_SIGN));
		++index;
	}
	return (0);
}
