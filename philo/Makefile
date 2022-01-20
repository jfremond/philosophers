# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:09:19 by jfremond          #+#    #+#              #
#    Updated: 2022/01/19 17:19:40 by jfremond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
#   EXECUTABLE   #
##################

NAME	=	philo

################
#   COMMANDS   #
################

CC		=	clang
LINK	=	clang
RM		=	/bin/rm -rf
MKDIR	=	/bin/mkdir -p

#############
#   FLAGS   #
#############

CFLAGS	=	-c -Wall -Wextra -Werror
CFLAGS	+=	-I $(HEAD_D)
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-pthread

LDFLAGS	=	-pthread

#############
#   DEBUG   #
#############

ifeq ($(DEBUG), 1)
	CFLAGS	+=	-fsanitize=thread
	LDFLAGS +=	-fsanitize=thread
endif

ifeq ($(DEBUG), 2)
	CFLAGS +=	-g3
endif

ifeq ($(DEBUG), 3)
	CFLAGS	+=	-g3 -fsanitize=address -fsanitize=undefined
	LDFLAGS +=	-g3 -fsanitize=address -fsanitize=undefined
endif

###################
#   DIRECTORIES   #
###################

HEAD_D	=	headers/
SRCS_D	=	sources/
UTILS_D	=	utils/
OBJS_D	=	objs/

###############
#   SOURCES   #
###############

SRCS_N	=	check_arg_digit.c			\
			check_arg_int.c				\
			check_arg_sign.c			\
			check_arg_validity.c		\
			death_watcher.c				\
			eat.c						\
			free_error.c				\
			init_and_destroy_mutex.c	\
			init_forks.c				\
			init_values.c				\
			main.c						\
			philo_routine.c				\
			print_messages.c			\
			time.c						\

UTILS_N	=	ft_atoll.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isdigit.c	\

###############
#   OBJECTS   #
###############

O_SRC	=	$(SRCS_N:.c=.o)
O_SRC	:=	$(addprefix $(OBJS_D), $(O_SRC))

O_UTILS	=	$(UTILS_N:.c=.o)
O_UTILS	:=	$(addprefix $(OBJS_D), $(O_UTILS))

OBJS	=	$(O_SRC) $(O_UTILS)

####################
#   DEPENDENCIES   #
####################

DEP_N	=	$(OBJS:.o=.d)

#############
#   RULES   #
#############

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LINK) $(OBJS) $(LDFLAGS) $(OUTPUT_OPTION)

-include		$(DEP_N)

$(OBJS_D)%.o:	$(SRCS_D)%.c
				$(MKDIR) $(OBJS_D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

$(OBJS_D)%.o:	$(UTILS_D)%.c
				$(MKDIR) $(OBJS_D)
				$(CC) $(CFLAGS) $(OUTPUT_OPTION) $<

ARG	= 200 510 200 200

jean-valgrind:	
				valgrind  --tool=helgrind ./$(NAME) $(ARG)
				valgrind  --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARG)
norm:			
				norminette $(HEAD_D) $(UTILS_D) $(SRCS_D)

clean:
				$(RM) $(OBJS_D)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
