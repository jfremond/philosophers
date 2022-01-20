/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:46:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/01/19 15:48:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* Error messages */
# define ERR_ARG_NUM "Error : Not the right amount of args\n"
# define ERR_ARG_VAL "Error : Can't have over 200 philos or time under 60ms\n"
# define ERR_ARG_DIGIT "Error : Args must be digits only\n"
# define ERR_ARG_INT "Error : Args must be ints\n"
# define ERR_ARG_SIGN "Error : Args must be positive\n"

/* State messages */
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

#endif